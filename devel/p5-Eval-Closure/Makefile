# $NetBSD: Makefile,v 1.24 2024/11/16 12:04:09 wiz Exp $

DISTNAME=	Eval-Closure-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DO/DOY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Eval-Closure
COMMENT=	Safely and cleanly create closures via string eval
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

# for make test
TOOL_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TOOL_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TOOL_DEPENDS+=	p5-Devel-LexAlias-[0-9]*:../../devel/p5-Devel-LexAlias

PERL5_PACKLIST=		auto/Eval/Closure/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
