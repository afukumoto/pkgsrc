# $NetBSD: Makefile,v 1.24 2024/12/10 22:36:36 nia Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
COMMENT=	MariaDB 10.6, a free MySQL compatible database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DWITHOUT_SERVER=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_WSREP=OFF

INSTALL_DIRS+=	client include libmariadb man scripts

CMAKE_CONFIGURE_ARGS.NetBSD+=	-DTGOTOLIB=-ltermcap

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
