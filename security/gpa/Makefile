# $NetBSD: Makefile,v 1.74 2024/12/27 08:20:34 wiz Exp $

DISTNAME=	gpa-0.10.0
PKGREVISION=	15
CATEGORIES=	x11 security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpa/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	https://www.gnupg.org/related_software/gpa/
COMMENT=	GUI frontend to gnupg
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

LIBS+=			${BUILDLINK_LDADD.getopt}
LIBS.SunOS+=		-lnsl

CONFIGURE_ENV+=		ac_cv_path_GPG=${GPGME_GPG:Q}

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
