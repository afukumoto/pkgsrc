# $NetBSD: Makefile,v 1.32 2024/11/14 22:20:00 wiz Exp $

R_PKGNAME=	rgdal
R_PKGVER=	1.6-7
PKGREVISION=	12
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bindings for the 'Geospatial' Data Abstraction Library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# + file LICENSE.note

# Packages suggested but not available: 'RSQLite', 'mapview'

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-DBI-[0-9]*:../../math/R-DBI
TEST_DEPENDS+=	R-maptools-[0-9]*:../../geography/R-maptools
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-rgeos-[0-9]*:../../geography/R-rgeos

USE_TOOLS+=	pkg-config

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
