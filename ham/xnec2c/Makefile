# $NetBSD: Makefile,v 1.42 2024/12/27 08:20:07 wiz Exp $

DISTNAME=	xnec2c-4.2.3
PKGREVISION=	5
CATEGORIES=	ham
MASTER_SITES=	https://www.qsl.net/5b4az/pkg/nec2/xnec2c/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qsl.net/5b4az/pages/nec2.html
COMMENT=	GTK+ graphical interactive version of nec2c
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		intltool msgfmt pax pkg-config

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--export-dynamic

INSTALLATION_DIRS=	share/doc/xnec2c

# Following line may not be correct, but without this, libinotify.so has problem
#/tmp/ham/xnec2c/work/xnec2c-4.2.1/src/optimize.c:124: undefined reference to `inotify_init1'
#ld: /tmp/ham/xnec2c/work/xnec2c-4.2.1/src/optimize.c:132: undefined reference to `inotify_add_watch'
CFLAGS+=		-linotify -L${PREFIX}/lib

USE_CC_FEATURES+=	c17

post-install:
	cd ${WRKSRC}/doc && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/share/doc/xnec2c

.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
