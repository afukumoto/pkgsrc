# $NetBSD: Makefile,v 1.26 2025/01/06 21:49:04 ktnb Exp $
#

DISTNAME=	biew-${BIEWVER:S/.//g}-src
PKGNAME=	biew-${BIEWVER}
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=beye/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://beye.sourceforge.net/en/beye.html
COMMENT=	Binary viewer/editor
LICENSE=	gnu-gpl-v2

BIEWVER=	6.1.0

WRKSRC=		${WRKDIR}/biew-${BIEWVER:S/.//g}

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	makefile

CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-no-integrated-as
.endif

LIBS.SunOS+=	-lrt
MAKE_ENV+=	OS_LIBS=${LIBS:Q}

.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
