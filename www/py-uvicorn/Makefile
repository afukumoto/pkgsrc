# $NetBSD: Makefile,v 1.48 2024/12/31 09:56:42 adam Exp $

DISTNAME=	uvicorn-0.34.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uvicorn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.uvicorn.org/
COMMENT=	The lightning-fast ASGI server
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-h11>=0.8:../../www/py-h11
# standard
DEPENDS+=	${PYPKGPREFIX}-dotenv>=0.13:../../devel/py-dotenv
DEPENDS+=	${PYPKGPREFIX}-httptools>=0.6.3:../../www/py-httptools
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.15.2:../../devel/py-uvloop
DEPENDS+=	${PYPKGPREFIX}-watchfiles>=0.13:../../misc/py-watchfiles
DEPENDS+=	${PYPKGPREFIX}-websockets>=10.4:../../www/py-websockets
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27.2:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14.0:../../devel/py-test-mock

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0:../../devel/py-typing-extensions
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} uvicorn uvicorn-${PYVERSSUFFIX} || ${TRUE}

# Needs a2wsgi
pre-test:
	${RM} ${WRKSRC}/tests/middleware/test_wsgi.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
