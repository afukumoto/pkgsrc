# $NetBSD: Makefile,v 1.6 2024/11/11 07:28:23 wiz Exp $

DISTNAME=	python_snappy-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-snappy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/intake/python-snappy
COMMENT=	Python library for the snappy compression library from Google
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cramjam>=2.6.0:../../archivers/py-cramjam

USE_LANGUAGES=	c c++

.include "../../devel/snappy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
