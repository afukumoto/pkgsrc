# $NetBSD: Makefile,v 1.13 2024/10/14 06:46:07 wiz Exp $

DISTNAME=	jupyter_server-2.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter-server.readthedocs.io/
COMMENT=	Backend for Jupyter web applications
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-jupyter-builder>=0.8.1:../../devel/py-hatch-jupyter-builder
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.11:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-Send2Trash>=1.8.2:../../sysutils/py-Send2Trash
DEPENDS+=	${PYPKGPREFIX}-anyio>=3.1.0:../../devel/py-anyio
DEPENDS+=	${PYPKGPREFIX}-argon2-cffi-[0-9]*:../../security/py-argon2-cffi
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=7.4.4:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.12:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyter_events>=0.9.0:../../devel/py-jupyter_events
DEPENDS+=	${PYPKGPREFIX}-jupyter_server_terminals>=0.4.4:../../comms/py-jupyter_server_terminals
DEPENDS+=	${PYPKGPREFIX}-nbconvert>=6.4.4:../../www/py-nbconvert
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.3.0:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-overrides>=5.0:../../devel/py-overrides
DEPENDS+=	${PYPKGPREFIX}-packaging>=22.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>=0.9:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-terminado>=0.8.3:../../www/py-terminado
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.6.0:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=1.7:../../www/py-websocket-client
DEPENDS+=	${PYPKGPREFIX}-zmq>=24:../../net/py-zmq
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-console-scripts-[0-9]*:../../devel/py-test-console-scripts
TEST_DEPENDS+=	${PYPKGPREFIX}-test-jupyter>=0.4:../../www/py-test-jupyter
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

USE_PKGLOCALEDIR=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-server jupyter-server-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
