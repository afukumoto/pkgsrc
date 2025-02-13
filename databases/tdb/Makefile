# $NetBSD: Makefile,v 1.57 2024/12/06 09:23:16 nros Exp $

DISTNAME=	tdb-1.4.12
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://www.samba.org/ftp/tdb/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tdb.samba.org/
COMMENT=	Small database system which uses files to store data
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

# both install tdbtool and tdbdump
CONFLICTS+=	samba<3.6.6nb3

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--abi-check-disable
CONFIGURE_ARGS+=	--disable-symbol-versions
.if defined(MAKE_JOBS) && !empty(MAKE_JOBS) && !(defined(MAKE_JOBS_SAFE) && ${MAKE_JOBS_SAFE:U:tl} == no)
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS}
.else
CONFIGURE_ARGS+=	--jobs=1
.endif
PKGCONFIG_OVERRIDE=	tdb.pc.in
TEST_TARGET=		test

USE_GCC_RUNTIME=	yes

PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	buildtools/bin/waf
MAKE_FLAGS+=		WAF_BINARY=${PYTHONBIN}\ ${WRKSRC}/buildtools/bin/waf

SUBST_CLASSES+=		docbook
SUBST_MESSAGE.docbook=	Fixing docbook URLs.
SUBST_FILES.docbook+=	buildtools/wafsamba/samba_conftests.py
SUBST_FILES.docbook+=	buildtools/wafsamba/wafsamba.py
SUBST_STAGE.docbook=	pre-configure
SUBST_SED.docbook+=	-e 's,http://docbook.sourceforge.net/release/xsl/current,${PREFIX}/share/xsl/docbook,g'

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
