# $NetBSD: Makefile,v 1.165 2024/12/26 23:57:20 adam Exp $

# Note that the directory is still postgis2, for historical reasons.
# It remains, due to inertia and the pain of renaming outweighing the
# benefit.  So far it looks more likely than not that postgis will not
# need to be versioned again soon.
MAJOR=		3.5
DISTNAME=	postgis-${MAJOR}.1
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases geography
MASTER_SITES=	https://download.osgeo.org/postgis/source/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://postgis.net/
COMMENT=	Spatial database capabilities for PostgreSQL

LICENSE=	gnu-gpl-v2

DEPENDS+=		postgresql${PGSQL_VERSION}-server-[0-9]*:../../databases/postgresql${PGSQL_VERSION}-server

TOOL_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

CONFLICTS=		postgis-[0-9]*

# TODO section
# 1. Fix installation use of "install -o root" from pgxs.mk, when postgresql
#    was built as root and postgis is built/installed as a non-root user.
#    https://lists.osgeo.org/pipermail/postgis-devel/2015-July/025045.html
# 2. Check 2nd make, and file bug about anything that happens.  Check xsltproc
#    in particular.

USE_GCC_RUNTIME=		yes
USE_LANGUAGES=			c c++
USE_CC_FEATURES+=		c99
USE_LIBTOOL=			yes
USE_TOOLS+=			gsed gmake lex pax perl pkg-config
GNU_CONFIGURE=			yes
CONFIGURE_ARGS+=		--enable-rpath
CONFIGURE_ARGS+=		--datadir=${PREFIX}/share/postgresql/contrib
PGSQL_VERSIONS_ACCEPTED=	17 16 15 14 13

# This isn't an option, but could be.
CONFIGURE_ARGS+=	--with-address-standardizer

BUILD_TARGET=		all docs
INSTALL_TARGET=		install docs-install

DOCDIR=			${PREFIX}/share/doc/postgis

PLIST_SUBST+=		MAJOR=${MAJOR}
PRINT_PLIST_AWK+=	{ gsub(/postgis-${MAJOR:S|/|\\/|g}/, "postgis-$${MAJOR}") }
PRINT_PLIST_AWK+=	{ gsub(/topology-${MAJOR:S|/|\\/|g}/, "topology-$${MAJOR}") }

# \todo Remove or file bugs upstream
INSTALLATION_DIRS=	${DOCDIR} ${DOCDIR}/images ${PKGMANDIR}/man1

REPLACE_PERL+=		loader/postgis.pl
REPLACE_PERL+=		utils/postgis_restore.pl.in
REPLACE_PERL+=		utils/create_spatial_ref_sys_config_dump.pl
#MAKE_ENV+=		PERL5=${PERL5:Q}

INSTALL_ENV+=		mkinstalldirs=${INSTALL_DATA_DIR:Q}

TEST_TARGET=		check
# https://trac.osgeo.org/postgis/wiki/DevWikiGettingABackTrace#Usingwithregressiontests

# TEST_DEPENDS
.include "../../devel/cunit/buildlink3.mk"

# DOC DEPENDS
CONFIGURE_ARGS+=	-with-xsldir=${PREFIX}/share/xsl/docbook
# By default xsltproc downloads DTDs.  postgis tells it not to, but
# the dependencies are not packaged.  The timing option, not needed,
# is to make the variable non-empty, to work around a
# defined/non-empty incorrect test in postgis.
MAKE_ENV+=		"XSLTPROCFLAGS=--timing"

# These are really all TOOL_DEPENDS.
# \todo Report upstream; they are not mentioned in README.postgis.
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

# address standardizer (separate for possible future option)
.include "../../devel/pcre2/buildlink3.mk"

# MISSING DEPEENDS
# "GNU gettext 0.14" for the loader
# \todo Add sfcgal >=1.3.2 https://gitlab.com/Oslandia/SFCGAL
# and CGAL >=4.1.

# OMITTED DEPENDS
# gtk 2.2.0, for GUI version of shp2pgsql

# NORMAL DEPENDS
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.geos+=	geos>=3.8
.include "../../geography/geos/buildlink3.mk"
# proj >= 6.1, but bl3 is >8 anyway
.include "../../geography/proj/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
