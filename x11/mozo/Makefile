# $NetBSD: Makefile,v 1.41 2024/12/27 08:21:02 wiz Exp $

PYTHON_VERSIONS_INCOMPATIBLE=	27
PKGREVISION= 11
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mozo-${VERSION:R}.2
CATEGORIES=	x11

COMMENT=	Menu editor for MATE

PY_PATCHPLIST=	yes

.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/mate-menus/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
