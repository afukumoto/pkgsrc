# $NetBSD: Makefile,v 1.10 2024/12/20 22:03:01 pin Exp $

DISTNAME=	marswm-0.6.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=jzbor/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/jzbor/marswm/
COMMENT=	Modern window manager featuring dynamic tiling
LICENSE=	mit

# Marswm does not build on 32bit systems.
# Support for building on 32bit is not planed, see:
# https://github.com/jzbor/marswm/issues/14
ONLY_FOR_PLATFORM=	${LP64PLATFORMS}

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/mars-relay \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/marsbar \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/marswm \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD" || ${X11_TYPE} == "modular"
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
.endif

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
