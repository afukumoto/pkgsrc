# $NetBSD: Makefile,v 1.4 2024/08/25 06:18:24 wiz Exp $

DISTNAME=	soxr-0.1.3-Source
PKGNAME=	lib${DISTNAME:S/-Source//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=soxr/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/p/soxr/wiki/Home/
COMMENT=	SoX Resample library
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=NO

PKGCONFIG_OVERRIDE+=	src/soxr.pc.in
PKGCONFIG_OVERRIDE+=	src/soxr-lsr.pc.in

.include "../../mk/bsd.pkg.mk"
