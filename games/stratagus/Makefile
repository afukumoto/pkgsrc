# $NetBSD: Makefile,v 1.38 2025/01/06 21:49:18 ktnb Exp $
#

DISTNAME=		stratagus-2.1-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		23
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=stratagus/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://stratagus.sourceforge.net/
COMMENT=		Real-time strategy engine

MAKE_JOBS_SAFE=		no

LUA_VERSIONS_ACCEPTED=	51

WRKSRC=			${WRKDIR}/stratagus-040702
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		X11_LDFLAGS=${X_LDFLAGS:M*:Q}

CONFIGURE_ARGS+=	--with-flac --with-mad --with-lua=${BUILDLINK_PREFIX.lua}
CPPFLAGS+=		-I${BUILDLINK_PREFIX.lua}/${LUA_INCDIR}
INSTALLATION_DIRS=	bin

OPSYSVARS+=		X_LDFLAGS
X_LDFLAGS.DragonFly=	${X11_LDFLAGS} -lX11
X_LDFLAGS.*=		${X11_LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stratagus ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/stratagus
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/stratagus/graphics
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${DESTDIR}${PREFIX}/share/doc/stratagus
	${INSTALL_DATA} ${WRKSRC}/doc/graphics/* \
		${DESTDIR}${PREFIX}/share/doc/stratagus/graphics

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
