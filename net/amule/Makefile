# $NetBSD: Makefile,v 1.110 2024/12/27 08:20:26 wiz Exp $

DISTNAME=	aMule-2.3.3
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	16
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=amule/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tripledes@eslack.org
HOMEPAGE=	http://www.amule.org/
COMMENT=	Another Emule P2P client
LICENSE=	gnu-gpl-v2

CONFLICTS=		xmule-[0-9]*

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-wx-config=${BUILDLINK_PREFIX.wxGTK30}/bin/wx-config
CONFIGURE_ARGS+=	--with-crypto-prefix=${BUILDLINK_PREFIX.cryptopp}
CONFIGURE_ARGS+=	--with-language=all
CONFIGURE_ARGS+=	--enable-xas
TEST_TARGET=		check

CXXFLAGS+=		-Wno-undef

.include "options.mk"

REPLACE_PERL=		src/libs/ec/file_generator.pl		\
			src/utils/scripts/kadnodescreate.pl	\
			src/utils/scripts/stats.pl		\
			src/utils/scripts/mldonkey_importer.pl	\
			src/utils/xas/xas.pl

LIBS+=			-lm	# for pow(3)

UNLIMIT_RESOURCES+=	datasize

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/crypto++/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
