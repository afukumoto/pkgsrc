# $NetBSD: Makefile,v 1.24 2024/07/18 12:52:23 ryoon Exp $

DISTNAME=	apache-tomcat-${TOMCAT_VERSION}
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE:=tomcat/tomcat-5/v${TOMCAT_VERSION}/bin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tomcat.apache.org/
COMMENT=	The Apache Project's Java Servlet 2.4 and JSP 2.0 server
LICENSE=	apache-2.0

TOMCAT_VERSION=	5.5.36

USE_JAVA=	run
# This needs java 1.5 or higher.
USE_JAVA2=	1.5

USE_TOOLS+=	pax

TOMCAT_LIB=	${PREFIX}/tomcat
CATALINA_DIR=	Catalina/localhost

EGDIR=		${TOMCAT_LIB}/share/examples/apache-tomcat
EGDIR2=		${EGDIR}/${CATALINA_DIR}

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFDIR.apache-tomcat=	${TOMCAT_LIB}/conf
MAKE_DIRS=	${PKG_SYSCONFDIR.apache-tomcat}/${CATALINA_DIR}

CONFLICTS+=	jakarta-tomcat55-[0-9]*
CONFLICTS+=	jakarta-tomcat-[0-9]*

RCD_SCRIPTS=	tomcat
CFILES=		server.xml web.xml tomcat-users.xml
CFILES+=	catalina.policy catalina.properties
CF2FILES=	manager.xml

CONF_FILES=	# empty
.for f in ${CFILES}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.for f in ${CF2FILES}
CONF_FILES+=	${EGDIR2}/${f} ${PKG_SYSCONFDIR}/${CATALINA_DIR}/${f}
.endfor

FILES_SUBST+=	JAVA_HOME=${PKG_JAVA_HOME:Q} TOMCAT_LIB=${TOMCAT_LIB:Q}

# If we were going to build jsvc, this would be a start
# post-extract:
# 	@(cd ${WRKSRC} && ${GZCAT} bin/jsvc.tar.gz | ${TAR} xf - )
#
# post-configure:
# 	@(cd ${WRKSRC}/jsvc-src ; ${SH} ./configure)

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

do-build:
	${MV} ${WRKSRC}/conf ${WRKDIR}

INSTALLATION_DIRS+=	${EGDIR2} ${TOMCAT_LIB}

do-install:
.for f in ${CFILES}
	${INSTALL_DATA} ${WRKDIR}/conf/${f} ${DESTDIR}${EGDIR}
.endfor
.for f in ${CF2FILES}
	${INSTALL_DATA} ${WRKDIR}/conf/${CATALINA_DIR}/${f} ${DESTDIR}${EGDIR2}
.endfor
	${RM} -rf ${WRKSRC}/temp/*
	cd ${WRKSRC} && pax -rw -pm . ${DESTDIR}${TOMCAT_LIB}

	${FIND} ${DESTDIR}${TOMCAT_LIB} -type f -name \*.bat -print | ${XARGS} ${RM} -f
	${FIND} ${DESTDIR}${TOMCAT_LIB} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${TOMCAT_LIB} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${TOMCAT_LIB} -type f -name \*.sh -print | \
		${XARGS} ${CHMOD} ${BINMODE}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
