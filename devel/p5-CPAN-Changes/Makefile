# $NetBSD: Makefile,v 1.17 2024/11/16 12:03:43 wiz Exp $

DISTNAME=	CPAN-Changes-0.500004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HAARG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-Changes
COMMENT=	Read and write Changes files
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		#empty
PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/CPAN/Changes/.packlist
PERL5_REQD+=		5.10
PERL5_REQD+=		5.11.4	# version >= 0.79
PERL5_REQD+=		5.2	# Text::Wrap >= 0
PERL5_REQD+=		5.13.4	# Test::More >= 0.96
PERL5_REQD+=		5.15.2	# ExtUtils::MakeMaker >= 6.59

TEST_DEPENDS+=		p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
