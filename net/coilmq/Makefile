# $NetBSD: Makefile,v 1.24 2024/10/14 06:45:54 wiz Exp $

DISTNAME=	CoilMQ-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	4
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CoilMQ/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/hozn/coilmq
COMMENT=	Simple, lightweight, and easily extensible STOMP message broker
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-daemon-[0-9]*:../../devel/py-daemon
DEPENDS+=	${PYPKGPREFIX}-pid-[0-9]*:../../sysutils/py-pid
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

USE_PKG_RESOURCES=	yes

REPLACE_PYTHON+=	coilmq/start.py

PKG_SYSCONFSUBDIR=	coilmq

SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	pre-configure
SUBST_FILES.cfg=	coilmq/config/__init__.py
SUBST_SED.cfg=		-e 's,/path/to/config.cfg,${PKG_SYSCONFDIR}/defaults.cfg,'

EGDIR=			${PREFIX}/share/examples/coilmq
INSTALLATION_DIRS+=	${EGDIR}
CONF_FILES=		${EGDIR}/defaults.cfg				\
			${PKG_SYSCONFDIR}/defaults.cfg			\
			${EGDIR}/coilmq.cfg-sample			\
			${PKG_SYSCONFDIR}/coilmq.cfg

post-install:
	${INSTALL_DATA} ${WRKSRC}/coilmq/config/defaults.cfg		\
		${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/coilmq/config/coilmq.cfg-sample	\
		${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
