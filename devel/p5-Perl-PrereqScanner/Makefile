# $NetBSD: Makefile,v 1.28 2024/11/16 12:04:56 wiz Exp $
#

DISTNAME=	Perl-PrereqScanner-1.100
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Perl-PrereqScanner
COMMENT=	Tool to scan your Perl code for its prerequisites
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.16.0,p5-CPAN-Meta-Requirements>=2.120.630}:../../devel/p5-CPAN-Meta-Requirements
DEPENDS+=	p5-Getopt-Long-Descriptive-[0-9]*:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Module-Path-[0-9]*:../../filesystems/p5-Module-Path
DEPENDS+=	p5-Moo>=2.0:../../devel/p5-Moo
DEPENDS+=	p5-PPI>=1.205:../../devel/p5-PPI
DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-String-RewritePrefix>=0.005:../../textproc/p5-String-RewritePrefix
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

#TOOL_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple
TOOL_DEPENDS+=		p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
# for make test
TOOL_DEPENDS+=		p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

PERL5_PACKLIST=	auto/Perl/PrereqScanner/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
