# $NetBSD: buildlink3.mk,v 1.18 2024/05/09 01:32:57 pho Exp $

BUILDLINK_TREE+=	hs-X11-xft

.if !defined(HS_X11_XFT_BUILDLINK3_MK)
HS_X11_XFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-X11-xft+=	hs-X11-xft>=0.3.4
BUILDLINK_ABI_DEPENDS.hs-X11-xft+=	hs-X11-xft>=0.3.4nb8
BUILDLINK_PKGSRCDIR.hs-X11-xft?=	../../x11/hs-X11-xft

.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.endif	# HS_X11_XFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-X11-xft
