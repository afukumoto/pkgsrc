# $NetBSD: Makefile,v 1.69 2024/12/23 23:22:04 mef Exp $

PKGNAME=	openrct2-0.4.17
CATEGORIES=	games

DIST_SUBDIR=	openrct2-${PKGVERSION_NOREV}

DISTFILES=	openrct.tar.gz
DISTFILES+=	title-sequences.zip
DISTFILES+=	objects.zip
DISTFILES+=	opensound.zip
DISTFILES+=	openmusic.zip
DISTFILES+=	replays.zip

EXTRACT_ONLY+=	openrct.tar.gz

TITLE_SEQUENCE_VERSION=	0.4.14
OBJECTS_VERSION=	1.4.11
OPENSFX_VERSION=	1.0.5
OPENMSX_VERSION=	1.6
REPLAYS_VERSION=	0.0.84

SITES.openrct.tar.gz= \
	-https://github.com/OpenRCT2/OpenRCT2/archive/refs/tags/v${PKGVERSION_NOREV}.tar.gz

# these versions come from CMakeLists.txt

SITES.title-sequences.zip= \
	https://github.com/OpenRCT2/title-sequences/releases/download/v${TITLE_SEQUENCE_VERSION}/

SITES.objects.zip= \
	https://github.com/OpenRCT2/objects/releases/download/v${OBJECTS_VERSION}/

SITES.opensound.zip= \
	https://github.com/OpenRCT2/OpenSoundEffects/releases/download/v${OPENSFX_VERSION}/

SITES.openmusic.zip= \
	https://github.com/OpenRCT2/OpenMusic/releases/download/v${OPENMSX_VERSION}/

SITES.replays.zip= \
	https://github.com/OpenRCT2/replays/releases/download/v${REPLAYS_VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenRCT2/OpenRCT2/
COMMENT=	Open source reimplementation of RollerCoaster Tycoon 2
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/OpenRCT2-${PKGVERSION_NOREV}

USE_TOOLS+=	gmake pkg-config unzip
USE_LANGUAGES=	c c++

#    upstream
#    https://github.com/OpenRCT2/OpenRCT2/wiki/Building-OpenRCT2-on-Linux
#    Says GCC>=12. or clang >=8.0. (C++20 support required)
GCC_REQD+=	12
#    But this line should be removed after 2024 Q4 branch
#    And below is the right thing (if gcc.mk works correctly)
USE_CXX_FEATURES+=	c++20
#    See the thread:
#    https://mail-index.netbsd.org/pkgsrc-users/2024/12/20/msg040707.html

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_COMPILER_AR="/usr/bin/ar"
CMAKE_CONFIGURE_ARGS+=	-DDISABLE_DISCORD_RPC=ON
CMAKE_CONFIGURE_ARGS+=	-DDISABLE_GOOGLE_BENCHMARK=ON
CMAKE_CONFIGURE_ARGS+=	-DMACOS_USE_DEPENDENCIES=OFF
CMAKE_CONFIGURE_ARGS+=	-DMACOS_BUNDLE=OFF

CMAKE_CONFIGURE_ARGS+=	-DDOWNLOAD_TITLE_SEQUENCES=OFF
CMAKE_CONFIGURE_ARGS+=	-DDOWNLOAD_OBJECTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DDOWNLOAD_OPENSFX=OFF
CMAKE_CONFIGURE_ARGS+=	-DDOWNLOAD_OPENMSX=OFF

CXXFLAGS+=	-DORCT2_RESOURCE_DIR=\"${PREFIX}/share/openrct2\"


CHECK_WRKREF_SKIP+=	share/*

BUILDLINK_TRANSFORM+=	rm:-Werror

SUBST_CLASSES+=		doc
SUBST_STAGE.doc=	pre-configure
SUBST_MESSAGE.doc=	Fixing documentation path.
SUBST_FILES.doc=	src/openrct2/platform/Platform.macOS.mm
SUBST_VARS.doc=		PREFIX

post-extract:
	unzip -d ${WRKSRC}/data/object ${DISTDIR}/${DIST_SUBDIR}/objects.zip
	unzip -d ${WRKSRC}/data/sequence ${DISTDIR}/${DIST_SUBDIR}/title-sequences.zip
	unzip -d ${WRKSRC}/data ${DISTDIR}/${DIST_SUBDIR}/opensound.zip
	unzip -d ${WRKSRC}/data ${DISTDIR}/${DIST_SUBDIR}/openmusic.zip
	unzip -d ${WRKSRC}/test/tests/testdata/replays \
		${DISTDIR}/${DIST_SUBDIR}/replays.zip

.include "../../devel/cmake/build.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/libduktape/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
