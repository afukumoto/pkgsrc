# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:20:11 wiz Exp $

BUILDLINK_TREE+=	kf6-kplotting

.if !defined(KF6_KPLOTTING_BUILDLINK3_MK)
KF6_KPLOTTING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kplotting+=	kf6-kplotting>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kplotting?=	kf6-kplotting>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-kplotting?=	../../graphics/kf6-kplotting

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KPLOTTING_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kplotting
