# $NetBSD: Makefile,v 1.24 2024/11/06 14:39:05 taca Exp $

DISTNAME=	braintree-4.23.0
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.braintreepaymentsolutions.com/gateway
COMMENT=	Braintree Gateway Ruby Client Library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-builder>=3.2.4:../../textproc/ruby-builder

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
