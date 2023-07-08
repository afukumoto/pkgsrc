# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.darktable
PKG_OPTIONS_OPTIONAL_GROUPS=	magick
PKG_OPTIONS_GROUP.magick=	graphicsmagick imagemagick
PKG_SUPPORTED_OPTIONS=	cups gphoto2 heif jp2 libwebp lua openexr openmp sdl2
PKG_SUGGESTED_OPTIONS=	cups graphicsmagick gphoto2 heif jp2 lua openexr openmp

.include "../../mk/bsd.options.mk"

###
### cups for printing
###
PLIST_VARS+=	cups
.if !empty(PKG_OPTIONS:Mcups)
PLIST.cups=	yes
.include "../../print/cups-base/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_PRINT=OFF
.endif

###
### gphoto2 for camera tethering
###
PLIST_VARS+=	gphoto2
.if !empty(PKG_OPTIONS:Mgphoto2)
PLIST.gphoto2=	yes
BUILDLINK_API_DEPENDS.libgphoto2+=	libgphoto2>=2.5
.include "../../devel/libgphoto2/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_CAMERA_SUPPORT=OFF
.endif

###
### heif for HEIF/HEIC/HIF/AVIF import
###
.if !empty(PKG_OPTIONS:Mheif)
.include "../../graphics/libheif/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_HEIF=OFF
.endif

###
### lua for scripting
###
PLIST_VARS+=	lua
.if !empty(PKG_OPTIONS:Mlua)
PLIST.lua=	yes
.include "../../lang/lua54/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_LUA=OFF
.endif

###
### OpenEXR for EXR import and export
###
PLIST_VARS+=	openexr
.if !empty(PKG_OPTIONS:Mopenexr)
PLIST.openexr=	yes
.include "../../graphics/openexr/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_OPENEXR=OFF
.endif

###
### OpenJPEG for JPEG2000 import and export
###
PLIST_VARS+=	jp2
.if !empty(PKG_OPTIONS:Mjp2)
PLIST.jp2=	yes
.include "../../graphics/openjpeg/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_OPENJPEG=OFF
.endif

###
### OpenMP for parallel processing
###
.if !empty(PKG_OPTIONS:Mopenmp)
PKGSRC_COMPILER= clang
CMAKE_ARGS+=	-DLIBS='-lgcc -lgcc_s'
CFLAGS+= -Wno-gnu-zero-variadic-macro-arguments
#PKG_CC=		${PREFIX}/bin/clang
#PKG_CXX=	${PREFIX}/bin/clang++
BUILDLINK_DEPMETHOD.clang=     build
.include "../../lang/clang/buildlink3.mk"
.include "../../parallel/openmp/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_OPENMP=OFF
.endif

###
### SDL2 for gamepad input support
###
PLIST_VARS+=	sdl2
.if !empty(PKG_OPTIONS:Msdl2)
PLIST.sdl2=	yes
.include "../../devel/SDL2/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_SDL2=OFF
.endif

###
### libwebp for WebP import & export
###
PLIST_VARS+=	webp
.if !empty(PKG_OPTIONS:Mlibwebp)
PLIST.webp=	yes
.include "../../graphics/libwebp/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_WEBP=OFF
.endif

###
### GraphicsMagick or ImageMagick for misc image format support
###
.if !empty(PKG_OPTIONS:Mgraphicsmagick)
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_GRAPHICSMAGICK=OFF
.if !empty(PKG_OPTIONS:Mimagemagick)
CMAKE_ARGS+=	-DUSE_IMAGEMAGICK=ON
.include "../../graphics/ImageMagick/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_IMAGEMAGICK=OFF
.endif
.endif
