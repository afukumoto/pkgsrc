# $NetBSD: Makefile,v 1.80 2024/12/27 08:20:33 wiz Exp $

DISTNAME=	zathura-pdf-poppler-0.3.3
PKGREVISION=	7
CATEGORIES=	print
MASTER_SITES=	https://pwmt.org/projects/zathura-pdf-poppler/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/zathura-pdf-poppler/
COMMENT=	Add PDF support to zathura using poppler rendering engine
LICENSE=	zlib

USE_TOOLS+=	pkg-config

USE_CC_FEATURES+=	c17

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../graphics/girara/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../print/zathura/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
