# $NetBSD: Makefile,v 1.73 2024/11/28 13:21:55 adam Exp $

DISTNAME=	pyopenssl-24.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyopenssl/OpenSSL/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyopenssl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyopenssl.org/
COMMENT=	Python interface to the OpenSSL library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography>=41.0.5:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend

# 506 passed, 1 skipped, 6 warnings, 3 errors
# one test failure reported at: https://github.com/pyca/pyopenssl/issues/656

WHEEL_NAME=	pyOpenSSL-${PKGVERSION_NOREV}

.include "../../lang/python/wheel.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
