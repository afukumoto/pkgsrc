# $NetBSD: Makefile,v 1.19 2024/11/06 16:14:53 taca Exp $

DISTNAME=	mail-2.8.1
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=0.1.1:../../mail/ruby-mini_mime

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
