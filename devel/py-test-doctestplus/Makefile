# $NetBSD: Makefile,v 1.9 2024/11/11 07:28:25 wiz Exp $

DISTNAME=	pytest-doctestplus-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-doctestplus/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://astropy.org/
COMMENT=	Pytest plugin with advanced doctest features
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-packaging>=17.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=30.3.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-test>=4.6:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-remotedata>=0.3.2:../../net/py-test-remotedata

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
