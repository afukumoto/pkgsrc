# $NetBSD: Makefile,v 1.7 2024/06/06 14:48:31 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_Cocoa-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-Cocoa/}

COMMENT=	Wrappers for the framework Cocoa on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
