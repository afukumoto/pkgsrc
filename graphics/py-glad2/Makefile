# $NetBSD: Makefile,v 1.6 2024/11/11 07:28:35 wiz Exp $

DISTNAME=	glad2-2.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/glad2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Dav1dde/glad
COMMENT=	Multi-Language GL/GLES/EGL/GLX/WGL Loader-Generator
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jinja2>=0:../../textproc/py-jinja2

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/glad ${DESTDIR}${PREFIX}/bin/glad${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
