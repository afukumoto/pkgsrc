# $NetBSD: Makefile,v 1.19 2024/08/25 06:19:16 wiz Exp $

DISTNAME=	yaml-0.2.5
PKGNAME=	lib${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://pyyaml.org/download/libyaml/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyyaml.org/wiki/LibYAML
COMMENT=	YAML 1.1 parser and emitter written in C
LICENSE=	mit

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	yaml-0.1.pc.in
TEST_TARGET=		check

# cmake support is incomplete
#CMAKE_CONFIGURE_ARGS+=		-DBUILD_SHARED_LIBS:BOOL=ON
#.include "../../devel/cmake/build.mk"

.include "../../mk/bsd.pkg.mk"
