# $NetBSD: buildlink3.mk,v 1.40 2024/11/14 22:20:44 wiz Exp $

BUILDLINK_TREE+=	Addresses

.if !defined(ADDRESSES_BUILDLINK3_MK)
ADDRESSES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Addresses+=	Addresses>=0.4.8
BUILDLINK_ABI_DEPENDS.Addresses+=	Addresses>=0.4.8nb29
BUILDLINK_PKGSRCDIR.Addresses?=		../../misc/Addresses

.include "../../devel/gnustep-make/gnustep.mk"

BUILDLINK_INCDIRS.Addresses+=	lib/GNUstep/Frameworks/Addresses.framework/Headers
BUILDLINK_INCDIRS.Addresses+=	lib/GNUstep/Frameworks/AddresView.framework/Headers
BUILDLINK_FILES.Addresses+=	include/AddressBook/*.h
BUILDLINK_FILES.Addresses+=	include/Addresses/*.h
BUILDLINK_FILES.Addresses+=	include/AddressView/*.h

.include "../../x11/gnustep-back/buildlink3.mk"
.endif # ADDRESSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-Addresses
