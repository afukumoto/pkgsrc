# $NetBSD: Makefile,v 1.5 2024/12/27 08:19:48 wiz Exp $

DISTNAME=	libgnome-games-support-2.0.0
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnome-games-support/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/libgnome-games-support/
COMMENT=	Small library intended for internal use by GNOME Games (v2)
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/libgnome-games-support-2.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../devel/meson/build.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
