# $NetBSD: Makefile,v 1.62 2024/08/25 06:19:11 wiz Exp $

DISTNAME=	qpdf-11.9.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qpdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qpdf.sourceforge.io/
COMMENT=	Structural, content-preserving transformations on PDF files
LICENSE=	apache-2.0

USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:test pkg-config
PKGCONFIG_OVERRIDE+=	libqpdf.pc.in
TEST_TARGET=		test

CMAKE_CONFIGURE_ARGS+=		-DUSE_IMPLICIT_CRYPTO=OFF
CMAKE_CONFIGURE_ARGS+=		-DREQUIRE_CRYPTO_GNUTLS=OFF
CMAKE_CONFIGURE_ARGS+=		-DREQUIRE_CRYPTO_OPENSSL=ON
CMAKE_CONFIGURE_ARGS+=		-DDEFAULT_CRYPTO=openssl

.include "../../devel/cmake/build.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
