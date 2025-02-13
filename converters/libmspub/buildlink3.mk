# $NetBSD: buildlink3.mk,v 1.26 2024/12/29 15:09:41 adam Exp $

BUILDLINK_TREE+=	libmspub

.if !defined(LIBMSPUB_BUILDLINK3_MK)
LIBMSPUB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmspub+=	libmspub>=0.0.6
BUILDLINK_ABI_DEPENDS.libmspub+=	libmspub>=0.1.4nb33
BUILDLINK_PKGSRCDIR.libmspub?=		../../converters/libmspub

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../textproc/icu/buildlink3.mk"
.endif	# LIBMSPUB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmspub
