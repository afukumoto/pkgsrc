# $NetBSD: Makefile,v 1.12 2024/11/14 22:20:33 wiz Exp $

DISTNAME=	akonadi-import-wizard-${KAPPSVER}
PKGREVISION=	6
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Import data from other mail clients to KMail
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/mailcommon/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
