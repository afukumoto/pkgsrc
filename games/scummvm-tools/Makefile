# $NetBSD: Makefile,v 1.82 2024/12/29 15:09:48 adam Exp $

DISTNAME=	scummvm-tools-2.1.0
PKGREVISION=	27
CATEGORIES=	games
MASTER_SITES=	https://www.scummvm.org/frs/scummvm-tools/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	Conversion and compression tools for ScummVM
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-wx-prefix=${PREFIX}

INSTALLATION_DIRS=	bin

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
