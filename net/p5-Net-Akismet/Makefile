# $NetBSD: Makefile,v 1.18 2024/11/16 12:06:10 wiz Exp $
#

DISTNAME=	Net-Akismet-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Akismet
COMMENT=	Perl 5 interface to Akismet - comment and trackback spam fighter

USE_LANGUAGES=		# empty

DEPENDS+=	p5-libwww>=5.09:../../www/p5-libwww

PERL5_PACKLIST=		auto/Net/Akismet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
