# $NetBSD: Makefile,v 1.45 2024/11/16 12:06:29 wiz Exp $

DISTNAME=		Crypt-OpenSSL-Random-0.17
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://perl-openssl.sourceforge.net/
COMMENT=		Perl5 wrapper module for OpenSSL pseudo-random number generator
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Crypt-OpenSSL-Guess>=0.11:../../security/p5-Crypt-OpenSSL-Guess

USE_LANGUAGES=		c
MAKE_ENV+=		DYLD_LIBRARY_PATH=${PREFIX}/lib # build on macOS

PERL5_PACKLIST=		auto/Crypt/OpenSSL/Random/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
