# $NetBSD: Makefile,v 1.25 2024/11/16 12:05:02 wiz Exp $

DISTNAME=	SUPER-1.20190531
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SUPER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SUPER
COMMENT=	Perl 5 module to control superclass method dispatch
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Identify>=0.03:../../devel/p5-Sub-Identify

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/SUPER/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
