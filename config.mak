CC		= cl
SBR_CFLAGS	= /Yd /Zi /FR	# create .sbr files for debugging
MS_VC2005	= /D _CRT_SECURE_NO_DEPRECATE /D _CRT_NONSTDC_NO_DEPRECATE
MS_CFLAGS	= /nologo /D WIN32 /D NDEBUG $(MS_VC2005)
CFG_CFLAGS	= $(MS_CFLAGS) 
REUSE		= ..\..\reuse\m2c
REUSE_LIB	= $(REUSE)\libreuse.lib
COMMON		= ..\..\common\m2c
COMMON_LIB	= $(COMMON)\libcommn.lib
