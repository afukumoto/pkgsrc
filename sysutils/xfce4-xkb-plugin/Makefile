# $NetBSD: Makefile,v 1.84 2024/12/27 08:20:43 wiz Exp $

PKGREVISION= 18
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-xkb-plugin-0.8.3
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-xkb-plugin/0.8/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-xkb-plugin
COMMENT=	Xfce Keyboard plugin

LDFLAGS.DragonFly=	-lX11
LDFLAGS.SunOS+=		-lX11

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
