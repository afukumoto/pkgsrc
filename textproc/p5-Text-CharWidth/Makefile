# $NetBSD: Makefile,v 1.22 2024/11/16 12:06:57 wiz Exp $

DISTNAME=	Text-CharWidth-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-CharWidth
COMMENT=	Perl5 wrappers around wcwidth(3) and family

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Text/CharWidth/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
