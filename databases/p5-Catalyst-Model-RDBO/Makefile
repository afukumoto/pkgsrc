# $NetBSD: Makefile,v 1.22 2024/11/16 12:03:21 wiz Exp $

DISTNAME=	Catalyst-Model-RDBO-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Model-RDBO
COMMENT=	Rose::DB::Object model class for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.00:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Rose-DB-Object>=0:../../databases/p5-Rose-DB-Object

PERL5_PACKLIST=	auto/Catalyst/Model/RDBO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
