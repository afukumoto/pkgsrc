# $NetBSD: Makefile,v 1.16 2024/11/16 12:05:16 wiz Exp $

DISTNAME=	Test-EOL-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-EOL
COMMENT=	Check the correct line endings in your project
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/EOL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
