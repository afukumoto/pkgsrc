# $NetBSD: Makefile,v 1.28 2024/11/16 12:08:05 wiz Exp $

DISTNAME=	WWW-Shorten-3.094
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WWW-Shorten
COMMENT=	Perl 5 module interface to URL shortening sites
LICENSE=	artistic-2.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/WWW/Shorten/.packlist

DEPENDS+=	p5-Config-Auto-[0-9]*:../../devel/p5-Config-Auto
DEPENDS+=	p5-URI>=1.27:../../www/p5-URI
DEPENDS+=	p5-libwww>=5.750:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
