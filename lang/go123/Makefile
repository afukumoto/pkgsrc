# $NetBSD: Makefile,v 1.6 2025/01/02 19:53:12 bsiegert Exp $

PKGREVISION=	1
.include "../../lang/go/version.mk"
GO_BOOTSTRAP_REQD=	120
.include "../../lang/go/bootstrap.mk"

GOVERSSUFFIX=	123

DISTNAME=	go${GO${GOVERSSUFFIX}_VERSION}.src
PKGNAME=	go${GOVERSSUFFIX}-${GO${GOVERSSUFFIX}_VERSION}
CATEGORIES=	lang
MASTER_SITES=	https://storage.googleapis.com/golang/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://golang.org/
COMMENT=	The Go programming language
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/go
USE_TOOLS+=	bash:run perl:run pax

# Patch to stop requiring /proc to be mounted on NetBSD
PATCH_SITES=		https://github.com/golang/go/commit/
PATCHFILES=		80344887818a2321296ce7fa71cca8ca2520611d.diff
PATCH_DIST_STRIP=	-p1

# cgo compiles under TMPDIR
TMPDIR?=	/tmp
BUILDLINK_PASSTHRU_DIRS+= ${TMPDIR}

INSTALLATION_DIRS=	bin go${GOVERSSUFFIX}

REPLACE_BASH+=	lib/time/update.bash
REPLACE_BASH+=	misc/wasm/go_js_wasm_exec
REPLACE_BASH+=	misc/wasm/go_wasip1_wasm_exec
REPLACE_BASH+=	src/all.bash
REPLACE_BASH+=	src/bootstrap.bash
REPLACE_BASH+=	src/buildall.bash
REPLACE_BASH+=	src/clean.bash
REPLACE_BASH+=	src/cmd/compile/internal/ssa/_gen/cover.bash
REPLACE_BASH+=	src/cmd/vendor/golang.org/x/sys/plan9/mkall.sh
REPLACE_BASH+=	src/cmd/vendor/golang.org/x/sys/plan9/mkerrors.sh
REPLACE_BASH+=	src/cmd/vendor/golang.org/x/sys/unix/mkall.sh
REPLACE_BASH+=	src/cmd/vendor/golang.org/x/sys/unix/mkerrors.sh
REPLACE_BASH+=	src/cmd/vendor/golang.org/x/sys/windows/mkerrors.bash
REPLACE_BASH+=	src/cmd/vendor/golang.org/x/sys/windows/mkknownfolderids.bash
REPLACE_BASH+=	src/crypto/internal/boring/build.sh
REPLACE_BASH+=	src/crypto/internal/boring/build-boring.sh
REPLACE_BASH+=	src/crypto/internal/boring/build-goboring.sh
REPLACE_BASH+=	src/go/doc/comment/mkstd.sh
REPLACE_BASH+=	src/cmp.bash
REPLACE_BASH+=	src/make.bash
REPLACE_BASH+=	src/race.bash
REPLACE_BASH+=	src/run.bash
REPLACE_BASH+=	src/runtime/race/mkcgo.sh
REPLACE_BASH+=	src/syscall/mkall.sh
REPLACE_BASH+=	src/syscall/mkerrors.sh
REPLACE_BASH+=	src/syscall/mksysnum_plan9.sh

REPLACE_PERL+=	src/regexp/syntax/make_perl_groups.pl
REPLACE_PERL+=	src/syscall/*.pl

# uses own linker, which does not support relro on NetBSD
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/bin/go
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/bin/gofmt
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/pkg/bootstrap/bin/asm
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/pkg/bootstrap/bin/compile
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/pkg/bootstrap/bin/link
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/pkg/bootstrap/bin/cgo
# also does not support SSP at this time
CHECK_SSP_SKIP=			${CHECK_RELRO_SKIP}

# uses /bin/rc (for Plan 9)
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/include/plan9/mklibc.rc
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/all.rc
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/clean.rc
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/make.rc
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/run.rc

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/crypto/x509/root_solaris.go
SUBST_VARS.paths=	PKG_SYSCONFDIR

# Required until we bootstrap from a native illumos kit.  This is obviously
# terrible and should be fixed properly.
.if ${OPSYS} == "SunOS" && ${OS_VARIANT} != "Solaris"
SUBST_CLASSES+=		grplist
SUBST_STAGE.grplist=	pre-configure
SUBST_FILES.grplist=	src/os/user/getgrouplist_unix.go
SUBST_SED.grplist=	-e 's,return getgrouplist.*,return 0;,'
.endif

PLIST_SUBST+=	GOVERSSUFFIX=${GOVERSSUFFIX}

PRINT_PLIST_AWK+=	/^bin\/go${GOVERSSUFFIX}/ { print "bin/go$${GOVERSSUFFIX}"; next; }
PRINT_PLIST_AWK+=	/^bin\/gofmt${GOVERSSUFFIX}/ { print "bin/gofmt$${GOVERSSUFFIX}"; next; }

post-extract:
	${RM} -r -f ${WRKSRC}/test/fixedbugs/issue27836*

post-patch:
	${RM} -f ${WRKSRC}/src/os/*.orig_dist

do-build:
	cd ${WRKSRC}/src && \
		env \
		GOROOT_BOOTSTRAP=${GOROOT_BOOTSTRAP:Q} \
		${GOOPT} \
		GOCACHE=${WRKDIR}/.cache/go-build \
		${BASH} ./make.bash -v
# for RELRO build:
#	cd ${WRKSRC}/src && env GOROOT_BOOTSTRAP=${GOROOT_BOOTSTRAP:Q} GO_LDFLAGS="-buildmode=pie" ${GOOPT} ${BASH} ./make.bash

do-install:
	cd ${WRKSRC} && rm -rf pkg/obj pkg/bootstrap
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/go${GOVERSSUFFIX}
	find ${DESTDIR}${PREFIX}/go${GOVERSSUFFIX} -name \*.orig -exec rm {} \;
.for cmd in go gofmt
	${LN} -sf ${PREFIX}/go${GOVERSSUFFIX}/bin/${cmd} ${DESTDIR}${PREFIX}/bin/${cmd}${GOVERSSUFFIX}
.endfor

do-test:
	cd ${WRKSRC}/src && GOROOT=${WRKSRC} PATH=${WRKSRC}/bin:${PATH} ${GOOPT} ${BASH} run.bash --no-rebuild --banner ""

.include "../../mk/bsd.pkg.mk"
