# $NetBSD: Makefile,v 1.12 2024/10/13 07:30:59 wiz Exp $

DISTNAME=	xwud-1.0.7
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Display XWD X Window Dump image file

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
