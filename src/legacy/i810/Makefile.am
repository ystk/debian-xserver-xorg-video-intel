SUBDIRS = xvmc

noinst_LTLIBRARIES = liblegacy-i810.la

AM_CFLAGS = @CWARNFLAGS@ @XORG_CFLAGS@ @DRM_CFLAGS@ @DRI_CFLAGS@ @PCIACCESS_CFLAGS@ \
	    -I$(top_srcdir)/src \
	    -I$(top_srcdir)/src/legacy \
	    $(NULL)

liblegacy_i810_la_SOURCES = \
         i810_accel.c \
         i810_common.h \
         i810_cursor.c \
         i810_dga.c \
         i810_driver.c \
         i810.h \
         i810_io.c \
         i810_memory.c \
         i810_reg.h \
         i810_ring.h \
         i810_video.c \
         i810_wmark.c

if DRI
liblegacy_i810_la_SOURCES +=\
         i810_dri.c \
         i810_dri.h \
	 $(NULL)
endif

if XVMC
liblegacy_i810_la_SOURCES += \
	i810_hwmc.c \
	$(NULL)
endif
