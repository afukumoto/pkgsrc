# $NetBSD: Makefile,v 1.33 2024/11/16 12:04:52 wiz Exp $

DISTNAME=	Package-Stash-0.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Package/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Package-Stash
COMMENT=	Perl 5 module providing routines for manipulating stashes
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-MooseX-Method-Signatures<=0.36

DEPENDS+=	p5-Dist-CheckConflicts>=0.02:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-Module-Implementation>=0.06:../../devel/p5-Module-Implementation
DEPENDS+=	p5-Package-Stash-XS>=0.26:../../devel/p5-Package-Stash-XS

TEST_DEPENDS+=		p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=		p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TEST_DEPENDS+=		p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=		p5-CPAN-Meta-Check-[0-9]*:../../devel/p5-CPAN-Meta-Check

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Package/Stash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
