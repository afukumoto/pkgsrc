# $NetBSD: Makefile,v 1.11 2024/11/16 12:05:44 wiz Exp $

DISTNAME=	Image-JpegTran-AutoRotate-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AU/AUDREYT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Image-JpegTran-AutoRotate
COMMENT=	Losslessly fix JPEG orientation
LICENSE=	cc0-1.0-universal

TOOL_DEPENDS+=	p5-Devel-CheckLib-[0-9]*:../../devel/p5-Devel-CheckLib
DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool

PERL5_PACKLIST=	auto/Image/JpegTran/AutoRotate/.packlist

post-extract:
	rm -f ${WRKSRC}/Image-JpegTran/inc/Devel/CheckLib.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
