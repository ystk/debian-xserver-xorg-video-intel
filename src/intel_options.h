#ifndef INTEL_OPTIONS_H
#define INTEL_OPTIONS_H

/*
 * Note: "ColorKey" is provided for compatibility with the i810 driver.
 * However, the correct option name is "VideoKey".  "ColorKey" usually
 * refers to the tranparency key for 8+24 overlays, not for video overlays.
 */

enum intel_options {
	OPTION_ACCEL_METHOD,
	OPTION_DRI,
	OPTION_VIDEO_KEY,
	OPTION_COLOR_KEY,
	OPTION_TILING_FB,
	OPTION_TILING_2D,
	OPTION_SHADOW,
	OPTION_SWAPBUFFERS_WAIT,
	OPTION_TRIPLE_BUFFER,
#ifdef INTEL_XVMC
	OPTION_XVMC,
#endif
	OPTION_PREFER_OVERLAY,
	OPTION_DEBUG_FLUSH_BATCHES,
	OPTION_DEBUG_FLUSH_CACHES,
	OPTION_DEBUG_WAIT,
	OPTION_HOTPLUG,
	OPTION_RELAXED_FENCING,
	OPTION_USE_SNA,
#ifdef USE_SNA
	OPTION_THROTTLE,
	OPTION_VMAP,
	OPTION_ZAPHOD,
	OPTION_DELAYED_FLUSH,
#endif
#ifdef USE_UXA
	OPTION_FALLBACKDEBUG,
	OPTION_BUFFER_CACHE,
#endif
	NUM_OPTIONS,
};

static OptionInfoRec intel_options[] = {
	{OPTION_ACCEL_METHOD,	"AccelMethod",	OPTV_STRING,	{0},	0},
	{OPTION_DRI,		"DRI",		OPTV_BOOLEAN,	{0},	TRUE},
	{OPTION_COLOR_KEY,	"ColorKey",	OPTV_INTEGER,	{0},	FALSE},
	{OPTION_VIDEO_KEY,	"VideoKey",	OPTV_INTEGER,	{0},	FALSE},
	{OPTION_TILING_2D,	"Tiling",	OPTV_BOOLEAN,	{0},	TRUE},
	{OPTION_TILING_FB,	"LinearFramebuffer",	OPTV_BOOLEAN,	{0},	FALSE},
	{OPTION_SHADOW,	"Shadow",	OPTV_BOOLEAN,	{0},	FALSE},
	{OPTION_SWAPBUFFERS_WAIT, "SwapbuffersWait", OPTV_BOOLEAN,	{0},	TRUE},
	{OPTION_TRIPLE_BUFFER, "TripleBuffer", OPTV_BOOLEAN,	{0},	TRUE},
#ifdef INTEL_XVMC
	{OPTION_XVMC,	"XvMC",		OPTV_BOOLEAN,	{0},	TRUE},
#endif
	{OPTION_PREFER_OVERLAY, "XvPreferOverlay", OPTV_BOOLEAN, {0}, FALSE},
	{OPTION_DEBUG_FLUSH_BATCHES, "DebugFlushBatches", OPTV_BOOLEAN, {0}, FALSE},
	{OPTION_DEBUG_FLUSH_CACHES, "DebugFlushCaches", OPTV_BOOLEAN, {0}, FALSE},
	{OPTION_DEBUG_WAIT, "DebugWait", OPTV_BOOLEAN, {0}, FALSE},
	{OPTION_HOTPLUG,	"HotPlug",	OPTV_BOOLEAN,	{0},	TRUE},
	{OPTION_RELAXED_FENCING,	"RelaxedFencing",	OPTV_BOOLEAN,	{0},	TRUE},
#ifdef USE_SNA
	{OPTION_THROTTLE,	"Throttle",	OPTV_BOOLEAN,	{0},	TRUE},
	{OPTION_VMAP,	"UseVmap",	OPTV_BOOLEAN,	{0},	TRUE},
	{OPTION_ZAPHOD,	"ZaphodHeads",	OPTV_STRING,	{0},	FALSE},
	{OPTION_DELAYED_FLUSH,	"DelayedFlush",	OPTV_BOOLEAN,	{0},	TRUE},
#endif
#ifdef USE_UXA
	{OPTION_FALLBACKDEBUG, "FallbackDebug", OPTV_BOOLEAN, {0},	FALSE},
	{OPTION_BUFFER_CACHE,       "BufferCache",  OPTV_BOOLEAN,   {0},    TRUE},
#endif
	{-1,			NULL,		OPTV_NONE,	{0},	FALSE}
};

#endif /* INTEL_OPTIONS_H */
