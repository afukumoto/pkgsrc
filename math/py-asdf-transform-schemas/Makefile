# $NetBSD: Makefile,v 1.7 2024/11/11 07:28:39 wiz Exp $

DISTNAME=	asdf_transform_schemas-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf-transform-schemas/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/asdf-format/asdf-transform-schemas
COMMENT=	ASDF schemas for transforms
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-asdf-standard>=1.1.0:../../math/py-asdf-standard
TEST_DEPENDS+=	${PYPKGPREFIX}-asdf>=2.8.0:../../math/py-asdf
TEST_DEPENDS+=	${PYPKGPREFIX}-asdf_astropy>=0:../../math/py-asdf_astropy
TEST_DEPENDS+=	${PYPKGPREFIX}-scipy>=0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
