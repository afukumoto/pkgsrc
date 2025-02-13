# $NetBSD: Makefile,v 1.81 2024/11/14 22:20:42 wiz Exp $

DISTNAME=	libqalculate-5.1.1
PKGNAME=	qalculate-5.1.1
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Qalculate/}
GITHUB_PROJECT=	libqalculate
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qalculate.github.io/
COMMENT=	Modern multi-purpose desktop calculator (console version)
LICENSE=	gnu-gpl-v2

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
FORCE_CXX_STD=		gnu++17
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf automake
USE_TOOLS+=		gmake intltool msgfmt msgmerge xgettext pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_prog_DOXYGEN=
PKGCONFIG_OVERRIDE=	libqalculate.pc.in

UNLIMIT_RESOURCES=	datasize

CFLAGS.SunOS+=		-D_LCONV_C99

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../devel/readline/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
