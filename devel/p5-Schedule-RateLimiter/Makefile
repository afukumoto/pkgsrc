# $NetBSD: Makefile,v 1.27 2024/11/16 12:05:03 wiz Exp $

DISTNAME=	Schedule-RateLimiter-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	19
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Schedule/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module to schedule tasks with rate limiting

USE_LANGUAGES=	# empty

#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/Schedule/RateLimiter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
