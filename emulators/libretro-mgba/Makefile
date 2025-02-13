# $NetBSD: Makefile,v 1.17 2024/08/25 06:18:41 wiz Exp $

.include "${.CURDIR}/../../emulators/mgba/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

HOMEPAGE=	https://docs.libretro.com/library/mgba/
COMMENT=	Libretro core based on the mGBA emulator

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

CMAKE_CONFIGURE_ARGS+=	-DUSE_DEBUGGERS=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_GDB_STUB=OFF

CMAKE_CONFIGURE_ARGS+=	-DUSE_EDITLINE=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_FFMPEG=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_ZLIB=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_MINIZIP=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_PNG=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_LIBZIP=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_SQLITE3=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_LZMA=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_EPOXY=OFF

CMAKE_CONFIGURE_ARGS+=	-DBUILD_QT=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SDL=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_GL=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_GLES2=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_GLES3=OFF

CMAKE_CONFIGURE_ARGS+=	-DBUILD_LIBRETRO=ON
CMAKE_CONFIGURE_ARGS+=	-DSKIP_LIBRARY=ON
CMAKE_CONFIGURE_ARGS+=	-DLIBRETRO_LIBDIR=${PREFIX}/lib/libretro

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

# Avoid conflicting with emulators/mgba.
post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/doc/mGBA
	${RM} -rf ${DESTDIR}${PREFIX}/include/mgba*

.include "../../devel/libelf/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
