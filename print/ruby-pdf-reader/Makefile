# $NetBSD: Makefile,v 1.31 2024/11/06 14:45:02 taca Exp $

DISTNAME=	pdf-reader-2.13.0
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yob/pdf-reader
COMMENT=	Library for accessing the content of PDF files
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-Ascii85>=1.0.0:../../converters/ruby-Ascii85
DEPENDS+=	${RUBY_PKGPREFIX}-rc4>=0:../../security/ruby-rc4
DEPENDS+=	${RUBY_PKGPREFIX}-hashery>=2.0<3:../../devel/ruby-hashery
DEPENDS+=	${RUBY_PKGPREFIX}-afm>=0.2.1<0.3:../../fonts/ruby-afm
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=0:../../fonts/ruby-ttfunk

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
