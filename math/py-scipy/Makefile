# $NetBSD: Makefile,v 1.91 2025/01/08 12:46:26 gdt Exp $

DISTNAME=	scipy-1.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scipy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scipy.org/
COMMENT=	Scientific Algorithms Library for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.8:../../devel/py-cython
TOOL_DEPENDS+=	meson>=1.5.0:../../devel/meson
TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python>=0.15.0:../../devel/py-meson_python
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-pythran>=0.14.0:../../math/py-pythran
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-mpmath-[0-9]*:../../math/py-mpmath
TEST_DEPENDS+=	${PYPKGPREFIX}-pooch-[0-9]*:../../devel/py-pooch
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_CC_FEATURES=	c17
USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++ fortran
USE_TOOLS+=		pkg-config
MAKE_ENV+=		ATLAS=None
# Upstream explicitly checks for 9; see meson.build.
# gcc does not clearly document what version is needed for c17, but
# our gcc.mk says 8 works and chooses 10.
# gcc documents that 8 is suitable for c++17; our gcc.mk chooses 10.
# Thus, this GCC_REQD is a no-op at the moment, but required for
# correctness.
GCC_REQD+=		9

SUBST_CLASSES+=		f2py
SUBST_STAGE.f2py=	pre-configure
SUBST_MESSAGE.f2py=	Fixing f2py binary name.
SUBST_FILES.f2py=	scipy/meson.build
SUBST_FILES.f2py+=	tools/generate_f2pymod.py
SUBST_SED.f2py=		-e "s,('f2py'),('f2py-${PYVERSSUFFIX}'),"
SUBST_SED.f2py+=	-e "s,\['f2py',\['f2py-${PYVERSSUFFIX}',"

SUBST_CLASSES+=		pythran
SUBST_STAGE.pythran=	pre-configure
SUBST_MESSAGE.pythran=	Fixing pythran binary name.
SUBST_FILES.pythran=	meson.build
SUBST_SED.pythran=	-e "s,'pythran','pythran-${PYVERSSUFFIX}',"

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

.if defined(PKGSRC_FORTRAN) && ${PKGSRC_FORTRAN} == "gfortran"
PYSETUPBUILDARGS+=	--fcompiler=gnu95
.else
BROKEN=			"Requires fortran 95"
.endif

CPPFLAGS+=	-D__STDC_FORMAT_MACROS
FFLAGS+=	-fPIC

LDFLAGS.Darwin+=	-headerpad_max_install_names

# Same as for py-numpy.
# Except that py-scipy needs explicit linkage to libblas.so for
# netlib (otherwise there will be missing symbols in _superlu.so (vendored).
# Meson will locate libcblas itself with -Dblas=blas by guesswork,
# satisfying the meson setup. Proper fix is a future meson build where
# one can specify blas and cblas separately. The distinction
# does not matter for openblas.
BLAS_ACCEPTED=		${_BLAS_TYPES}
# next line is needed, don't believe pkglint
BLAS_C_INTERFACE=	yes
WHEEL_ARGS+=		-Csetup-args=-Dblas=${BLAS_PC}
WHEEL_ARGS+=		-Csetup-args=-Dlapack=${LAPACK_PC}
WHEEL_ARGS+=		-Ccompile-args=-j${MAKE_JOBS:U1}

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	${FIND} ${DESTDIR}${PREFIX}/${PYSITELIB} -name "*.so" |			\
		while read lib; do						\
		libname=`basename $${lib}`;					\
		libdir=`dirname $${lib} | sed -e 's,${DESTDIR},,'`;		\
		install_name_tool -id $${libdir}/$${libname} $${lib};		\
	done
.endif

# self test failures for 1.1.0 reported at
# https://github.com/scipy/scipy/issues/9196
# needs 'make install' first!
do-test:
	cd ${WRKDIR} && \
	${PYTHONBIN} -c "import scipy; scipy.test('full')"

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.23.5
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-pythran/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
