# $NetBSD: Makefile,v 1.25 2024/11/16 12:06:01 wiz Exp $

DISTNAME=	Number-Compare-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Number-Compare
COMMENT=	Compiles a simple comparison to an anonymous subroutine
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Number/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
