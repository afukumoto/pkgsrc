# $NetBSD: Makefile,v 1.9 2024/09/06 18:48:41 bsiegert Exp $

DISTNAME=	sptui-0.1.2
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=szktkfm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/szktkfm/sptui/
COMMENT=	Spotify TUI player
LICENSE=	mit

# sptui is not really a Spotify client but, more of a client controller.
# It needs a client like 'librespot' or, 'spotifyd' running in the backgroud.

INSTALLATION_DIRS=	bin
USE_TOOLS+=		itstool gdbus-codegen perl

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/sptui \
		${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
