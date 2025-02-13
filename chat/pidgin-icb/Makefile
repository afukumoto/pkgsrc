# $NetBSD: Makefile,v 1.74 2024/12/27 08:19:27 wiz Exp $

DISTNAME=	pidgin-icb-20070505
PKGREVISION=	70
CATEGORIES=	chat
MASTER_SITES=	http://nic.com.pl/~alek/pidgin-icb/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nic.com.pl/~alek/
COMMENT=	ICB protocol plugin for the Pidgin instant messenger

USE_TOOLS+=	pkg-config

USE_LIBTOOL=	yes
NO_CONFIGURE=	yes

CFLAGS+=	`pkg-config pidgin --cflags`
LDFLAGS+=	-module -avoid-version -rpath ${PIDGIN_PLUGIN_DIR}	\
		    `pkg-config pidgin --libs`

PIDGIN_PLUGIN_DIR=	${DESTDIR}${PREFIX}/lib/purple-2
PIDGIN_PIXMAPS_DIR=	${DESTDIR}${PREFIX}/share/pixmaps/pidgin/protocols

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${COMPILE.c} -I. icb.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link ${LINK.c} -o libicb.la icb.lo

do-install:
	${INSTALL_LIB_DIR} ${PIDGIN_PLUGIN_DIR}
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB} libicb.la \
	    ${PIDGIN_PLUGIN_DIR}
	for i in 16 22 48; do cd ${WRKSRC} && \
	    ${INSTALL_DATA_DIR} ${PIDGIN_PIXMAPS_DIR}/$$i && \
	    ${INSTALL_DATA} icb_$$i.png ${PIDGIN_PIXMAPS_DIR}/$$i/icb.png; done

.include "../../chat/pidgin/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
