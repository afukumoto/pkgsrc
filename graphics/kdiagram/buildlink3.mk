# $NetBSD: buildlink3.mk,v 1.8 2024/11/14 22:20:10 wiz Exp $

BUILDLINK_TREE+=	kdiagram

.if !defined(KDIAGRAM_BUILDLINK3_MK)
KDIAGRAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdiagram+=	kdiagram>=2.8.0
BUILDLINK_ABI_DEPENDS.kdiagram?=		kdiagram>=2.8.0nb9
BUILDLINK_PKGSRCDIR.kdiagram?=		../../graphics/kdiagram

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.endif	# KDIAGRAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdiagram
