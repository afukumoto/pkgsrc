# $NetBSD: Makefile,v 1.44 2024/09/06 18:48:47 bsiegert Exp $

GITHUB_TAG=	01cf781a
DISTNAME=	reftools-0.0.20201119
PKGREVISION=	43
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=davidrjenni/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/davidrjenni/reftools/
COMMENT=	Go refactoring tools
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/reftools-01cf781abd5bfec662427327f5e38d1bd02e4e11

GO_BUILD_PATTERN=	./cmd/...

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
