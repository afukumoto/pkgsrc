# $NetBSD: Makefile,v 1.19 2024/11/16 12:04:22 wiz Exp $
#

DISTNAME=	Hash-FieldHash-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Hash-FieldHash
COMMENT=	Lightweight field hash for inside-out objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-LeakTrace>=0:../../devel/p5-Test-LeakTrace

PERL5_PACKLIST=		auto/Hash/FieldHash/.packlist
USE_LANGUAGES=		c
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
