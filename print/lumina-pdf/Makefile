# $NetBSD: Makefile,v 1.38 2024/11/14 22:21:24 wiz Exp $

DISTNAME=	lumina-pdf-1.6.0
PKGREVISION=	35
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=lumina-desktop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lumina-desktop/lumina-pdf/
COMMENT=	PDF viewer utility
LICENSE=	modified-bsd

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src-qt5

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake -o Makefile PREFIX=${PREFIX}

TOOL_DEPENDS+=		qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
