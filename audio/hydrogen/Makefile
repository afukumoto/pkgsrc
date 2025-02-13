# $NetBSD: Makefile,v 1.101 2024/11/14 22:18:42 wiz Exp $

DISTNAME=	hydrogen-1.0.2
PKGREVISION=	29
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hydrogen-music/}
GITHUB_PROJECT=	Hydrogen
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://hydrogen-music.org/
COMMENT=	Real time drum machine/sequencer
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/.rc/-rc/}

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DWANT_LRDF=ON

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
CMAKE_CONFIGURE_ARGS+=	-DWANT_OSS=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_OSS=OFF
.endif

CMAKE_CONFIGURE_ARGS+=	-DWANT_CPPUNIT=OFF

LDFLAGS.SunOS+=	-lsocket -lnsl

USE_CXX_FEATURES+=	c++14

# It rejectes the genreated .pc file for NetBSD libarchive.
PREFER.libarchive=	pkgsrc

.include "options.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/liblrdf/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
