# $NetBSD: buildlink3.mk,v 1.25 2024/11/14 22:20:58 wiz Exp $

BUILDLINK_TREE+=	libassetml

.if !defined(LIBASSETML_BUILDLINK3_MK)
LIBASSETML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libassetml+=	libassetml>=1.2.1
BUILDLINK_ABI_DEPENDS.libassetml+=	libassetml>=1.2.1nb20
BUILDLINK_PKGSRCDIR.libassetml?=	../../multimedia/libassetml

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBASSETML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libassetml
