# $NetBSD: buildlink3.mk,v 1.28 2024/11/19 22:46:10 adam Exp $

BUILDLINK_TREE+=	qt5-qtcharts

.if !defined(QT5_QTCHARTS_BUILDLINK3_MK)
QT5_QTCHARTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtcharts+=	qt5-qtcharts>=5.11.2
BUILDLINK_ABI_DEPENDS.qt5-qtcharts+=	qt5-qtcharts>=5.15.16
BUILDLINK_PKGSRCDIR.qt5-qtcharts?=	../../x11/qt5-qtcharts

BUILDLINK_INCDIRS.qt5-qtcharts+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtcharts+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtcharts+=	qt5/plugins

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTCHARTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtcharts
