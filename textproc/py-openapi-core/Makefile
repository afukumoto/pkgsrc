# $NetBSD: Makefile,v 1.18 2024/12/10 07:55:28 wiz Exp $

DISTNAME=	openapi_core-0.19.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openapi-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-openapi/openapi-core
COMMENT=	Client-side and server-side support for the OpenAPI Specification v3
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-asgiref>=3.6.0:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-isodate-[0-9]*:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.18.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jsonschema-path>=0.3.1:../../textproc/py-jsonschema-path
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-openapi-schema-validator>=0.6.0:../../textproc/py-openapi-schema-validator
DEPENDS+=	${PYPKGPREFIX}-openapi-spec-validator>=0.7.1:../../textproc/py-openapi-spec-validator
DEPENDS+=	${PYPKGPREFIX}-parse-[0-9]*:../../textproc/py-parse
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug
TEST_DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb
TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django3
#TEST_DEPENDS+=	${PYPKGPREFIX}-falcon-[0-9]*:../../devel/py-falcon
TEST_DEPENDS+=	${PYPKGPREFIX}-fastapi-[0-9]*:../../wip/py-fastapi
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx-[0-9]*:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-starlette-[0-9]*:../../www/py-starlette
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

# as of 0.19.4 (with fastapi dependency)
# 1361 passed, 20 xfailed, 65 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
