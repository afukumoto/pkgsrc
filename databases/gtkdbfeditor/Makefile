# $NetBSD: Makefile,v 1.50 2024/12/27 08:19:29 wiz Exp $
#

DISTNAME=	gtkdbfeditor-1.0.4
PKGREVISION=	47
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkdbfeditor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sdteffen.de/gtkdbfeditor/
COMMENT=	Simple editor for DBF files (dBase, xBase)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt

.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
