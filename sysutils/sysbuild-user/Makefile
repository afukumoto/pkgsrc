# $NetBSD: Makefile,v 1.6 2024/07/25 05:41:52 wiz Exp $

DISTNAME=	sysbuild-user-1.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Runs sysbuild periodically under a dedicated user
LICENSE=	modified-bsd

DEPENDS=		sysbuild>=2.5:../../sysutils/sysbuild

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		YES

SYSBUILD_USER?=		sysbuild
SYSBUILD_GROUP?=	sysbuild
SYSBUILD_HOME?=		/home/sysbuild

PKG_GROUPS=		${SYSBUILD_GROUP}
PKG_GROUPS_VARS=	PKG_GROUPS
PKG_USERS=		${SYSBUILD_USER}:${SYSBUILD_GROUP}
PKG_USERS_VARS=		PKG_USERS

PKG_GECOS.${SYSBUILD_USER}=	Unprivileged user for NetBSD builds
PKG_HOME.${SYSBUILD_USER}=	${SYSBUILD_HOME}
PKG_SHELL.${SYSBUILD_USER}=	/bin/sh

EGDIR=		${PREFIX}/share/examples/sysbuild-user
OWN_DIRS_PERMS=	${SYSBUILD_HOME} ${SYSBUILD_USER} ${SYSBUILD_GROUP} 755
CONF_FILES=	${EGDIR}/default.conf ${SYSBUILD_HOME}/default.conf

BUILD_SUBST+=	-e 's,@PREFIX@,${PREFIX},g'
FILES_SUBST+=	EGDIR=${EGDIR}
FILES_SUBST+=	SYSBUILD_HOME=${SYSBUILD_HOME}
FILES_SUBST+=	SYSBUILD_USER=${SYSBUILD_USER}
MESSAGE_SUBST+=	SYSBUILD_HOME=${SYSBUILD_HOME}
MESSAGE_SUBST+=	SYSBUILD_USER=${SYSBUILD_USER}

INSTALLATION_DIRS=	share/examples/sysbuild-user

do-build:
.for file in crontab default.conf
	${SED} ${BUILD_SUBST} <${FILESDIR}/${file} >${WRKSRC}/${file}
.endfor

do-install:
.for file in crontab default.conf
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${EGDIR}/
.endfor

.include "../../mk/bsd.pkg.mk"
