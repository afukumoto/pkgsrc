# $NetBSD: Makefile,v 1.29 2024/11/16 12:07:39 wiz Exp $

DISTNAME=	HTML-Lint-2.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Lint
COMMENT=	Perl 5 module to check for HTML errors in a string or file
LICENSE=	artistic-2.0

CONFLICTS=	weblint-[0-9]*

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTML/Lint/.packlist

DEPENDS+=	p5-HTML-Parser>=3.47:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tagset>=3.03:../../www/p5-HTML-Tagset
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
