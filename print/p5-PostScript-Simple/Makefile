# $NetBSD: Makefile,v 1.20 2024/11/16 12:06:24 wiz Exp $

DISTNAME=	PostScript-Simple-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PostScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PostScript-Simple
COMMENT=	Produce PostScript files from Perl
LICENSE=	gnu-gpl-v2

REPLACE_PERL+=		lib/PostScript/Simple.pm lib/PostScript/Simple/EPS.pm

PERL5_PACKLIST=		auto/PostScript/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
