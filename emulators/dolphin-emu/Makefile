# $NetBSD: Makefile,v 1.64 2024/12/27 08:19:42 wiz Exp $

DISTNAME=	dolphin-emu-5.0
PKGREVISION=	55
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=dolphin-emu/}
GITHUB_PROJECT=	dolphin
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://dolphin-emu.org/
COMMENT=	Nintendo GameCube and Wii emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	msgfmt msgmerge pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# Since SFML is not available in pkgsrc, make sure the included version
# is always used.
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_SFML=ON

CMAKE_CONFIGURE_ARGS+=	-DPKGMANDIR=${PKGMANDIR}

USE_CXX_FEATURES+=	unique_ptr

.include "../../mk/bsd.prefs.mk"

# Claims to only support little endian architectures.
ONLY_FOR_PLATFORM=	${LITTLEENDIANPLATFORMS}

# No support in the code.
BROKEN_ON_PLATFORM+=	SunOS-*-*

.if ${MACHINE_ARCH} != "x86_64"
CMAKE_CONFIGURE_ARGS+=		-DENABLE_GENERIC=1
.endif

# "Couldn't find libevdev and/or libudev.  Can't build evdev controller backend."
CMAKE_CONFIGURE_ARGS.Linux+=	-DENABLE_EVDEV=0

# JIT
NOT_PAX_MPROTECT_SAFE+=	bin/dolphin-emu
NOT_PAX_MPROTECT_SAFE+=	bin/dolphin-emu-nogui

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../security/mbedtls/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.endif
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
