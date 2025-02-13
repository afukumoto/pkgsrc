# $NetBSD: Makefile,v 1.67 2024/12/27 08:19:21 wiz Exp $

DISTNAME=	libcanberra-0.30
PKGREVISION=	18
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/libcanberra/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/libcanberra/
COMMENT=	Desktop event sound library
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_lib_ltdl_lt_dladvise_init=yes

PKGCONFIG_OVERRIDE+=	libcanberra-gtk.pc.in
PKGCONFIG_OVERRIDE+=	libcanberra-gtk3.pc.in
PKGCONFIG_OVERRIDE+=	libcanberra.pc.in

# configure test is broken
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--as-needed
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--gc-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--gc-sections

REPLACE_SH=		src/libcanberra-logout-sound.sh.in

PLIST_VARS+=		oss

.include "options.mk"

.include "../../devel/libltdl/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
PLIST.oss=	yes
.endif
.include "../../mk/bsd.pkg.mk"
