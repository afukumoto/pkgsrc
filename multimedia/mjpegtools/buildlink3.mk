# $NetBSD: buildlink3.mk,v 1.26 2025/01/06 21:49:23 ktnb Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	mjpegtools

.if !defined(MJPEGTOOLS_BUILDLINK3_MK)
MJPEGTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mjpegtools+=	mjpegtools>=1.8.0
BUILDLINK_ABI_DEPENDS.mjpegtools+=	mjpegtools>=2.1.0nb2
BUILDLINK_PKGSRCDIR.mjpegtools?=	../../multimedia/mjpegtools

.include "../../audio/lame/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"

pkgbase := mjpegtools
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.mjpegtools:Mdv)
.  include "../../multimedia/libdv/buildlink3.mk"
.endif
.endif # MJPEGTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mjpegtools
