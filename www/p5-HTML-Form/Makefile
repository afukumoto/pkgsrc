# $NetBSD: Makefile,v 1.26 2024/11/16 12:07:39 wiz Exp $
#

DISTNAME=		HTML-Form-6.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-Form
COMMENT=		HTML Form Class that represents an HTML form element
LICENSE=		${PERL5_LICENSE}

CONFLICTS+=		p5-libwww<6.00

DEPENDS+=		p5-HTTP-Date>=6.00:../../www/p5-HTTP-Date
# for make test
TEST_DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
TEST_DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
TEST_DEPENDS+=		p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/HTML/Form/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
