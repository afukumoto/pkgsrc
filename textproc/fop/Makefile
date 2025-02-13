# $NetBSD: Makefile,v 1.39 2024/06/27 13:44:26 ktnb Exp $
#
# Note: we currently use the pre-built (-bin) distribution of FOP,
#

DISTNAME=	fop-${VERSION}-bin
PKGNAME=	fop-${VERSION}
VERSION=	2.9
CATEGORIES=	textproc www
MASTER_SITES=	${MASTER_SITE_APACHE:=xmlgraphics/fop/binaries/}

MAINTAINER=	ftigeot@users.sourceforge.net
HOMEPAGE=	https://xmlgraphics.apache.org/fop/
COMMENT=	Print formatter driven by XSL Formatting Objects (XSL-FO)
LICENSE=	apache-2.0

USE_JAVA=		run
USE_JAVA2=		yes
USE_TOOLS+=		pax
NO_CONFIGURE=		yes
NO_BUILD=		yes
INSTALLATION_DIRS=	bin share/java/fop

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

PLIST_SRC=	${PKGDIR}/PLIST

SUBST_CLASSES+=			java_home
SUBST_STAGE.java_home=		pre-install
SUBST_MESSAGE.java_home=	Setting JAVA_HOME to a sane value.
SUBST_FILES.java_home=		fop/fop
SUBST_FILES.java_home+=		fop-ttfreader.sh
SUBST_VARS.java_home=		PKG_JAVA_HOME PREFIX SH

.include "options.mk"

fop-ttfreader:
	${CP} ${FILESDIR}/fop-ttfreader.sh \
		${WRKSRC}/fop-ttfreader.sh

do-install:
	cd ${WRKSRC}/fop && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/java/fop
	${LN} -sf ../share/java/fop/fop ${DESTDIR}${PREFIX}/bin
	${RM} -f ${DESTDIR}${PREFIX}/share/java/fop/fop.orig
	${RM} -f ${DESTDIR}${PREFIX}/share/java/fop/fop-ttfreader.sh
	${INSTALL_SCRIPT} ${WRKSRC}/fop-ttfreader.sh \
		${DESTDIR}${PREFIX}/bin/fop-ttfreader

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
