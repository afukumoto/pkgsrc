# $NetBSD: Makefile,v 1.29 2024/11/16 12:04:13 wiz Exp $

DISTNAME=	File-DesktopEntry-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-DesktopEntry
COMMENT=	Perl module for handling .desktop files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-BaseDir>=0.03:../../devel/p5-File-BaseDir
# for make test
TOOL_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=		auto/File/DesktopEntry/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
