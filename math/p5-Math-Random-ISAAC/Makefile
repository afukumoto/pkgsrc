# $NetBSD: Makefile,v 1.14 2024/11/16 12:05:59 wiz Exp $
#

DISTNAME=	Math-Random-ISAAC-1.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	math perl5 security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-Random-ISAAC
COMMENT=	Perl interface to the ISAAC PRNG algorithm
LICENSE=	cc0-1.0-universal

DEPENDS+=	p5-Math-Random-ISAAC-XS-[0-9]*:../../math/p5-Math-Random-ISAAC-XS

TOOL_DEPENDS+=	p5-Test-NoWarnings>=0.084:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Math/Random/ISAAC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
