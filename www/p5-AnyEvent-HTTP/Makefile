# $NetBSD: Makefile,v 1.28 2024/11/16 12:07:25 wiz Exp $

DISTNAME=	AnyEvent-HTTP-2.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AnyEvent-HTTP
COMMENT=	Perl 5 module providing simple but non-blocking HTTP/HTTPS client
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/AnyEvent/HTTP/.packlist

DEPENDS+=	p5-AnyEvent>=5:../../devel/p5-AnyEvent

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
