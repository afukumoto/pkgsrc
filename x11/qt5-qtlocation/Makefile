# $NetBSD: Makefile,v 1.75 2024/11/19 22:46:11 adam Exp $

DISTNAME=	qtlocation-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtlocation-${QTVERSION}
COMMENT=	Qt5 module for qtlocation

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Location.pc Qt5Positioning.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

PLIST_VARS+=		dbus
.include "../../x11/qt5-qtbase/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.qt5-qtbase:Mdbus}
PLIST.dbus=		yes
.endif

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
