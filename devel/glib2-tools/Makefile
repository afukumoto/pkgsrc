# $NetBSD: Makefile,v 1.14 2024/10/22 09:50:39 adam Exp $

.include "../../devel/glib2/Makefile.common"

PKGNAME:=	${PKGNAME:S/glib2/glib2-tools/}
CATEGORIES=	devel gnome

COMMENT=	GLib2/gobject python-dependent tools

DISTINFO_FILE=	${.CURDIR}/../../devel/glib2/distinfo
PATCHDIR=	${.CURDIR}/../../devel/glib2/patches

NO_BUILD=		yes

PYSCRIPTS=		glib-genmarshal glib-mkenums
INSTALLATION_DIRS=	bin

do-configure:
.for f in ${PYSCRIPTS}
	cd ${WRKSRC}/gobject \
	&& ${SED} \
		-e "s,/usr/bin/env ,," \
		-e "s,@PYTHON@,${PYTHONBIN}," \
		-e "s,@VERSION@,${PKGVERSION}," \
		${f}.in > ${f}
.endfor

do-install:
	cd ${WRKSRC}/gobject \
	&& ${INSTALL_SCRIPT} ${PYSCRIPTS} ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
