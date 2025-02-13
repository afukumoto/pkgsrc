# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:19:26 wiz Exp $

BUILDLINK_TREE+=	kf6-kpeople

.if !defined(KF6_KPEOPLE_BUILDLINK3_MK)
KF6_KPEOPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kpeople+=	kf6-kpeople>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kpeople?=	kf6-kpeople>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-kpeople?=	../../devel/kf6-kpeople

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../misc/kf6-kcontacts/buildlink3.mk"
.include "../../x11/kf6-kitemviews/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KPEOPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kpeople
