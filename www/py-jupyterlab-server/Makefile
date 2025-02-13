# $NetBSD: Makefile,v 1.8 2024/10/14 06:46:07 wiz Exp $

DISTNAME=	jupyterlab_server-2.27.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterlab_server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyterlab-server.readthedocs.io/
COMMENT=	Server components for JupyterLab and JupyterLab like applications
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.7:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-babel>=2.10:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-json5>=0.9.0:../../textproc/py-json5
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.18.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=1.21:../../www/py-jupyter_server
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-requests>=2.31:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml-[0-9]*:../../devel/py-ruamel-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-console-scripts-[0-9]*:../../devel/py-test-console-scripts
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-jupyter>=0.6.2:../../www/py-test-jupyter
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
# TODO: strict_rfc3339

USE_LANGUAGES=		# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.8.3:../../devel/py-importlib-metadata
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
