# $NetBSD: Makefile,v 1.97 2024/12/27 08:20:21 wiz Exp $

DISTNAME=	mousetweaks-3.32.0
PKGREVISION=	15
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/mousetweaks/3.32/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Mousetweaks
COMMENT=	Mouse accessibility software
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config gmake
USE_TOOLS+=	msgfmt msgmerge xgettext

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
