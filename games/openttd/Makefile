# $NetBSD: Makefile,v 1.130 2024/11/14 22:19:57 wiz Exp $

DISTNAME=	openttd-14.1-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	https://proxy.binaries.openttd.org/openttd-releases/${PKGVERSION_NOREV}/
MASTER_SITES+=	https://cdn.openttd.org/openttd-releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openttd.org/
COMMENT=	Open source clone of Transport Tycoon Deluxe
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

USE_CXX_FEATURES+=	c++20 charconv

BUILD_DEFS+=	VARBASE

# Uses alloca, cannot use standard C++ on NetBSD
FORCE_CXX_STD=		gnu++20

.include "../../mk/bsd.prefs.mk"

CMAKE_CONFIGURE_ARGS+=	-DPERSONAL_DIR=.openttd
CMAKE_CONFIGURE_ARGS+=	-DSHARED_DIR=${VARBASE}/games/openttd
CMAKE_CONFIGURE_ARGS+=	-DGLOBAL_DIR=${PREFIX}/share/openttd
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_BINDIR=bin
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_DATADIR=share
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Allegro=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Grfcodec=ON
CMAKE_CONFIGURE_ARGS+=	-DOPTION_INSTALL_FHS=ON

PLIST_VARS=	unix
.if ${OPSYS} != "Darwin"
PLIST.unix=	yes
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif

.include "../../archivers/lzo/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
