# $NetBSD: Makefile,v 1.15 2024/12/27 08:19:51 wiz Exp $
#

VERSION=	2.2.12
PKGREVISION=	13
DISTNAME=	ocpn_plots_pi-${VERSION}
PKGNAME=	opencpn-plugin-plots-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=rgleason/}
GITHUB_PROJECT=	plots_pi
GITHUB_TAG=	v${VERSION}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://opencpn.org/OpenCPN/plugins/sweepplot.html
COMMENT=	visualizes sailing performance data
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes

CMAKE_CONFIGURE_ARGS+=	-DPREFIX:PATH=${PREFIX} -DPREFIX_PLUGINS:PATH=${PREFIX}/lib/opencpn
CMAKE_MODULE_PATH_OVERRIDE = \
		cmake/PluginConfigure.cmake \
		cmake/PluginInstall.cmake \
		cmake/PluginLocalization.cmake \
		cmake/PluginPackage.cmake

.include "../../devel/cmake/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
