# $NetBSD: Makefile,v 1.12 2024/11/11 07:28:06 wiz Exp $

DISTNAME=	doc8-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/doc8/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pycqa/doc8
COMMENT=	Opinionated style checker for rst styles of documentation
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.19:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-restructuredtext_lint>=0.7:../../devel/py-restructuredtext_lint
DEPENDS+=	${PYPKGPREFIX}-stevedore-[0-9]*:../../devel/py-stevedore

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} doc8 doc8-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
