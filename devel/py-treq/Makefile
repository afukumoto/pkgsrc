# $NetBSD: Makefile,v 1.12 2024/11/11 07:28:28 wiz Exp $

DISTNAME=	treq-24.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/treq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twisted/treq
COMMENT=	HTTP library for Twisted
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=35.0.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-hyperlink>=21.0.0:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-incremental>=21.3.0:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-twisted>=22.10.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-httpbin>=0.7.0:../../www/py-httpbin
TEST_DEPENDS+=	${PYPKGPREFIX}-werkzeug>=2.0.3:../../www/py-werkzeug

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
