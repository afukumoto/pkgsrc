# $NetBSD: Makefile,v 1.34 2024/10/14 07:13:40 wiz Exp $

DISTNAME=	buildbot-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://buildbot.net/
COMMENT=	Continuous integration system
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-JWT-[0-9]*:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.16.0:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.1.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-migrate>=0.9:../../databases/py-sqlalchemy-migrate
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.9.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-txaio>=2.2.2:../../devel/py-txaio
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=4.1.1:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-boto3-[0-9]*:../../net/py-boto3
TEST_DEPENDS+=	${PYPKGPREFIX}-jade-[0-9]*:../../textproc/py-jade
TEST_DEPENDS+=	${PYPKGPREFIX}-lz4-[0-9]*:../../archivers/py-lz4
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-moto-[0-9]*:../../net/py-moto
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized
TEST_DEPENDS+=	${PYPKGPREFIX}-treq-[0-9]*:../../devel/py-treq
TEST_DEPENDS+=	${PYPKGPREFIX}-txrequests-[0-9]*:../../devel/py-txrequests

PYTHON_VERSIONS_INCOMPATIBLE=	313 # py-Tempita

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} buildbot buildbot-${PYVERSSUFFIX} && \
	${MV} buildbot_windows_service buildbot_windows_service-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
