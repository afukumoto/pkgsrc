# $NetBSD: Makefile,v 1.43 2024/11/15 13:00:16 pin Exp $

DISTNAME=	lxqt-config-2.1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-config/
COMMENT=	System configuration control center
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

# Requires xorg-libinput, which we lack in pkgsrc.
CMAKE_CONFIGURE_ARGS+=	-DWITH_TOUCHPAD=OFF

.include "../../mk/bsd.prefs.mk"

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/lxqt-config \
		-L${PREFIX}/lib/lxqt-config/

# NetBSD base X11 places xkb config files in a non-standard location
.if ${OPSYS} == "NetBSD" && ${X11_TYPE} != "modular"
XKBSUB=	lib
.else
XKBSUB=	share
.endif

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	lxqt-config-input/keyboardlayoutconfig.h
SUBST_VARS.prefix=	X11BASE
SUBST_VARS.prefix+=	XKBSUB

DEPENDS+=	lxqt-menu-data-[0-9]*:../../sysutils/lxqt-menu-data
DEPENDS+=	lxqt-themes-[0-9]*:../../graphics/lxqt-themes
TOOL_DEPENDS+=	lxqt-build-tools>=2.1.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../x11/plasma6-libkscreen/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
