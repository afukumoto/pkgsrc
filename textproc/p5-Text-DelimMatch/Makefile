# $NetBSD: Makefile,v 1.35 2024/11/16 12:06:58 wiz Exp $
#

DISTNAME=	DelimMatch-1.06a
PKGNAME=	p5-Text-${DISTNAME}
PKGREVISION=	18
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/DelimMatch/
COMMENT=	Find regexp delimited strings with proper nesting

WRKSRC=			${WRKDIR}/${DISTNAME:S/a$//}
PERL5_PACKLIST=		auto/Text/DelimMatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
