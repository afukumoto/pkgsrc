# $NetBSD: Makefile,v 1.11 2024/11/11 07:27:59 wiz Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	ailment-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ailment/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/angr/ailment
COMMENT=	The angr intermediate language
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
# Circular dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-angr-[0-9]*:../../devel/py-angr
TEST_DEPENDS+=	${PYPKGPREFIX}-archinfo-[0-9]*:../../devel/py-archinfo
TEST_DEPENDS+=	${PYPKGPREFIX}-pyvex-[0-9]*:../../devel/py-pyvex

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
