# $NetBSD: Makefile,v 1.8 2024/10/18 11:51:21 mef Exp $

R_PKGNAME=	checkmate
R_PKGVER=	2.3.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast and versatile argument checks
LICENSE=	modified-bsd

DEPENDS+=	R-backports>=1.1.0:../../math/R-backports

TEST_DEPENDS+=	R-data.table-[0-9]*:../../textproc/R-data.table
TEST_DEPENDS+=	R-devtools-[0-9]*:../../devel/R-devtools
TEST_DEPENDS+=	R-fastmatch-[0-9]*:../../math/R-fastmatch
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown


USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
