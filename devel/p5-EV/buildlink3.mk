# $NetBSD: buildlink3.mk,v 1.10 2024/11/16 12:04:09 wiz Exp $

BUILDLINK_TREE+=	p5-EV

.if !defined(P5_EV_BUILDLINK3_MK)
P5_EV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-EV+=	p5-EV>=3.9
BUILDLINK_ABI_DEPENDS.p5-EV?=	p5-EV>=4.34nb1
BUILDLINK_PKGSRCDIR.p5-EV?=	../../devel/p5-EV

.include "../../lang/perl5/buildlink3.mk"
.endif # P5_EV_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-EV
