# $NetBSD: Makefile,v 1.88 2024/12/27 08:20:04 wiz Exp $
#

DISTNAME=	xzgv-0.9.1
PKGREVISION=	39
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xzgv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/xzgv
COMMENT=	Image viewer
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake makeinfo pkg-config gawk
INFO_FILES=		yes
INSTALLATION_DIRS=	bin ${PKGINFODIR} ${PKGMANDIR}/man1
LDFLAGS+=		-lm -lX11	# explicitly list for ld v2.22

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	@(cd ${WRKSRC}/doc && ${MAKEINFO} xzgv.texi)
	cd ${WRKSRC}/doc; for f in xzgv.info; do			\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
