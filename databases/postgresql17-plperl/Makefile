# $NetBSD: Makefile,v 1.5 2024/11/25 20:13:26 adam Exp $

PKGNAME=	${DISTNAME:S/-/17-plperl-/}
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql17-server>=${PKGVERSION_NOREV}:../../databases/postgresql17-server

.include "../../databases/postgresql17/Makefile.common"

USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
CONFIGURE_ARGS+=	--with-perl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plperl
MAKE_FILE=		GNUmakefile

# There is some dependency ordering problem in the Makefile,
# so force the headers to be generated first.
BUILD_TARGET=		perlchunks.h plperl_opmask.h all

.include "../../databases/postgresql17-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
