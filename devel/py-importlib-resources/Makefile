# $NetBSD: Makefile,v 1.31 2025/01/04 06:37:24 adam Exp $

DISTNAME=	importlib_resources-6.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/importlib_resources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://importlib-resources.readthedocs.io/
COMMENT=	Read resources from Python packages
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.test>=5.4:../../devel/py-jaraco.test
TEST_DEPENDS+=	${PYPKGPREFIX}-zipp>=3.17:../../archivers/py-zipp

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-zipp>=3.1.0:../../archivers/py-zipp
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
