# $NetBSD: Makefile,v 1.16 2024/11/16 12:04:47 wiz Exp $
#

DISTNAME=		MouseX-NativeTraits-1.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		12
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MouseX/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/MouseX-NativeTraits
COMMENT=		Extend your attribute interfaces for Mouse
LICENSE=		${PERL5_LICENSE}

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/MouseX/NativeTraits/.packlist

TOOL_DEPENDS+=		p5-Any-Moose>=0.13:../../devel/p5-Any-Moose
TOOL_DEPENDS+=		p5-Test-Fatal>=0.003:../../devel/p5-Test-Fatal

DEPENDS+=		p5-Mouse>=0.82:../../devel/p5-Mouse

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
