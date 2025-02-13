# $NetBSD: Makefile,v 1.97 2024/12/30 10:54:46 tsutsui Exp $

DISTNAME=	nokogiri-1.18.1
CATEGORIES=	textproc

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://nokogiri.org/
COMMENT=	HTML, XML, SAX, and Reader parser with XPath and CSS selector support
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mini_portile2>=2.8.2:../../misc/ruby-mini_portile2

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		pkg-config
CPPFLAGS+=		-I${PREFIX}/include/libxml2
MAKE_ENV+=		NOKOGIRI_USE_SYSTEM_LIBRARIES=yes
RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	:files ports/archives/libxml2-2.13.5.tar.xz= \
			ports/archives/libxslt-1.1.42.tar.xz=

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--no-as-needed

# XXX: work around bug in bootstrap-mk-files, remove when fixed
MAKE_ENV.SunOS+=	ARFLAGS=rcv

.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
