# $NetBSD: Makefile,v 1.19 2024/11/16 12:03:38 wiz Exp $

DISTNAME=	AnyEvent-IRC-0.97
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AnyEvent-IRC
COMMENT=	Perl 5 event based IRC protocol client API
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/AnyEvent/IRC/.packlist

DEPENDS+=	p5-Object-Event-[0-9]*:../../devel/p5-Object-Event
DEPENDS+=	p5-AnyEvent>=5:../../devel/p5-AnyEvent

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
