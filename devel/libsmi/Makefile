# $NetBSD: Makefile,v 1.22 2024/08/05 08:19:59 tnn Exp $

DISTNAME=	libsmi-0.5.0
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	http://www.ibr.cs.tu-bs.de/projects/libsmi/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ibr.cs.tu-bs.de/projects/libsmi/
COMMENT=	Library to access SMI MIB information
LICENSE=	esdl-license

MIBDIR=		${PREFIX}/share/libsmi/mibs
PIBDIR=		${PREFIX}/share/libsmi/pibs

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-mibdir=${MIBDIR:Q}
CONFIGURE_ARGS+=	--with-pibdir=${PIBDIR:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CFLAGS+=	-D_GNU_SOURCE=1	# for timegm(3)

REPLACE_SH+=	tools/smicache.in
REPLACE_SH+=	tools/smistrip.in
REPLACE_SH+=	test/*.test.in

TEST_TARGET=	check

.include "options.mk"

post-extract:
	rm -f ${WRKSRC}/test/smilint-smiv2.test

.include "../../mk/bsd.pkg.mk"
