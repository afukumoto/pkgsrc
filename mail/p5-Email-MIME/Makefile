# $NetBSD: Makefile,v 1.43 2024/11/16 12:05:48 wiz Exp $

DISTNAME=		Email-MIME-1.954
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Email-MIME
COMMENT=		Perl module for easy MIME message parsing
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Email-Address-XS-[0-9]*:../../mail/p5-Email-Address-XS
DEPENDS+=		p5-Email-MIME-ContentType>=1.023:../../mail/p5-Email-MIME-ContentType
DEPENDS+=		p5-Email-MIME-Encodings>=1.314:../../mail/p5-Email-MIME-Encodings
DEPENDS+=		p5-Email-MessageID-[0-9]*:../../mail/p5-Email-MessageID
# Email::Simple-2.100 contains both: Email::Simple and Email::Simple::Creator
DEPENDS+=		p5-Email-Simple>=2.206:../../mail/p5-Email-Simple
DEPENDS+=		p5-MIME-Types>=1.13:../../mail/p5-MIME-Types
DEPENDS+=		p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime

PERL5_PACKLIST=		auto/Email/MIME/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
