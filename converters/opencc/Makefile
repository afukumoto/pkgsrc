# $NetBSD: Makefile,v 1.9 2024/06/19 11:01:18 jperkin Exp $

VERSION=	1.1.3
GITHUB_PROJECT=	OpenCC
GITHUB_TAG=	ver.${VERSION}
DISTNAME=	OpenCC-ver.${VERSION}
PKGNAME=	${DISTNAME:S/OpenCC-ver./opencc-/}
PKGREVISION=	1
CATEGORIES=	converters chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=BYVoid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencc.byvoid.com/
COMMENT=	Convertion between Traditional and Simplified Chinese
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME} # GitHub rule is not relevant for this.

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++14

PKGCONFIG_OVERRIDE+=	opencc.pc.in

USE_GCC_RUNTIME=	yes

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/src
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/src

TEST_TARGET=	test

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../lang/python/pyversion.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
