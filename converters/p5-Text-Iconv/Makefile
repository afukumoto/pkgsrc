# $NetBSD: Makefile,v 1.41 2024/11/16 12:03:18 wiz Exp $

DISTNAME=	Text-Iconv-1.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Iconv
COMMENT=	Perl interface to iconv() codeset conversion function

PERL5_PACKLIST=		auto/Text/Iconv/.packlist

MAKE_PARAMS+=	INC="-I${BUILDLINK_PREFIX.iconv}/include"
MAKE_PARAMS+=	LIBS="-L${BUILDLINK_PREFIX.iconv}/lib"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
