# $NetBSD: Makefile,v 1.8 2024/12/14 10:57:39 jperkin Exp $

R_PKGNAME=	lifecycle
R_PKGVER=	1.0.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manage the Life Cycle of your Package Functions
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-glue>=1.3.1:../../devel/R-glue
DEPENDS+=	R-rlang>=1.1.0:../../devel/R-rlang
DEPENDS+=	R-cli>=3.4.0:../../devel/R-cli

# Package suggested but not available: 'tidyverse'
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-crayon-[0-9]*:../../devel/R-crayon
TEST_DEPENDS+=	R-lintr-[0-9]*:../../devel/R-lintr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-tidyverse-[0-9]*:../../devel/R-tidyverse
TEST_DEPENDS+=	R-vctrs-[0-9]*:../../math/R-vctrs

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
