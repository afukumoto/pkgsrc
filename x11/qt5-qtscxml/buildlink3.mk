# $NetBSD: buildlink3.mk,v 1.23 2024/11/19 22:46:12 adam Exp $

BUILDLINK_TREE+=	qt5-qtscxml

.if !defined(QT5_QTSCXML_BUILDLINK3_MK)
QT5_QTSCXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtscxml+=	qt5-qtscxml>=5.13.2
BUILDLINK_ABI_DEPENDS.qt5-qtscxml?=	qt5-qtscxml>=5.15.16
BUILDLINK_PKGSRCDIR.qt5-qtscxml?=	../../x11/qt5-qtscxml

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTSCXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtscxml
