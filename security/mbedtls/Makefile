# $NetBSD: Makefile,v 1.30 2024/08/25 06:19:12 wiz Exp $

DISTNAME=	mbedtls-2.28.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=ARMmbed/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://tls.mbed.org/
COMMENT=	Lightweight, modular cryptographic and SSL/TLS library (2.x branch)
LICENSE=	apache-2.0 OR gnu-gpl-v2

CONFLICTS+=	mbedtls3-[0-9]*
CONFLICTS+=	polarssl-[0-9]*
SUPERSEDES+=	polarssl-[0-9]*

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99

USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-Wno-dev
CMAKE_CONFIGURE_ARGS+=	-DUSE_SHARED_MBEDTLS_LIBRARY=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PROGRAMS=ON

# Fails to build full suite on NetBSD due to strange tricks with stdout
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TESTING=OFF

CMAKE_CONFIGURE_ARGS+=	-DMBEDTLS_FATAL_WARNINGS=OFF

MAKE_ENV+=	RANLIB=${RANLIB:Q}

LDFLAGS.SunOS+=	-lsocket

# python is required only for tests and they are disabled above
#PYTHON_FOR_BUILD_ONLY=	tool

#PYTHON_VERSIONS_INCOMPATIBLE=	27

PKGCONFIG_OVERRIDE+=	pkgconfig/mbedcrypto.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/mbedtls.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/mbedx509.pc.in

# Prefix bundled programs so they don't conflict with other packages
post-install:
	cd ${DESTDIR}${PREFIX}/bin && for f in *; do \
		${MV} "$$f" "mbedtls_$$f"; \
	done

#do-test:
#	LD_LIBRARY_PATH=${WRKSRC}/library \
#	    ${WRKSRC}/programs/test/selftest

.include "options.mk"
.include "../../devel/cmake/build.mk"
#.include "../../lang/python/tool.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
