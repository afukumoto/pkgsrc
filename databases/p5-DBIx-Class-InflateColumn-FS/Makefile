# $NetBSD: Makefile,v 1.16 2024/11/16 12:03:26 wiz Exp $

DISTNAME=	DBIx-Class-InflateColumn-FS-0.01007
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-Class-InflateColumn-FS
COMMENT=	Inflate/deflate columns to Path::Class::File objects
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/InflateColumn/FS/.packlist

DEPENDS+=	p5-DBIx-Class>=0.08000:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-UUIDColumns>=0.02005:../../databases/p5-DBIx-Class-UUIDColumns
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class

# For test really
TOOL_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
TOOL_DEPENDS+=	p5-DBICx-TestDatabase-[0-9]*:../../databases/p5-DBICx-TestDatabase

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
