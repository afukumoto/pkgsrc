# $NetBSD: Makefile,v 1.68 2024/12/27 08:21:02 wiz Exp $

DISTNAME=	Wx-Perl-ProcessStream-0.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	49
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Wx-Perl-ProcessStream
COMMENT=	Access IO of external processes via events from WxWidgets
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Wx>=0.50:../../x11/p5-Wx

USE_TOOLS+=	perl

PERL5_PACKLIST=		auto/Wx/Perl/ProcessStream/.packlist

.include "../../x11/p5-Wx/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
