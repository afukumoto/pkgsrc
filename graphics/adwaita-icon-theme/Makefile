# $NetBSD: Makefile,v 1.28 2024/07/28 22:50:48 rillig Exp $

DISTNAME=		adwaita-icon-theme-40.1.1
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/adwaita-icon-theme/${PKGVERSION_NOREV:R:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Standard GNOME icons
LICENSE=		cc-by-sa-v3.0 OR gnu-lgpl-v3

GNU_CONFIGURE=		yes
GNU_CONFIGURE_ICONV=	no
USE_TOOLS+=		gmake pkg-config
# otherwise it creates lots of superfluous lib/locale dirs
USE_PKGLOCALEDIR=	yes
TOOLS_NOOP+=		gtk-update-icon-cache

CONFIGURE_ENV+=		ac_cv_path_GTK_ENCODE_SYMBOLIC_SVG="false"

PKGCONFIG_OVERRIDE+=	adwaita-icon-theme.pc.in

# should be created by the upstream installation Makefile targets,
# but isn't
INSTALLATION_DIRS+=	share/icons/Adwaita/96x96/places

ICON_THEMES=		yes

.include "../../mk/bsd.prefs.mk"

.for s in 96 256
PRINT_PLIST_AWK+=	{gsub("^share/icons/Adwaita/${s}x${s}/places/start-here.png","@comment this is in PLIST.NetBSD, do not add here: &");}
.endfor

post-install:
.if ${OPSYS} == "NetBSD"
.  for s in 16 22 24 32 48 96 256
	${INSTALL_DATA} ${FILESDIR}/netbsd-${s}.png \
	    ${DESTDIR}${PREFIX}/share/icons/Adwaita/${s}x${s}/places/start-here.png
.  endfor
.endif

BUILDLINK_DEPMETHOD.gettext-lib=        build
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
