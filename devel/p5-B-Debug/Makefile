# $NetBSD: Makefile,v 1.8 2024/11/16 12:03:41 wiz Exp $

DISTNAME=	B-Debug-1.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RU/RURBAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/B-Debug
COMMENT=	Walk Perl syntax tree, printing debug info about ops
LICENSE=	gnu-gpl-v1

USE_LANGUAGES=	# none
PERL5_PACKLIST=	auto/B/Debug/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
