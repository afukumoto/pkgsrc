# $NetBSD: Makefile,v 1.22 2025/01/07 20:01:35 adam Exp $

DISTNAME=	tables-3.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tables/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pytables.org/
COMMENT=	Database package for large amounts of data
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.11:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cpuinfo-[0-9]*:../../sysutils/py-cpuinfo
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-numexpr>=2.6.2:../../math/py-numexpr
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.4.0:../../devel/py-typing-extensions

USE_LANGUAGES=	c c++

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pt2to3 pt2to3-${PYVERSSUFFIX} && \
	${MV} ptdump ptdump-${PYVERSSUFFIX} && \
	${MV} ptrepack ptrepack-${PYVERSSUFFIX} && \
	${MV} pttree pttree-${PYVERSSUFFIX} || ${TRUE}

# needs to be installed first
# as of 3.10.1
# FAILED (errors=314, skipped=59)
# many with
# FileNotFoundError: [Errno 2] No such file or directory: '/home/pbulk/.pytables-cpuinfo.json'
do-test:
	${PYTHONBIN} -m tables.tests.test_all

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/blosc/buildlink3.mk"
.include "../../devel/blosc2/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=2.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
