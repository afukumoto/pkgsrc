# $NetBSD: Makefile,v 1.10 2024/09/06 18:48:56 bsiegert Exp $

DISTNAME=	Terrapin-Scanner-1.0.3
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=RUB-NDS/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://terrapin-attack.com/
COMMENT=	Scan SSH servers and clients for Terrapin vulnerability
LICENSE=	apache-2.0

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
