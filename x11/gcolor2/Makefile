# $NetBSD: Makefile,v 1.32 2024/12/27 08:20:53 wiz Exp $

DISTNAME=	gcolor2-0.4
PKGREVISION=	27
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gcolor2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gcolor2.sourceforge.net/
COMMENT=	Simple color selector
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl pkg-config

TOOL_DEPENDS+=	p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

SUBST_CLASSES+=		df
SUBST_STAGE.df=		post-configure
SUBST_MESSAGE.df=	Fixing icon reference in desktop file
SUBST_FILES.df=		${PKGBASE}.desktop
SUBST_SED.df=		-e 's:/usr/share:${PREFIX}/share:1'

AUTO_MKDIRS=	yes

post-extract:
	${RUN}${CP} ${FILESDIR}/${PKGBASE}.desktop ${WRKSRC}/

post-install:
	${RUN}${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
