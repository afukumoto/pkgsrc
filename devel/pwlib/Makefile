# $NetBSD: Makefile,v 1.74 2024/12/22 12:57:17 nia Exp $

DISTNAME=	pwlib-v1_8_3-src
PKGNAME=	pwlib-1.8.3
PKGREVISION=	14
CATEGORIES=	devel
MASTER_SITES+=	http://www.voxgratia.org/releases/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/openh323/
COMMENT=	Portable Windows Library
# note: obsoleted by devel/ptlib

# Very fundamentally 32-bit only; fixing it would require a complete
# incompatible rework. That rework is (or is subsumed by) "ptlib".
NOT_FOR_PLATFORM+=	${LP64PLATFORMS}

# Depends on deprecated std::auto_ptr, etc
FORCE_CXX_STD+=		gnu++03

PKG_DESTDIR_SUPPORT=	destdir

WRKSRC=			${WRKDIR}/pwlib
USE_TOOLS+=		bison gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-sasl --disable-openldap
CONFIGURE_ARGS+=	--disable-expat --disable-video --disable-qos
PTHREAD_OPTS+=		require

BUILD_TARGET=		opt
MAKE_ENV+=		PWLIBDIR=${WRKSRC:Q} CC=${CC:Q} CPLUS=${CXX:Q}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	make/unix.mak make/lib.mak make/common.mak make/pwlib.mak
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	LIBTOOL
SUBST_SED.paths+=	-e 's,@BSD_INSTALL_LIB@,${INSTALL_LIB},g'
SUBST_SED.paths+=	-e 's,@BSD_INSTALL_PROGRAM@,${INSTALL_PROGRAM},g'
SUBST_SED.paths+=	-e 's,@PTHREAD_FLAGS@,${PTHREAD_LDFLAGS} ${PTHREAD_LIBS},g'
SUBST_VARS.paths+=	LIBOSSAUDIO
SUBST_STAGE.paths=	pre-configure

post-extract:
	mkdir ${WRKSRC}/share
	${LN} -s ../../pwlib ${WRKSRC}/share/pwlib

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

INSTALL_DIRS=	src/ptlib/unix

INSTALLATION_DIRS+=	bin lib

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pwlib/make
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/ptclib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/ptlib/unix/ptlib
	cd ${WRKSRC}/make; ${INSTALL_SCRIPT} ptlib-config ${DESTDIR}${PREFIX}/bin; \
	for f in *.mak; do		\
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/pwlib/make; \
	done
	${INSTALL_DATA} ${WRKSRC}/version.h ${DESTDIR}${PREFIX}/include/ptlib
	cd ${WRKSRC}; \
	for f in `${FIND} include -name CVS -prune -o -name \*.orig -prune -o -name wince -prune -o -name msos -prune -o -type f -print`; do	\
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/$$f;	\
	done

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
