# $NetBSD: Makefile,v 1.12 2024/10/14 06:45:35 wiz Exp $

PKGNAME=	deepstate-libfuzzer-${VERSION}
PKGREVISION=	2

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	deepstate>=${VERSION}:../../devel/deepstate
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}

CMAKE_CONFIGURE_ARGS+=	-DPYTHON=${PREFIX}/bin/python${PYVERSSUFFIX}
CMAKE_CONFIGURE_ARGS+=	-DDEEPSTATE_LIBFUZZER=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_COMPILER=${CLANGBASE:Q}/bin/clang
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_COMPILER=${CLANGBASE:Q}/bin/clang++

PYTHON_VERSIONS_INCOMPATIBLE=	39 311 312 313

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${CONFIGURE_DIRS}

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/libdeepstate_LF.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/compiler/clang.mk"
.include "../../lang/compiler-rt/buildlink3.mk"
.include "../../devel/deepstate/Makefile.common"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
