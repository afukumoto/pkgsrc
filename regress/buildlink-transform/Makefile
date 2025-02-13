# $NetBSD: Makefile,v 1.24 2024/11/24 08:58:29 rillig Exp $
#
# Run many buildlink transform tests in a single regression test to avoid
# having to keep creating the wrapper scripts over and over again.
#
DISTNAME=	regress-buildlink-transform-0.0
CATEGORIES=	regress
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	test buildlink wrapper transformation

USE_CWRAPPERS=	no

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_INSTALL=	yes

# Remove GCC optimization options.
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*

# Remove /opt/schily.
.if ${LOCALBASE} != "/opt/schily"
BUILDLINK_TRANSFORM+=	rmdir:/opt/schily
.endif

# Convert "-lreadline" into "-ledit -ltermcap -lm".
BUILDLINK_TRANSFORM+=	l:readline:edit:termcap:m

REGRESS_ENV=		PATH=${PATH}
REGRESS_ENV+=		WRAPPER_DEBUG=yes

# Create a "regress" script in the wrapper directory that just echoes its
# arguments.
#
REGRESS=		${ECHO}
WRAPPEES+=		REGRESS
_WRAP_ALIASES.REGRESS=	regress

post-wrapper:
	@${RM} -f ${WRAPPER_BINDIR}/${REGRESS}

.PHONY: regress do-regress

regress: wrapper do-regress

FAILED_TESTS=	${WRKDIR}/failed
PASSED_TESTS=	${WRKDIR}/passed

do-regress:
	@if [ -f ${FAILED_TESTS} ]; then				\
		${ECHO} "FAILED:";					\
		${CAT} ${FAILED_TESTS} | while read test; do		\
			${ECHO} "	$$test";			\
		done;							\
		exit 1;							\
	fi

report-failed:
	@if [ -f "${FAILED_TESTS}" ]; then				\
		${ECHO} `${CAT} ${FAILED_TESTS} | ${WC} -l`;		\
	else								\
		${ECHO} "0";						\
	fi

report-passed:
	@if [ -f "${PASSED_TESTS}" ]; then				\
		${ECHO} `${CAT} ${PASSED_TESTS} | ${WC} -l`;		\
	else								\
		${ECHO} "0";						\
	fi

TEST_RESULT=	runtest=`${SETENV} ${REGRESS_ENV} regress $$test`;	\
		${ECHO} "(${.TARGET}) saw:      $$test";		\
		${ECHO} "(${.TARGET}) got:      $$runtest";		\
		${ECHO} "(${.TARGET}) expected: $$expected";		\
		case $$runtest in					\
		$$expected | "$$expected")				\
			${ECHO} "(${.TARGET}) result:   PASS";		\
			${ECHO} "${.TARGET}" >> ${PASSED_TESTS};	\
			;;						\
		*)							\
			${ECHO} "(${.TARGET}) result:   FAIL";		\
			${ECHO} "${.TARGET}" >> ${FAILED_TESTS};	\
			;;						\
		esac

TEST_DIR=	${.CURDIR}/tests

# If RUNTESTS is defined, then just run those tests, otherwise run them all.
.if defined(RUNTESTS)
.  for mkfile in ${RUNTESTS:@test@ ${TEST_DIR}/${test}.mk @}
.    include "${mkfile}"
.  endfor
.else
.  include "tests/include-pkgdir-slashdot.mk"
.  include "tests/include-pkgdir.mk"
.  include "tests/include-pkgsubdir.mk"
.  include "tests/include-usr-include-slashdot.mk"
.  include "tests/include-usr-include-subdir.mk"
.  include "tests/include-usr-include.mk"
.  include "tests/lib-expand.mk"
.  include "tests/libdir-pkgdir-slashdot.mk"
.  include "tests/libdir-pkgdir.mk"
.  include "tests/libdir-pkgsubdir.mk"
.  include "tests/libdir-usr-lib-slashdot.mk"
.  include "tests/libdir-usr-lib-subdir.mk"
.  include "tests/libdir-usr-lib.mk"
.  include "tests/libpath.mk"
.  include "tests/libpath-in-define.mk"
.  include "tests/no-abspath.mk"
.  include "tests/preserve-option.mk"
.  include "tests/quoted-arg.mk"
.  include "tests/remove-dir.mk"
.  include "tests/remove-option.mk"
.  include "tests/repeated-arg.mk"
.  include "tests/rpath-merge.mk"
.  include "tests/rpath-pkgdir-slashdot.mk"
.  include "tests/rpath-pkgdir.mk"
.  include "tests/rpath-pkgsubdir.mk"
.  include "tests/rpath-split.mk"
.  include "tests/rpath-usr-lib-slashdot.mk"
.  include "tests/rpath-usr-lib-subdir.mk"
.  include "tests/rpath-usr-lib.mk"
.  include "tests/libpath-shlib.mk"
.  include "tests/libpath-shmod.mk"
.endif

.include "../../mk/bsd.pkg.mk"
