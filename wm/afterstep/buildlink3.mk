# $NetBSD: buildlink3.mk,v 1.24 2024/12/27 08:20:45 wiz Exp $

BUILDLINK_TREE+=	afterstep

.if !defined(AFTERSTEP_BUILDLINK3_MK)
AFTERSTEP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.afterstep+=	afterstep>=2.2.11
BUILDLINK_ABI_DEPENDS.afterstep?=	afterstep>=2.2.12nb11
BUILDLINK_PKGSRCDIR.afterstep?=		../../wm/afterstep
BUILDLINK_DEPMETHOD.afterstep?=		build

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
#.include "../../x11/libXt/buildlink3.mk"

.endif	# AFTERSTEP_BUILDLINK3_MK

BUILDLINK_TREE+=	-afterstep
