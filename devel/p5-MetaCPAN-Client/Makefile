# $NetBSD: Makefile,v 1.34 2024/11/16 12:04:33 wiz Exp $

DISTNAME=	MetaCPAN-Client-2.031000
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MICKEY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/MetaCPAN::Client
COMMENT=	Comprehensive, DWIM-featured client to the MetaCPAN API
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-Safe-Isa-[0-9]*:../../devel/p5-Safe-Isa
DEPENDS+=	p5-Ref-Util-[0-9]*:../../devel/p5-Ref-Util
DEPENDS+=	p5-Class-Load-[0-9]*:../../devel/p5-Class-Load
DEPENDS+=	p5-MooX-Types-MooseLike-[0-9]*:../../devel/p5-MooX-Types-MooseLike
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump

TEST_DEPENDS+=	p5-Log-Any-[0-9]*:../../devel/p5-Log-Any
TEST_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
TEST_DEPENDS+=	p5-Search-Elasticsearch-[0-9]*:../../devel/p5-Search-Elasticsearch
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Any-URI-Escape-[0-9]*:../../www/p5-Any-URI-Escape
TEST_DEPENDS+=	p5-WWW-Mechanize-Cached-[0-9]*:../../www/p5-WWW-Mechanize-Cached
TEST_DEPENDS+=	p5-LWP-Protocol-https>=0:../../www/p5-LWP-Protocol-https
TEST_DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
TEST_DEPENDS+=	p5-HTTP-Tiny-Mech-[0-9]*:../../www/p5-HTTP-Tiny-Mech
TEST_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
TEST_DEPENDS+=	p5-Ref-Util-[0-9]*:../../devel/p5-Ref-Util

PERL5_PACKLIST=		auto/MetaCPAN/Client/.packlist
USE_LANGUAGES=		# none
REPLACE_PERL+=		fav.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
