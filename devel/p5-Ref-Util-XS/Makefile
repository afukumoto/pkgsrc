# $NetBSD: Makefile,v 1.11 2024/11/16 12:05:00 wiz Exp $

DISTNAME=	Ref-Util-XS-0.117
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Ref/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Ref-Util-XS
COMMENT=	XS implementation for Ref::Util
LICENSE=	mit

PERL5_PACKLIST=		auto/Ref/Util/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
