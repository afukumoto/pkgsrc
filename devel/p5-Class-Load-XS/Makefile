# $NetBSD: Makefile,v 1.24 2024/11/16 12:03:50 wiz Exp $

DISTNAME=	Class-Load-XS-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Load-XS
COMMENT=	XS implementation of parts of Class::Load
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Load>=0.15:../../devel/p5-Class-Load

TOOL_DEPENDS+=	p5-Module-Implementation>=0.04:../../devel/p5-Module-Implementation
TOOL_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TOOL_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TOOL_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Class/Load/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
