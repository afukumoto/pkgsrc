# $NetBSD: Makefile,v 1.4 2024/05/06 08:40:24 jperkin Exp $

DISTNAME=	hexcurse-1.60.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=LonnyGomes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LonnyGomes/hexcurse/
COMMENT=	Hexcurse is an ncurses-based console hexeditor written in C
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
