# $NetBSD: Makefile,v 1.40 2024/11/04 16:06:12 nia Exp $
#

DISTNAME=	aide-0.15.1
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aide/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://aide.sourceforge.net/
COMMENT=	Free intrusion detection system for checking file integrity
LICENSE=	artistic

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex gmake

CHECK_PORTABILITY_SKIP=	contrib/gpg2_update.sh # not needed

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && empty(OS_VERSION:M5.[6-9])
# Since Solaris 10, static linking no longer possible
CONFIGURE_ARGS+=	--disable-static
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
