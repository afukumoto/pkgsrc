# $NetBSD: Makefile,v 1.18 2024/11/16 12:05:41 wiz Exp $

DISTNAME=	Barcode-Code128-2.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/W/WR/WRW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Barcode-Code128
COMMENT=	Generate CODE 128 bar codes
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Barcode/Code128/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
