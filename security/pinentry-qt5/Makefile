# $NetBSD: Makefile,v 1.22 2024/11/14 22:21:33 wiz Exp $

PKGNAME=	${DISTNAME:S/pinentry-/pinentry-qt5-/}
PKGREVISION=	4
COMMENT=	Applications for entering PINs or Passphrases, Qt5 enabled
CONFLICTS=	pinentry-qt4-[0-9]*

.include "../../security/pinentry/Makefile.common"

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config gmake autoconf
CONFIGURE_ARGS+=	--disable-libsecret
CONFIGURE_ARGS+=	--disable-pinentry-curses
CONFIGURE_ARGS+=	--disable-pinentry-emacs
CONFIGURE_ARGS+=	--disable-pinentry-efl
CONFIGURE_ARGS+=	--disable-pinentry-fltk
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-qt
CONFIGURE_ARGS+=	--enable-pinentry-qt5
CONFIGURE_ENV+=		MOC5="${QTDIR}/bin/moc"
CONFIGURE_ENV+=		RCC5="${QTDIR}/bin/rcc"

INSTALL_DIRS=		qt5

pre-configure:
	cd ${WRKSRC} && autoreconf -i -f

# XXX: conflicts with pinentry-qt6
post-install:
	${RM} ${DESTDIR}${PREFIX}/share/pixmaps/pinentry.png

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
