# $NetBSD: buildlink3.mk,v 1.8 2024/11/14 22:19:35 wiz Exp $

BUILDLINK_TREE+=	qt6-qtwayland

.if !defined(QT6_QTWAYLAND_BUILDLINK3_MK)
QT6_QTWAYLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtwayland+=	qt6-qtwayland>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtwayland+=	qt6-qtwayland>=6.8.0nb3
BUILDLINK_PKGSRCDIR.qt6-qtwayland?=	../../devel/qt6-qtwayland

BUILDLINK_LIBDIRS.qt6-qtwayland+=	qt6/plugins/platforms
BUILDLINK_LIBDIRS.qt6-qtwayland+=	qt6/plugins/wayland-decoration-client
BUILDLINK_LIBDIRS.qt6-qtwayland+=	qt6/plugins/wayland-graphics-integration-client
BUILDLINK_LIBDIRS.qt6-qtwayland+=	qt6/plugins/wayland-graphics-integration-server
BUILDLINK_LIBDIRS.qt6-qtwayland+=	qt6/plugins/wayland-shell-integration

.include "../../devel/wayland/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTWAYLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtwayland
