# $NetBSD: buildlink3.mk,v 1.1 2024/08/26 13:53:41 ryoon Exp $

BUILDLINK_TREE+=	mozjs128

.if !defined(MOZJS128_BUILDLINK3_MK)
MOZJS128_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mozjs128+=	mozjs128>=128.1.0
BUILDLINK_PKGSRCDIR.mozjs128?=	../../lang/mozjs128

.endif	# MOZJS128_BUILDLINK3_MK

BUILDLINK_TREE+=	-mozjs128
