# $NetBSD: Makefile,v 1.22 2024/11/16 12:04:36 wiz Exp $

DISTNAME=		Module-FromPerlVer-0.030000
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Module-FromPerlVer
COMMENT=		Install modules compatible with the running perl
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=		p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
# TEST_DEPENDS
TOOL_DEPENDS+=		p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PERL5_PACKLIST=		auto/Module/FromPerlVer/.packlist
USE_TOOLS+=		perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
