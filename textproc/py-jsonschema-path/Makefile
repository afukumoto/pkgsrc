# $NetBSD: Makefile,v 1.3 2024/07/03 08:38:15 adam Exp $

DISTNAME=	jsonschema_path-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonschema-path/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p1c2u/jsonschema-path
COMMENT=	JSONSchema Spec with object-oriented paths
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-pathable>=0.4.1:../../devel/py-pathable
DEPENDS+=	${PYPKGPREFIX}-referencing>=0.28.0:../../textproc/py-referencing
DEPENDS+=	${PYPKGPREFIX}-requests>=2.31.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
