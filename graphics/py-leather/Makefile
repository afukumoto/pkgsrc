# $NetBSD: Makefile,v 1.7 2024/11/11 07:28:35 wiz Exp $

DISTNAME=	leather-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/leather/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://leather.readthedocs.io/
COMMENT=	Python charting for 80% of humans
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.9.1:../../textproc/py-cssselect
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml>=3.6.0:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
