# $NetBSD: Makefile,v 1.12 2024/11/14 22:20:53 wiz Exp $

DISTNAME=	pimcommon-${KAPPSVER}
PKGREVISION=	6
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Common libraries for KDE PIM
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

DEPENDS+=	kdesignerplugin-[0-9]*:../../x11/kdesignerplugin

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/purpose/buildlink3.mk"
.include "../../mail/kimap/buildlink3.mk"
.include "../../misc/libkdepim/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../textproc/kpimtextedit/buildlink3.mk"
.include "../../textproc/ktextaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
