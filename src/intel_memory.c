/**************************************************************************

Copyright 1998-1999 Precision Insight, Inc., Cedar Park, Texas.
Copyright © 2002 by David Dawes.

All Rights Reserved.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sub license, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice (including the
next paragraph) shall be included in all copies or substantial portions
of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
IN NO EVENT SHALL THE COPYRIGHT HOLDERS AND/OR THEIR SUPPLIERS BE LIABLE FOR
ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

**************************************************************************/

/*
 * Authors:
 *   Keith Whitwell <keith@tungstengraphics.com>
 *   David Dawes <dawes@xfree86.org>
 *
 * Updated for Dual Head capabilities:
 *   Alan Hourihane <alanh@tungstengraphics.com>
 */

/**
 * @file intel_memory.c
 *
 * This is the video memory allocator.  Our memory allocation is different from
 * other graphics chips, where you have a fixed amount of graphics memory
 * available that you want to put to the best use.  Instead, we have almost no
 * memory pre-allocated, and we have to choose an appropriate amount of sytem
 * memory to use.
 *
 * The allocations we might do:
 *
 * - Ring buffer
 * - HW cursor block (either one block or four)
 * - Overlay registers
 * - Front buffer (screen 1)
 * - Front buffer (screen 2, only in zaphod mode)
 * - Back/depth buffer (3D only)
 * - Compatibility texture pool (optional, more is always better)
 * - New texture pool (optional, more is always better.  aperture allocation
 *     only)
 *
 * The user may request a specific amount of memory to be used
 * (intel->pEnt->videoRam != 0), in which case allocations have to fit within
 * that much aperture.  If not, the individual allocations will be
 * automatically sized, and will be fit within the maximum aperture size.
 * Only the actual memory used (not alignment padding) will get actual AGP
 * memory allocated.
 *
 * Given that the allocations listed are generally a page or more than a page,
 * our allocator will only return page-aligned offsets, simplifying the memory
 * binding process.  For smaller allocations, the acceleration architecture's
 * linear allocator is preferred.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ioctl.h>

#include "xf86.h"
#include "xf86_OSproc.h"

#include "intel.h"
#include "i915_drm.h"

/**
 * Returns the fence size for a tiled area of the given size.
 */
unsigned long intel_get_fence_size(intel_screen_private *intel, unsigned long size)
{
	unsigned long i;
	unsigned long start;

	if (IS_I965G(intel)) {
		/* The 965 can have fences at any page boundary. */
		return ALIGN(size, GTT_PAGE_SIZE);
	} else {
		/* Align the size to a power of two greater than the smallest fence
		 * size.
		 */
		if (IS_I9XX(intel))
			start = MB(1);
		else
			start = KB(512);

		for (i = start; i < size; i <<= 1) ;

		return i;
	}
}

/**
 * On some chips, pitch width has to be a power of two tile width, so
 * calculate that here.
 */
unsigned long
intel_get_fence_pitch(intel_screen_private *intel, unsigned long pitch,
		     uint32_t tiling_mode)
{
	unsigned long i;
	unsigned long tile_width = (tiling_mode == I915_TILING_Y) ? 128 : 512;

	if (tiling_mode == I915_TILING_NONE)
		return pitch;

	/* 965 is flexible */
	if (IS_I965G(intel))
		return ALIGN(pitch, tile_width);

	/* Pre-965 needs power of two tile width */
	for (i = tile_width; i < pitch; i <<= 1) ;

	return i;
}

static Bool
intel_check_display_stride(ScrnInfoPtr scrn, int stride, Bool tiling)
{
	intel_screen_private *intel = intel_get_screen_private(scrn);
	int limit = KB(32);

	/* 8xx spec has always 8K limit, but tests show larger limit in
	   non-tiling mode, which makes large monitor work. */
	if (IS_I8XX(intel) && tiling)
		limit = KB(8);

	if (IS_I915(intel) && tiling)
		limit = KB(8);

	if (IS_I965G(intel) && tiling)
		limit = KB(16);

	if (IS_IGDNG(intel) && tiling)
		limit = KB(32);

	if (stride <= limit)
		return TRUE;
	else
		return FALSE;
}

/*
 * Pad to accelerator requirement
 */
static inline int intel_pad_drawable_width(int width)
{
	return ALIGN(width, 64);
}

/**
 * Allocates a framebuffer for a screen.
 *
 * Used once for each X screen, so once with RandR 1.2 and twice with classic
 * dualhead.
 */
drm_intel_bo *intel_allocate_framebuffer(ScrnInfoPtr scrn,
					int width, int height, int cpp,
					unsigned long *out_pitch,
					uint32_t *out_tiling)
{
	intel_screen_private *intel = intel_get_screen_private(scrn);
	drm_intel_bo *front_buffer;
	uint32_t tiling_mode;
	unsigned long pitch;

	if (intel->tiling)
		tiling_mode = I915_TILING_X;
	else
		tiling_mode = I915_TILING_NONE;

	width = intel_pad_drawable_width(width);
	if (!intel_check_display_stride(scrn, width * intel->cpp,
					tiling_mode != I915_TILING_NONE))
	    tiling_mode = I915_TILING_NONE;
	if (!intel_check_display_stride(scrn, width * intel->cpp,
					tiling_mode != I915_TILING_NONE)) {
		xf86DrvMsg(scrn->scrnIndex, X_ERROR,
			   "Expected front buffer stride %d kB "
			   "will exceed display limit\n",
			   width * intel->cpp / 1024);
		return NULL;
	}

retry:
	front_buffer = drm_intel_bo_alloc_tiled(intel->bufmgr, "front buffer",
						width, height, intel->cpp,
						&tiling_mode, &pitch, 0);
	if (front_buffer == NULL) {
		if (tiling_mode != I915_TILING_NONE) {
			tiling_mode = I915_TILING_NONE;
			goto retry;
		}
		xf86DrvMsg(scrn->scrnIndex, X_ERROR,
			   "Failed to allocate framebuffer.\n");
		return NULL;
	}

	if (!intel_check_display_stride(scrn, pitch,
				       tiling_mode != I915_TILING_NONE)) {
		drm_intel_bo_unreference(front_buffer);
		if (tiling_mode != I915_TILING_NONE) {
			tiling_mode = I915_TILING_NONE;
			goto retry;
		}

		xf86DrvMsg(scrn->scrnIndex, X_ERROR,
			   "Front buffer stride %ld kB "
			   "exceeds display limit\n", pitch / 1024);
		return NULL;
	}

	if (intel->tiling && tiling_mode != I915_TILING_X) {
		xf86DrvMsg(scrn->scrnIndex, X_ERROR,
			   "Failed to set tiling on frontbuffer.\n");
	}

	xf86DrvMsg(scrn->scrnIndex, X_INFO,
		   "Allocated new frame buffer %dx%d stride %ld, %s\n",
		   width, height, pitch,
		   tiling_mode == I915_TILING_NONE ? "untiled" : "tiled");

	drm_intel_bo_disable_reuse(front_buffer);

	intel_set_gem_max_sizes(scrn);
	*out_pitch = pitch;
	*out_tiling = tiling_mode;

	return front_buffer;
}

static void intel_set_max_bo_size(intel_screen_private *intel,
				 const struct drm_i915_gem_get_aperture *aperture)
{
	if (aperture->aper_available_size)
		/* Large BOs will tend to hit SW fallbacks frequently, and also will
		 * tend to fail to successfully map when doing SW fallbacks because we
		 * overcommit address space for BO access, or worse cause aperture
		 * thrashing.
		 */
		intel->max_bo_size = aperture->aper_available_size / 2;
	else
		intel->max_bo_size = 64 * 1024 * 1024;
}

static void intel_set_max_gtt_map_size(intel_screen_private *intel,
				      const struct drm_i915_gem_get_aperture *aperture)
{
	if (aperture->aper_available_size)
		/* Let objects up get bound up to the size where only 2 would fit in
		 * the aperture, but then leave slop to account for alignment like
		 * libdrm does.
		 */
		intel->max_gtt_map_size =
			aperture->aper_available_size * 3 / 4 / 2;
	else
		intel->max_gtt_map_size = 16 * 1024 * 1024;
}

static void intel_set_max_tiling_size(intel_screen_private *intel,
				     const struct drm_i915_gem_get_aperture *aperture)
{
	if (aperture->aper_available_size)
		/* Let objects be tiled up to the size where only 4 would fit in
		 * the aperture, presuming worst case alignment.
		 */
		intel->max_tiling_size = aperture->aper_available_size / 4;
	else
		intel->max_tiling_size = 4 * 1024 * 1024;
}

void intel_set_gem_max_sizes(ScrnInfoPtr scrn)
{
	intel_screen_private *intel = intel_get_screen_private(scrn);
	struct drm_i915_gem_get_aperture aperture;

	aperture.aper_available_size = 0;
	ioctl(intel->drmSubFD, DRM_IOCTL_I915_GEM_GET_APERTURE, &aperture);

	intel_set_max_bo_size(intel, &aperture);
	intel_set_max_gtt_map_size(intel, &aperture);
	intel_set_max_tiling_size(intel, &aperture);
}
