# $NetBSD: Makefile,v 1.22 2024/11/16 12:05:23 wiz Exp $
#

DISTNAME=	Test-Script-Run-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Script-Run
COMMENT=	Perl 5 module to test scripts
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Test/Script/Run/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
TOOL_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
