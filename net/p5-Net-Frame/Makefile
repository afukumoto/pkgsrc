# $NetBSD: Makefile,v 1.23 2024/11/16 12:06:13 wiz Exp $

DISTNAME=	Net-Frame-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The base framework for frame crafting
HOMEPAGE=	https://metacpan.org/release/Net-Frame
LICENSE=	artistic

DEPENDS+=	p5-Class-Gomor>=1.0:../../devel/p5-Class-Gomor
DEPENDS+=	p5-Socket6-[0-9]*:../../net/p5-Socket6
DEPENDS+=	p5-Net-IPv6Addr-[0-9]*:../../net/p5-Net-IPv6Addr
DEPENDS+=	p5-Bit-Vector-[0-9]*:../../devel/p5-Bit-Vector

PERL5_PACKLIST=		auto/Net/Frame/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
