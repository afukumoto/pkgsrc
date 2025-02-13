# $NetBSD: Makefile,v 1.86 2024/12/27 08:20:25 wiz Exp $

DISTNAME=	pitivi-0.999
PKGREVISION=	22
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pitivi/0.999/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pitivi.org/
COMMENT=	Video editor using GStreamer/GTK
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config intltool msgfmt xgettext itstool

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-gstreamer1-[0-9]*:../../multimedia/py-gstreamer1
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

# For some reason creating projects fails without these.
DEPENDS+=	gst-plugins1-ogg-[0-9]*:../../multimedia/gst-plugins1-ogg
DEPENDS+=	gst-plugins1-theora-[0-9]*:../../multimedia/gst-plugins1-theora
DEPENDS+=	gst-plugins1-vorbis-[0-9]*:../../audio/gst-plugins1-vorbis

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_MESSAGE.py=	Setting the Python executable name.
SUBST_FILES.py+=	meson.build
SUBST_VARS.py+=		PYVERSSUFFIX

REPLACE_PYTHON+=	bin/pitivi.in

PY_PATCHPLIST=			yes

.include "../../devel/meson/build.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/gst-plugins1-gdk_pixbuf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../multimedia/frei0r/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../multimedia/gst-plugins1-editing-services/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../multimedia/gst-plugins1-gtk/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
