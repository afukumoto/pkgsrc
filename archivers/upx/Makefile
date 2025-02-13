# $NetBSD: Makefile,v 1.37 2024/12/02 07:43:59 nia Exp $

DISTNAME=		upx-3.96
PKGREVISION=		3
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_GITHUB:=upx/}
GITHUB_TAG=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.gz	# must be defined before SITES.${DISTNAME:...}
DISTFILES=		${DEFAULT_DISTFILES} ${DISTNAME:S/upx/upx-lzma-sdk/}${EXTRACT_SUFX}
SITES.${DISTNAME:S/upx/upx-lzma-sdk/}${EXTRACT_SUFX}=	${MASTER_SITE_GITHUB:S,^,-,:=upx/}upx-lzma-sdk/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://upx.github.io/
COMMENT=	Ultimate packer for executables
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl pod2man pod2html pod2text
NO_CONFIGURE=	yes
BUILD_DIRS=	src doc
MAKE_ENV+=	PREFIX=${PREFIX} UPX_UCLDIR=${PREFIX}

MAKE_FLAGS+=	CXXFLAGS_WERROR=

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/upx

BUILDLINK_TRANSFORM+=		rm:-mcpu=i686
BUILDLINK_TRANSFORM+=		rm:-Werror
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-Map rm:-Wl,upx.map

post-extract:
	rmdir ${WRKSRC}/src/lzma-sdk
	ln -sf ${WRKDIR}/upx-lzma-sdk* ${WRKSRC}/src/lzma-sdk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/upx.out ${DESTDIR}${PREFIX}/bin/upx
	${INSTALL_MAN} ${WRKSRC}/doc/upx.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/upx.doc ${DESTDIR}${PREFIX}/share/doc/upx
	${INSTALL_DATA} ${WRKSRC}/doc/upx.html ${DESTDIR}${PREFIX}/share/doc/upx

.include "../../devel/ucl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
