# $NetBSD: Makefile,v 1.44 2024/12/27 08:20:39 wiz Exp $

PKGREVISION= 13
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-notification-daemon-${VERSION:R}.1
CATEGORIES=	sysutils

COMMENT=	Notification daemon for MATE desktop

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/mate-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
