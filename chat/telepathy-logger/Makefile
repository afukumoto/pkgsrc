# $NetBSD: Makefile,v 1.71 2024/11/14 22:18:53 wiz Exp $

DISTNAME=	telepathy-logger-0.2.7
PKGREVISION=	43
CATEGORIES=	chat
MASTER_SITES=	https://telepathy.freedesktop.org/releases/telepathy-logger/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://telepathy.freedesktop.org/wiki/Logger
COMMENT=	Logger module for telepathy
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake gsed intltool msgfmt

CFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

PKGCONFIG_OVERRIDE+=	extensions/tpl-extensions.pc.in
PKGCONFIG_OVERRIDE+=	telepathy-logger/telepathy-logger-0.1.pc.in

PYTHON_FOR_BUILD_ONLY=		yes
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.2.7

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
