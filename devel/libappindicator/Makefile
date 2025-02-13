# $NetBSD: Makefile,v 1.44 2024/12/27 08:19:34 wiz Exp $

DISTNAME=	libappindicator-12.10.0
PKGREVISION=	27
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/libappindicator/12.10/12.10.0/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/libappindicator/
COMMENT=	Allow applications to export a menu into the panel
LICENSE=	gnu-lgpl-v3 AND gnu-lgpl-v2.1

CONFLICTS+=	libappindicator3-[0-9]*
SUPERSEDES+=	libappindicator3-[0-9]*

EXTRACT_USING=	gtar
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	bindings/mono/appindicator-sharp-0.1.pc.in
PKGCONFIG_OVERRIDE+=	src/appindicator3-0.1.pc.in
PKGCONFIG_OVERRIDE+=	src/appindicator-0.1.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

CONFIGURE_ARGS+=	--with-gtk=3

.include "../../devel/libindicator/buildlink3.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
