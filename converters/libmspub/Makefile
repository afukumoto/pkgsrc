# $NetBSD: Makefile,v 1.64 2024/12/29 15:09:41 adam Exp $

DISTNAME=	libmspub-0.1.4
PKGREVISION=	33
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/libmspub/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://wiki.documentfoundation.org/DLP/Libraries/libmspub
COMMENT=	Library for importing Microsoft Publisher content
LICENSE=	mpl-1.1 OR gnu-lgpl-v2 OR gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
FORCE_CXX_STD=		c++17
CONFIGURE_ARGS+=	--without-docs

BUILDLINK_TRANSFORM+=	rm:-Werror

PKGCONFIG_OVERRIDE+=	libmspub.pc.in

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-error=unknown-pragmas -Wno-error=c++11-extensions
.endif

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
