# $NetBSD: Makefile,v 1.25 2024/11/16 12:06:01 wiz Exp $

DISTNAME=	Set-Crontab-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Set-Crontab
COMMENT=	Perl module to parse crontab(5)-like lists of integers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Set/Crontab/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
