# $NetBSD: Makefile,v 1.37 2025/01/06 21:49:09 ktnb Exp $

DISTNAME=		bomberclone-0.11.9
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bomberclone/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.bomberclone.de/
COMMENT=		Multi-player Bomberman clone

LICENSE=		gnu-gpl-v2

CONFLICTS=		bomberclone-data-[0-9]*

BUILDLINK_TRANSFORM+=	rm:-Werror
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

LDFLAGS.DragonFly=	-lm

post-install:
	${RM} -fr ${DESTDIR}${PREFIX}/share/bomberclone/*/CVS
	${RM} -fr ${DESTDIR}${PREFIX}/share/bomberclone/*/*/CVS
	${RM} -fr ${DESTDIR}${PREFIX}/share/bomberclone/*/*/*/CVS

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
