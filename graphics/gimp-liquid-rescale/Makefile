# $NetBSD: Makefile,v 1.71 2025/01/06 21:49:20 ktnb Exp $

DISTNAME=		gimp-lqr-plugin-0.7.1
PKGNAME=		gimp-liquid-rescale-0.7.1
PKGREVISION=		53
CATEGORIES=		graphics
MASTER_SITES=		http://liquidrescale.wikidot.com/local--files/en:download-page-sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://liquidrescale.wikidot.com/
COMMENT=		Content-aware image resizing plugin for the GIMP
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config gmake

PTHREAD_AUTO_VARS=	yes

.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/liblqr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
