# $NetBSD: Makefile,v 1.9 2024/12/12 10:54:47 wiz Exp $

DISTNAME=	git-filter-repo-2.47.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=newren/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/newren/git-filter-repo/
COMMENT=	Tool for rewriting git history
LICENSE=	mit

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
NO_BUILD=	yes

REPLACE_PYTHON+=	git-filter-repo

INSTALLATION_DIRS+=	libexec/git-core ${PKGMANDIR}/man1

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
