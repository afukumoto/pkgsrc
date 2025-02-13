# $NetBSD: Makefile,v 1.39 2024/12/04 07:24:59 wiz Exp $

DISTNAME=	valgrind-3.20.0
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.org/pub/valgrind/
MASTER_SITES+=	https://sourceware.org/pub/valgrind/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://valgrind.org/
COMMENT=	Debugging and profiling tools
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	valgrind.pc.in
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM+=	Darwin-[0-9].*-i386 Darwin-[0-9].*-x86_64
ONLY_FOR_PLATFORM+=	Darwin-1[0-7].*-i386 Darwin-1[0-7].*-x86_64
ONLY_FOR_PLATFORM+=	FreeBSD-*-x86_64 FreeBSD-*-i386
ONLY_FOR_PLATFORM+=	Linux-*-x86_64 Linux-*-i386 Linux-*-arm* Linux-*-aarch64
ONLY_FOR_PLATFORM+=	SunOS-*-i386 SunOS-*-x86_64

USE_TOOLS+=		gmake perl:run
USE_LANGUAGES=		c c++
TEST_TARGET=		regtest
SSP_SUPPORTED=		no
REPLACE_PERL+=		callgrind/callgrind_annotate.in
REPLACE_PERL+=		callgrind/callgrind_control.in

# XXX needs investigation on a supported platform
RELRO_SUPPORTED=	no

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH:C/arm.*/arm/} == "arm"
PLIST_SUBST+=		VGCONF_ARCH_PRI=arm
.endif

.if ${MACHINE_ARCH} == "aarch64"
PLIST_SUBST+=          VGCONF_ARCH_PRI=arm64
.endif

.if ${MACHINE_ARCH} == "i386"
PLIST_SUBST+=		VGCONF_ARCH_PRI=x86
.endif

.if ${MACHINE_ARCH} == "x86_64"
PLIST_SUBST+=		VGCONF_ARCH_PRI=amd64
CONFIGURE_ARGS+=	--enable-only64bit
.endif

.include "../../mk/bsd.pkg.mk"
