# $NetBSD: Makefile,v 1.24 2024/11/11 07:28:36 wiz Exp $

DISTNAME=	pycha-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycha/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/lgs/pycha/
COMMENT=	Library for making charts with Python
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cairocffi-[0-9]*:../../graphics/py-cairocffi
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	#none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/chavier ${DESTDIR}${PREFIX}/bin/chavier-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
