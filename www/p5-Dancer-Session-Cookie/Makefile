# $NetBSD: Makefile,v 1.19 2024/11/16 12:07:37 wiz Exp $

DISTNAME=	Dancer-Session-Cookie-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Dancer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Dancer-Session-Cookie
COMMENT=	Encrypted cookie-based session backend for Dancer
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Dancer/Session/Cookie/.packlist

DEPENDS+=	p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC
DEPENDS+=	p5-Crypt-Rijndael-[0-9]*:../../security/p5-Crypt-Rijndael
DEPENDS+=	p5-Dancer>=1.1313:../../www/p5-Dancer
DEPENDS+=	p5-PerlX-Maybe-[0-9]*:../../devel/p5-PerlX-Maybe
DEPENDS+=	p5-Session-Storage-Secure-[0-9]*:../../www/p5-Session-Storage-Secure
DEPENDS+=	p5-String-CRC32-[0-9]*:../../textproc/p5-String-CRC32
DEPENDS+=	p5-Time-Duration-Parse-[0-9]*:../../time/p5-Time-Duration-Parse
DEPENDS+=	p5-Session-Storage-Secure>=0.010:../../www/p5-Session-Storage-Secure

TOOL_DEPENDS+=	p5-HTTP-Cookies-[0-9]*:../../www/p5-HTTP-Cookies
TOOL_DEPENDS+=	p5-HTTP-Date-[0-9]*:../../www/p5-HTTP-Date
TOOL_DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
TOOL_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TOOL_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
TOOL_DEPENDS+=	p5-Test-WWW-Mechanize-PSGI>=0:../../www/p5-Test-WWW-Mechanize-PSGI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
