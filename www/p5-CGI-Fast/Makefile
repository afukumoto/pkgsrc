# $NetBSD: Makefile,v 1.23 2024/11/16 12:07:28 wiz Exp $

DISTNAME=		CGI-Fast-2.17
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CGI-Fast
COMMENT=		CGI Interface for Fast CGI
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-CGI>=4:../../www/p5-CGI
DEPENDS+=	p5-FCGI-[0-9]*:../../www/p5-FCGI
# TEST_DEPENDS
TOOL_DEPENDS+=	p5-CPAN-Changes-[0-9]*:../../devel/p5-CPAN-Changes

PERL5_PACKLIST=		auto/CGI/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
