# $NetBSD: Makefile,v 1.1 2024/12/13 16:40:32 taca Exp $

DISTNAME=	activemodel-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activemodel${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 7.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	72
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
