# $NetBSD: Makefile,v 1.110 2024/12/31 17:33:16 adam Exp $

PKGNAME=	${APACHE_PKG_PREFIX}-subversion-${SVNVER}
COMMENT=	WebDAV server (Apache module) for Subversion

.include "../../devel/subversion/Makefile.common"

GNU_CONFIGURE_APXS2=	no
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--disable-mod-activation
CONFIGURE_ARGS+=	--with-apache-libexecdir

APACHE_MODULE=		YES

BUILD_TARGET=		apache-mod
INSTALL_TARGET=		install-mods-shared

CFLAGS.SunOS+=		-D__EXTENSIONS__

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
