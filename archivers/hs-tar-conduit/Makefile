# $NetBSD: Makefile,v 1.1 2025/01/05 11:46:47 pho Exp $

DISTNAME=	tar-conduit-0.4.1
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extract and create tar files using conduit for streaming
LICENSE=	mit

SUBST_CLASSES+=		cabal
SUBST_STAGE.cabal=	pre-configure
SUBST_MESSAGE.cabal=	Removing dependency on deprecated conduit-combinators
SUBST_FILES.cabal=	tar-conduit.cabal
SUBST_SED.cabal=	-e '/conduit-combinators/d'

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
