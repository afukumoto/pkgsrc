# $NetBSD: Makefile,v 1.36 2024/11/16 12:04:48 wiz Exp $

DISTNAME=	Net-Netmask-2.0002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	charlie@rubberduck.com
COMMENT=	Perl5 module to parse and manipulate IP network blocks
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-UseAllModules>=0.17:../../devel/p5-Test-UseAllModules
RUN_DEPENDS+=	p5-Math-BigInt>=1.999811:../../math/p5-Math-BigInt

PERL5_PACKLIST=	auto/Net/Netmask/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
