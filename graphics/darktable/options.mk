# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.darktable
PKG_OPTIONS_OPTIONAL_GROUPS=	magick
PKG_OPTIONS_GROUP.magick=	graphicsmagick imagemagick
PKG_SUPPORTED_OPTIONS=	gphoto2 openmp sdl2 libwebp
PKG_SUGGESTED_OPTIONS=	gphoto2 graphicsmagick openmp

.include "../../mk/bsd.options.mk"

###
### gphoto2 for camera tethering
###
PLIST_VARS+=	gphoto2
.if !empty(PKG_OPTIONS:Mgphoto2)
PLIST.gphoto2=	yes
BUILDLINK_API_DEPENDS.libgphoto2+=	libgphoto2>=2.5
.include "../../devel/libgphoto2/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_CAMERA_SUPPORT=OFF
.endif

###
### OpenMP for parallel processing
###
.if !empty(PKG_OPTIONS:Mopenmp)
#PKGSRC_COMPILER= clang
##CMAKE_CONFIGURE_ARGS+=	-DLIBS='-lgcc -lgcc_s'
#CFLAGS+= -Wno-gnu-zero-variadic-macro-arguments
##PKG_CC=		${PREFIX}/bin/clang
##PKG_CXX=	${PREFIX}/bin/clang++
#BUILDLINK_DEPMETHOD.clang=     build
#.include "../../lang/clang/buildlink3.mk"
#.include "../../parallel/openmp/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_OPENMP=OFF
.endif

###
### SDL2 for gamepad input support
###
PLIST_VARS+=	sdl2
.if !empty(PKG_OPTIONS:Msdl2)
PLIST.sdl2=	yes
.include "../../devel/SDL2/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_SDL2=OFF
.endif

###
### libwebp for WebP import & export
###
PLIST_VARS+=	webp
.if !empty(PKG_OPTIONS:Mlibwebp)
PLIST.webp=	yes
.include "../../graphics/libwebp/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_WEBP=OFF
.endif

###
### GraphicsMagick or ImageMagick for misc image format support
###
.if !empty(PKG_OPTIONS:Mgraphicsmagick)
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_GRAPHICSMAGICK=OFF
.if !empty(PKG_OPTIONS:Mimagemagick)
CMAKE_CONFIGURE_ARGS+=	-DUSE_IMAGEMAGICK=ON
.include "../../graphics/ImageMagick/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_IMAGEMAGICK=OFF
.endif
.endif
