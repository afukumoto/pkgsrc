# $NetBSD: Makefile,v 1.81 2024/04/12 19:32:56 riastradh Exp $

PKGNAME=	mencoder-${MPLAYER_VERSION}
PKGREVISION=	4

COMMENT=	Simple movie encoder for MPlayer-playable movies

USE_TOOLS+=	pkg-config

.include "../../multimedia/mplayer-share/Makefile.common"

# Fix build under Mac OS X, please see here for details:
# http://lists.mplayerhq.hu/pipermail/mplayer-dev-eng/2009-May/061515.html
LDFLAGS.Darwin+=	-framework Carbon

CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

BUILD_TARGET=	mencoder

MANCOMPRESSED_IF_MANZ=	YES
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mencoder ${DESTDIR}${PREFIX}/bin
	if [ X"${MANZ}" = X"" ]; then \
		${LN} -s -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mplayer.1 \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mencoder.1; \
	else \
		${LN} -s -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mplayer.1.gz \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mencoder.1.gz; \
	fi

.include "../../multimedia/mplayer-share/depends.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
