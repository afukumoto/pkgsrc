# $NetBSD: Makefile,v 1.303 2024/12/29 15:09:50 adam Exp $

DISTNAME=	inkscape-1.4
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	https://media.inkscape.org/dl/resources/file/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://www.inkscape.org/
COMMENT=	Scalable Vector Graphics (SVG) editor
LICENSE=	gnu-gpl-v2

.if !exists(/usr/bin/iconv)
TOOL_DEPENDS+=	libiconv-[0-9]*:../../converters/libiconv
.endif
DEPENDS+=	adwaita-icon-theme>0:../../graphics/adwaita-icon-theme
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
# for inkex.py, needed by most Python extension scripts
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-scour-[0-9]*:../../graphics/py-scour
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial

WRKSRC=		${WRKDIR}/${DISTNAME}_2024-10-09_e7c3feb100

CPPFLAGS.NetBSD+=	-Urounddown
CPPFLAGS.NetBSD+=	-Uroundup

# This should be resolved in CMakeLists.txt.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/inkscape

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
# GCC 7 is not good enough. It chokes on ${WRKSRC}/src/object/sp-factory.cpp:
# > static Func constexpr null = [] () -> SPObject* { return nullptr; };
# by emitting duplicate definitions for the same static data member. This
# is because its C++17 support is incomplete and does not treat constexpr
# data members as inline symbols. GCC 8 is also not good enough because it
# fails to infer the type of std::uniform_real_distribution() used in
# ${WRKSRC}/src/ui/tools/booleans-subitems.cpp.
GCC_REQD+=		9
# GNU make (gmake) is required for handling whitespace in filename.
USE_TOOLS+=		gmake gzip msgfmt msgmerge perl pkg-config

REPLACE_PERL+=		man/fix-roff-punct

UNLIMIT_RESOURCES=	datasize

SUBST_CLASSES+=		pypath
SUBST_STAGE.pypath=	pre-configure
SUBST_FILES.pypath=	src/extension/implementation/script.cpp
SUBST_VARS.pypath=	PYTHONBIN

SUBST_CLASSES+=		pycmd
SUBST_STAGE.pycmd=	pre-configure
SUBST_MESSAGE.pycmd=	Replacing COMMAND python in CMakeFiles.
SUBST_FILES.pycmd+=	share/*/CMakeLists.txt
SUBST_SED.pycmd=	-e "s,COMMAND python3,COMMAND ${PYTHONBIN},g"

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Replacing xdg search path.
SUBST_FILES.xdg+=	src/inkscape-main.cpp
SUBST_SED.xdg=		-e 's,xdg_data_dirs = "/usr/local/share/:/usr/share/",xdg_data_dirs = "'${PREFIX}'/share/",'

REPLACE_PYTHON+=	share/extensions/*.py

CHECK_INTERPRETER_SKIP+=	share/inkscape/extensions/genpofiles.sh
CHECK_INTERPRETER_SKIP+=	share/inkscape/extensions/simplepath.rb
CHECK_PORTABILITY_SKIP+=	packaging/macosx/Resources/bin/inkscape
CHECK_PORTABILITY_SKIP+=	packaging/macosx/ScriptExec/launcher-quartz-no-macintegration.sh

CMAKE_CONFIGURE_ARGS+=	-DPACKAGE_LOCALE_DIR=${PREFIX}/${PKGLOCALEDIR}/locale

MANCOMPRESSED=	yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CMAKE_CONFIGURE_ARGS+=	-DIntl_INCLUDE_DIR=${BUILDLINK_PREFIX.gettext}/include
.endif

# There exists some race condition in create_default_templates.py that
# makes default.es_MX.svg sometimes not get installed.
# (gettext translation file dependency not correctly expressed in cmake?)
# Run the script post-build to ensure all files are generated.
post-build:
	cd ${WRKSRC} && ${PYTHONBIN} share/templates/create_default_templates.py . .

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	${RUN} cd ${DESTDIR}${PREFIX} && \
		for f in lib/inkscape/libinkscape_base.${PKGVERSION_NOREV}.0.0.dylib; do	\
			install_name_tool -id						\
			${PREFIX}/$$f $$f;						\
		done
	${RUN} cd ${DESTDIR}${PREFIX} && \
		for f in bin/inkscape bin/inkview; do					\
			install_name_tool -change					\
			${PREFIX}/lib/libinkscape_base.${PKGVERSION_NOREV}.0.0.dylib	\
			${PREFIX}/lib/inkscape/libinkscape_base.${PKGVERSION_NOREV}.0.0.dylib	\
			$$f;								\
		done
.endif

.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.boehm-gc+=	boehm-gc>=7.4
.include "../../converters/libcdr/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libvisio/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/googletest/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsigcpp+=	libsigc++>=2.0.12
.include "../../devel/libsigc++/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.42
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.harfbuzz+=	harfbuzz>=2.2
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/potrace/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/double-conversion/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../textproc/gspell/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkmm3+=	gtkmm3>=3.24
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.gtk3:Mquartz}
.include "../../x11/gtk-mac-integration/buildlink3.mk"
.endif
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
