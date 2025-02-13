# $NetBSD: Makefile,v 1.45 2024/11/14 22:20:33 wiz Exp $

DISTNAME=	zig-0.13.0
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/download/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ziglang.org/
COMMENT=	Programming language designed for robustness and clarity
LICENSE=	mit

# Fails to build in chroot on netbsd: https://github.com/ziglang/zig/issues/19756
USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:run

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DZIG_SHARED_LLVM=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${DESTDIR}${PREFIX}
# avoid full-cu-features available to build host,
# in other words ensure that we run everywhere
CMAKE_CONFIGURE_ARGS+=	-DZIG_TARGET_MCPU=baseline
#CMAKE_CONFIGURE_ARGS+=	-DZIG_PIE=ON

MAKE_ENV+=	ZIG_GLOBAL_CACHE_DIR=${WRKDIR}/zig-global-cache
MAKE_ENV+=	ZIG_LOCAL_CACHE_DIR=${WRKDIR}/zig-local-cache

CHECK_PORTABILITY_SKIP+=	ci/azure/macos_script
BUILDLINK_TRANSFORM+=		rm:-Werror

UNLIMIT_RESOURCES=	stacksize

# again, sigh...
RELRO_SUPPORTED=	no
MKPIE_SUPPORTED=	no
# TODO: /usr/bin/env + /bin/env in lib/std/zig/system.zig

# after install, because the zig binary ends up in paths like
# ./zig-0.10.1/zig-cache/o/e6445b80597d6bc8fe865e7254800ac9/zig
# unless we want to run find for the executable here?
do-test:
	mkdir ${WRKDIR}/cache
	cd ${WRKSRC} && \
		${DESTDIR}${PREFIX}/bin/zig build test-behavior \
		--cache-dir ${WRKDIR}/cache --global-cache-dir ${WRKDIR}/cache \
		--zig-lib-dir ${WRKSRC}/lib

.include "../../devel/cmake/build.mk"
.include "../../devel/lld/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
