# $NetBSD: Makefile,v 1.30 2024/11/16 12:07:02 wiz Exp $

DISTNAME=	Text-SimpleTable-2.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-SimpleTable
COMMENT=	Simple Eyecandy ASCII Tables
LICENSE=	artistic-2.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Text/SimpleTable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
