# $NetBSD: Makefile,v 1.5 2024/11/26 19:50:10 osa Exp $

DISTNAME=	lua-resty-lrucache-0.15
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=openresty/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openresty/lua-resty-lrucache
COMMENT=	Lua-land LRU cache based on the LuaJIT FFI
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:build gmake

MAKE_ENV+=	LUA_INCLUDE_DIR=${PREFIX}/include/luajit-2.1
MAKE_ENV+=	LUA_LIB_DIR=${PREFIX}/share/luajit-2.1

BUILDLINK_API_DEPENDS.LuaJIT2+=	LuaJIT2>=2.1
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
