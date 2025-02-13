# $NetBSD: Makefile,v 1.28 2024/11/16 12:06:51 wiz Exp $

DISTNAME=	Pod-Weaver-4.020
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-Weaver
COMMENT=	Weave together a Pod document from an outline
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Config-MVP>=2.0:../../devel/p5-Config-MVP
DEPENDS+=	p5-Config-MVP-Reader-INI-[0-9]*:../../devel/p5-Config-MVP-Reader-INI
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Log-Dispatchouli>=1.100.710:../../devel/p5-Log-Dispatchouli
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-OneArgNew>=0:../../devel/p5-MooseX-OneArgNew
DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-Pod-Elemental>=0.100220:../../textproc/p5-Pod-Elemental
DEPENDS+=	p5-String-Flogger>=1.0:../../textproc/p5-String-Flogger
DEPENDS+=	p5-String-Formatter>=0.100680:../../textproc/p5-String-Formatter
DEPENDS+=	p5-String-RewritePrefix-[0-9]*:../../textproc/p5-String-RewritePrefix
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

TOOL_DEPENDS+=		p5-PPI-[0-9]*:../../devel/p5-PPI
TOOL_DEPENDS+=		p5-Software-License-[0-9]*:../../devel/p5-Software-License
TOOL_DEPENDS+=		p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences

PERL5_PACKLIST=		auto/Pod/Weaver/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
