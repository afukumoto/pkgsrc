# $NetBSD: Makefile,v 1.18 2024/11/16 12:04:17 wiz Exp $

DISTNAME=	File-Slurper-0.014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Slurper
COMMENT=	Simple, sane and efficient module to slurp a file
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

PERL5_PACKLIST=		auto/File/Slurper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
