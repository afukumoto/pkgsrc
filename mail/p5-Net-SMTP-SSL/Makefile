# $NetBSD: Makefile,v 1.22 2024/11/16 12:05:54 wiz Exp $

DISTNAME=		Net-SMTP-SSL-1.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		mail perl5 security
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Net-SMTP-SSL
COMMENT=		Perl5 module providing SSL support for Net::SMTP
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/SMTP/SSL/.packlist

DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
