# $NetBSD: Makefile,v 1.20 2024/11/16 12:03:15 wiz Exp $
#

DISTNAME=	Device-XBee-API-0.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JE/JEAGLE/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Device::XBee::API
COMMENT=	Object-oriented Perl interface to Digi XBee module API mode
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Device-SerialPort>=1.04:../../comms/p5-Device-SerialPort

WRKSRC=		${WRKDIR}/Device-XBee-API
USE_LANGUAGES=	# none

PERL5_PACKLIST=	auto/Device/XBee/API/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
