# $NetBSD: Makefile,v 1.15 2024/04/06 08:05:17 wiz Exp $

PKGREVISION= 7
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/drhelius/Gearsystem
COMMENT=	Sega Master System / Game Gear / SG-1000 emulator
LICENSE=	gnu-gpl-v3

UNLIMIT_RESOURCES+=	datasize virtualsize

USE_TOOLS+=	gmake

# Same as platforms/linux.
BUILD_DIRS=	platforms/bsd

MAKE_FLAGS+=	CXX=${CXX}
MAKE_FLAGS+=	GIT_VERSION="pkgsrc"

# Uses alloca, cannot use standard C++ on NetBSD.
FORCE_CXX_STD=	gnu++11

INSTALLATION_DIRS+=	bin share/applications share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_DIRS}/gearsystem \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/gearsystem.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/platforms/ios/Gearsystem/Images.xcassets/AppIcon.appiconset/sms_icon_120.png \
		${DESTDIR}${PREFIX}/share/pixmaps/gearsystem.png

.include "../../devel/SDL2/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.  include "../../graphics/glew/buildlink3.mk"
.  include "../../graphics/MesaLib/buildlink3.mk"
.endif
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
