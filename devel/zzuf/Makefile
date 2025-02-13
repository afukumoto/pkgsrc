# $NetBSD: Makefile,v 1.11 2024/07/07 09:57:01 nia Exp $
#

DISTNAME=	zzuf-0.15
PKGREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	${MASTER_SITE_GITHUB:=samhocevar/zzuf/releases/download/v${DISTNAME:C:zzuf-::}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://caca.zoy.org/wiki/zzuf/
COMMENT=	Transparent application input fuzzer

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

# for alloca
FORCE_C_STD=	gnu99

# overrides read() definition
FORTIFY_SUPPORTED=	no

BUILDLINK_TRANSFORM+=	l:gnugetopt:getopt
SHLIBTOOL_OVERRIDE=	# empty
CONFIG_GUESS_OVERRIDE=	.auto/config.guess
CONFIG_SUB_OVERRIDE=	.auto/config.sub

SUBST_CLASSES+=			fix-paths
SUBST_FILES.fix-paths=		doc/libzzuf.3.in
SUBST_MESSAGE.fix-paths=	Fixing hard-coded pathnames
SUBST_SED.fix-paths=		-e 's,/usr,${PREFIX},g'
SUBST_STAGE.fix-paths=		pre-configure

.include "../../mk/bsd.fast.prefs.mk"

LIBS.NetBSD+=	${NETBSDLIB.rt}
###
### XXX Do this with autoconf?
###
.if ${OPSYS} == "NetBSD" && exists(/usr/include/aio.h)
.PHONY: netbsd-posix-aio-check
netbsd-posix-aio-check:
NETBSDLIB.rt!=								\
	if ( /sbin/sysctl -n kern.posix_aio >/dev/null 2>&1 ); then	\
	    lib=-lrt;							\
	fi || ${TRUE};							\
	echo "$$lib"
.endif

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -D__EXTENSIONS__

TEST_TARGET=	check

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
