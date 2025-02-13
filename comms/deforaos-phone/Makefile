# $NetBSD: Makefile,v 1.55 2024/12/27 08:19:28 wiz Exp $

DISTNAME=	Phone-0.6.0
PKGNAME=	deforaos-phone-0.6.0
PKGREVISION=	17
CATEGORIES=	comms net
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Phone/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop telephony

LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/gprs.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/gprs.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/phone.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/phone.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/phonectl.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/phonectl.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/gprs.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gprs.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/phone.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/phone.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/phonectl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/phonectl.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.if ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
