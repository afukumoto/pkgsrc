# $NetBSD: Makefile,v 1.20 2025/01/06 21:49:17 ktnb Exp $
#

DISTNAME=	qonk-0.3.1
PKGREVISION=	14
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qonk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qonk.sourceforge.net/
COMMENT=	Small space build-and-conquer strategy game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin share/doc share/qonk

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/qonk.txt

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
