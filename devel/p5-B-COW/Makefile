# $NetBSD: Makefile,v 1.9 2024/11/16 12:03:41 wiz Exp $

DISTNAME=	B-COW-0.007
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AT/ATOOMIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/B::COW
COMMENT=	Some naive additional B helpers to check the COW status of one SvPV
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/B/COW/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
