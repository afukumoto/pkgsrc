# $NetBSD: Makefile,v 1.307 2024/11/14 22:20:45 wiz Exp $

# Needs update to 6.9.0
DISTNAME=	calibre-5.44.0
PKGREVISION=	26
CATEGORIES=	misc
MASTER_SITES=	https://download.calibre-ebook.com/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.calibre-ebook.com/
COMMENT=	E-book library management application
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-apsw>=3.37.0nb1:../../databases/py-apsw
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-css-parser-[0-9]*:../../textproc/py-css-parser
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.4.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-dns>=1.6.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-feedparser>=6.0.0:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text
DEPENDS+=	${PYPKGPREFIX}-html5-parser-[0-9]*:../../textproc/py-html5-parser
DEPENDS+=	${PYPKGPREFIX}-jeepney>=0.6.0:../../sysutils/py-jeepney
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-mechanize>=0.1.11nb1:../../www/py-mechanize
DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-netifaces>=0.8:../../net/py-netifaces
DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.7.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-psutil>=0.6.1:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-qt5-webengine-[0-9]*:../../x11/py-qt5-webengine
DEPENDS+=	${PYPKGPREFIX}-regex-[0-9]*:../../textproc/py-regex
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-soupsieve-[0-9]*:../../www/py-soupsieve
DEPENDS+=	${PYPKGPREFIX}-zeroconf-[0-9]*:../../net/py-zeroconf

# for installation
TOOL_DEPENDS+=	${PYPKGPREFIX}-qt-builder>=1:../../x11/py-qt-builder
TOOL_DEPENDS+=	${PYPKGPREFIX}-sip6-[0-9]*:../../x11/py-sip6
TOOL_DEPENDS+=	xdg-utils>=1.0.2:../../misc/xdg-utils

EXTRACT_USING=	bsdtar

USE_LANGUAGES=			c c++
FORCE_CXX_STD=			c++17
USE_LIBTOOL=			yes
USE_TOOLS+=			pkg-config pax
PYSETUPOPTARGS=			# empty
PYSETUPINSTALLARGS=		--prefix=${PREFIX} --root=${DESTDIR:Q}${PREFIX}
MAKE_JOBS_SAFE=			no	# setup.py does not like -j

INSTALLATION_DIRS=	share/applications
INSTALLATION_DIRS+=	share/icons
INSTALLATION_DIRS+=	share/calibre/recipes

FIX_PYTHON_FILES+=	*.py
FIX_PYTHON_FILES+=	recipes/*.recipe
FIX_PYTHON_FILES+=	*/*.py
FIX_PYTHON_FILES+=	*/*/*.py
FIX_PYTHON_FILES+=	*/*/*/*.py
FIX_PYTHON_FILES+=	*/*/*/*/*.py
FIX_PYTHON_FILES+=	*/*/*/*/*/*.py
FIX_PYTHON_FILES+=	*/*/*/*/*/*/*.py

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e "s,^QMAKE =.*,QMAKE = '${PREFIX}/qt5/bin/qmake',"
SUBST_MESSAGE.prefix=	Fixing path to QMAKE
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	setup/build_environment.py

# This one is for /usr/bin/env python (or even /usr/bin/env Python or /usr/bin/python2)
SUBST_CLASSES+=		path
SUBST_SED.path+=	-e "s,\#! */usr/bin/env *python2,\#!${PYTHONBIN},"
SUBST_SED.path+=	-e "s,\#! */usr/bin/env *python[0-9.]*,\#!${PYTHONBIN},"
SUBST_MESSAGE.path=	Fixing path to python.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	${FIX_PYTHON_FILES}

SUBST_CLASSES+=		plat
SUBST_SED.plat+=	-e "/supported_platforms =/s/'linux'/'linux', 'netbsd'/"
SUBST_MESSAGE.plat=	Fixing supported platforms
SUBST_STAGE.plat=	pre-configure
SUBST_FILES.plat=	src/calibre/devices/misc.py
SUBST_FILES.plat+=	src/calibre/devices/*/*driver.py
SUBST_FILES.plat+=	src/calibre/library/catalogs/*.py
SUBST_FILES.plat+=	src/calibre/ebooks/metadata/sources/base.py
SUBST_FILES.plat+=	src/calibre/ebooks/metadata/archive.py
SUBST_FILES.plat+=	src/calibre/ebooks/html/to_zip.py
SUBST_FILES.plat+=	src/calibre/customize/*.py

REPLACE_BASH+=		resources/calibre-portable.sh

# These ones are for replacing python[0-9*] with PYTHONBIN
REPLACE_PYTHON+=	recipes/animal_politico.recipe
REPLACE_PYTHON+=	recipes/respekt_magazine.recipe
REPLACE_PYTHON+=	recipes/kompiutierra.recipe
REPLACE_PYTHON+=	recipes/trouw.recipe
REPLACE_PYTHON+=	src/calibre/ebooks/metadata/odt.py
REPLACE_PYTHON+=	src/calibre/utils/*.py
REPLACE_PYTHON+=	src/odf/*.py

MAKE_ENV+=		PODOFO_INC_DIR=${BUILDLINK_PREFIX.podofo}/include/podofo
MAKE_ENV+=		PODOFO_LIB_DIR=${BUILDLINK_PREFIX.podofo}/lib
MAKE_ENV+=		SIP_DIR=${PREFIX}/share/sip${PYVERSSUFFIX}/PyQt5
MAKE_ENV+=		LFLAGS=${LDFLAGS:Q}

# Turn off x bits on non-executable files.
post-extract:
	find  ${WRKSRC}/src/calibre/devices ${WRKSRC}/src/calibre/ebooks ${WRKSRC}/src/calibre/web -name '*.py' -exec chmod a-x \{} \;
	find  ${WRKSRC}/resources/images/mimetypes  -name '*.png' -exec chmod a-x \{} \;

post-install:
	cd ${WRKSRC}/recipes && pax -wr -pma *.recipe \
	    ${DESTDIR}${PREFIX}/share/calibre/recipes
	cd ${WRKSRC} && pax -wr -pma Changelog* README.md \
	    COPYRIGHT INSTALL.rst LICENSE.* \
	    ${DESTDIR}${PREFIX}/share/doc/calibre

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} ./setup.py test

.include "options.mk"

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../archivers//bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.chmlib+=	chmlib>=0.40
.include "../../devel/chmlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmtp+=	libmtp>=1.1.5
.include "../../devel/libmtp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/egg.mk"
_PYSETUPTOOLSINSTALLARGS=	# empty
# Get rid of --root=${DESTDIR}, use our own version from above instead.
# because the setup.py is not the standard one and behaves differently.
_PYSETUPINSTALLARGS=	${PYSETUPINSTALLARGS} ${PYSETUPOPTARGS} ${_PYSETUPTOOLSINSTALLARGS}
.include "../../print/podofo/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=0.20.2
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/hyphen/buildlink3.mk"
.include "../../textproc/libstemmer/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
