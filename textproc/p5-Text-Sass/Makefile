# $NetBSD: Makefile,v 1.23 2024/11/16 12:07:01 wiz Exp $

DISTNAME=	Text-Sass-v1.0.4
PKGNAME=	p5-${DISTNAME:S/v//}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Sass
COMMENT=	Perl 5 module implementing Sass
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Text-Sass/.packlist
PERL5_MODULE_TYPE=	Module::Build

REPLACE_PERL+=	bin/sass2css.pl

TOOL_DEPENDS+=	p5-Try-Tiny>=0.06:../../devel/p5-Try-Tiny

DEPENDS+=	p5-Readonly>=1.03:../../devel/p5-Readonly
DEPENDS+=	p5-Convert-Color>=0.05:../../converters/p5-Convert-Color

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
