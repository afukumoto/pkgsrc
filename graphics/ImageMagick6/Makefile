# $NetBSD: Makefile,v 1.75 2024/11/14 22:20:04 wiz Exp $

PKGREVISION= 6
.include "Makefile.common"

PKGNAME=	ImageMagick6-${DISTVERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Package for display and interactive manipulation of images

CONFLICTS=	geomview<1.8.1nb2  # used to have a program named 'animate'

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config:run
CONFIGURE_ARGS+=	--disable-assert
CONFIGURE_ARGS+=	--with-xml=yes
CONFIGURE_ARGS+=	--without-perl
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--program-suffix=6
# http://www.imagemagick.org/discourse-server/viewtopic.php?f=2&t=25475
CONFIGURE_ARGS.NetBSD+=	--disable-openmp
PKGCONFIG_OVERRIDE=	Magick++/lib/ImageMagick++.pc.in
PKGCONFIG_OVERRIDE+=	Magick++/lib/Magick++.pc.in
PKGCONFIG_OVERRIDE+=	magick/ImageMagick.pc.in
PKGCONFIG_OVERRIDE+=	magick/MagickCore.pc.in
PKGCONFIG_OVERRIDE+=	wand/MagickWand.pc.in
PKGCONFIG_OVERRIDE+=	wand/Wand.pc.in

LDFLAGS.SunOS+=		-lsendfile

SUBST_CLASSES+=		pkgcfg
SUBST_FILES.pkgcfg=	${PKGCONFIG_OVERRIDE} Magick++/bin/Magick++-config.in
SUBST_FILES.pkgcfg+=	magick/Magick-config.in magick/MagickCore-config.in
SUBST_FILES.pkgcfg+=	wand/MagickWand-config.in wand/Wand-config.in
SUBST_MESSAGE.pkgcfg=	Fixing pkg-config requirements.
SUBST_SED.pkgcfg=	-e 's|MagickCore-config |MagickCore-config6 |g'
SUBST_SED.pkgcfg+=	-e 's|Wand-config|Wand-config6|g'
SUBST_SED.pkgcfg+=	-e 's|s MagickWand|s MagickWand-6.Q16|g'
SUBST_SED.pkgcfg+=	-e 's|s: MagickWand|s: MagickWand-6.Q16|g'
SUBST_SED.pkgcfg+=	-e 's|s MagickCore|s MagickCore-6.Q16|g'
SUBST_SED.pkgcfg+=	-e 's|s: MagickCore|s: MagickCore-6.Q16|g'
SUBST_SED.pkgcfg+=	-e 's|Magick++-config|Magick++-config6|g'
SUBST_SED.pkgcfg+=	-e 's|Magick-config |Magick-config6 |g'
SUBST_SED.pkgcfg+=	-e 's|s Magick++|s Magick++-6.Q16|g'
SUBST_SED.pkgcfg+=	-e 's|@PKG_CONFIG@|${PREFIX}/bin/pkg-config|g'
SUBST_STAGE.pkgcfg=	pre-configure
SUBST_NOOP_OK.pkgcfg=	yes
# The files magick/ImageMagick.pc.in and magick/MagickCore.pc.in are not
# modified, and they don't need to since their names don't appear in any
# "Requires:" line.

USE_CC_FEATURES+=	c99
FORCE_C_STD=		c99

TEST_TARGET=		check

.include "options.mk"

# Avoid compiler bug on "mipsel" (cobalt?)
.if ${MACHINE_ARCH} == "mipsel"
CFLAGS+=		-O
.endif

PKG_SYSCONFSUBDIR=	ImageMagick-${IM_MAJOR_LIB_VER}
EGDIR=			${PREFIX}/share/examples/ImageMagick6
CONF_FILES+=		${EGDIR}/coder.xml ${PKG_SYSCONFDIR}/coder.xml
CONF_FILES+=		${EGDIR}/colors.xml ${PKG_SYSCONFDIR}/colors.xml
CONF_FILES+=		${EGDIR}/delegates.xml ${PKG_SYSCONFDIR}/delegates.xml
CONF_FILES+=		${EGDIR}/log.xml ${PKG_SYSCONFDIR}/log.xml
CONF_FILES+=		${EGDIR}/magic.xml ${PKG_SYSCONFDIR}/magic.xml
CONF_FILES+=		${EGDIR}/mime.xml ${PKG_SYSCONFDIR}/mime.xml
CONF_FILES+=		${EGDIR}/thresholds.xml ${PKG_SYSCONFDIR}/thresholds.xml
CONF_FILES+=		${EGDIR}/type-dejavu.xml ${PKG_SYSCONFDIR}/type-dejavu.xml
CONF_FILES+=		${EGDIR}/type-ghostscript.xml ${PKG_SYSCONFDIR}/type-ghostscript.xml
CONF_FILES+=		${EGDIR}/type-windows.xml ${PKG_SYSCONFDIR}/type-windows.xml
CONF_FILES+=		${EGDIR}/type.xml ${PKG_SYSCONFDIR}/type.xml

SUBST_CLASSES+=		fix-cfg
SUBST_STAGE.fix-cfg=	pre-configure
SUBST_MESSAGE.fix-cfg=	Fixing configure.xml.
SUBST_FILES.fix-cfg=	config/configure.xml.in
SUBST_VARS.fix-cfg=	CONFIGURE_ARGS

SUBST_CLASSES+=		fix-etc
SUBST_STAGE.fix-etc=	pre-configure
SUBST_MESSAGE.fix-etc=	Handle configuration files.
SUBST_FILES.fix-etc=	Makefile.in
SUBST_SED.fix-etc=	-e 's,^configlibdir =.*,configlibdir = $$(DATA_DIR)/examples/ImageMagick6,'

SUBST_CLASSES+=			fix-tools
SUBST_STAGE.fix-tools=		pre-install
SUBST_MESSAGE.fix-tools=	Unwrapping tools path in delegate paths.
SUBST_FILES.fix-tools=		config/delegates.xml
SUBST_SED.fix-tools=		-e 's,${TOOLS_DIR},,g'

# failed to convert strong functions and variables: Invalid type identifier
CTF_FILES_SKIP+=	lib/libMagickCore-6.Q16.so.5.0.0
CTF_FILES_SKIP+=	lib/libMagickWand-6.Q16.so.5.0.0
CTF_FILES_SKIP+=	lib/libMagickCore-6.Q16.so.*	# CPU limit exceeded

post-install:
	${INSTALL_DATA} ${WRKSRC}/config/policy*xml ${DESTDIR}${EGDIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
