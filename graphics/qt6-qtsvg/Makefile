# $NetBSD: Makefile,v 1.19 2024/12/26 22:20:18 adam Exp $

DISTNAME=	qtsvg-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtsvg-${QTVERSION}
COMMENT=	Qt6 module for SVG
CATEGORIES=	graphics
LICENSE=	gnu-lgpl-v2.1 OR gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Svg.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6SvgWidgets.pc

.include "../../x11/qt6-qtbase/Makefile.common"

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
