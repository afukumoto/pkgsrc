# $NetBSD: Makefile,v 1.82 2024/11/11 07:27:58 wiz Exp $

DISTNAME=	sqlalchemy-2.0.36
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLAlchemy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sqlalchemy.org/
COMMENT=	Python SQL toolkit and Object Relational Mapper
LICENSE=	mit

WHEEL_NAME=	SQLAlchemy-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.24:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.18:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
