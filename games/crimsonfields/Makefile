# $NetBSD: Makefile,v 1.50 2025/01/06 21:49:10 ktnb Exp $

DISTNAME=	crimson-0.5.3
PKGNAME=	${DISTNAME:S/crimson/crimsonfields/}
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://crimson.seul.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://crimson.seul.org/
COMMENT=	Tactical war game in the tradition of Battle Isle
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

CONFIGURE_ARGS+=	--enable-bi2cf
CONFIGURE_ARGS+=	--enable-cf2bmp
CONFIGURE_ARGS+=	--enable-cfed
CONFIGURE_ARGS+=	--enable-comet

# Hangs in "../tools/mkunitset ../tools/default.usrc default.units ../gfx"
NOT_FOR_BULK_PLATFORM+=	Darwin-*-*

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
