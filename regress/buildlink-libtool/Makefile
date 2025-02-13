# $NetBSD: Makefile,v 1.7 2024/11/24 08:34:45 rillig Exp $

DISTNAME=	regress-buildlink-libtool-0.0
CATEGORIES=	regress
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	test buildlink libtool

USE_LIBTOOL=	yes
NO_CONFIGURE=	yes
NO_INSTALL=	yes

# Remove GCC optimization options.
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*

# Convert "-lreadline" into "-ledit -ltermcap -lm".
BUILDLINK_TRANSFORM+=	l:readline:edit:termcap:m

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.PHONY: regress do-regress

regress: build do-regress

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
		ECHO} `${CAT} ${PASSED_TESTS} | ${WC} -l`;		\
	else								\
		${ECHO} "0";						\
	fi

TEST_RESULT=	${ECHO} "(${.TARGET}) got:      $$test";		\
		${ECHO} "(${.TARGET}) expected: $$expected";		\
		case $$test in						\
		$$expected)						\
			${ECHO} "(${.TARGET}) result:   PASS";		\
			${ECHO} "${.TARGET}" >> ${PASSED_TESTS};	\
			;;						\
		*)							\
			${ECHO} "(${.TARGET}) result:   FAIL";		\
			${ECHO} "${.TARGET}" >> ${FAILED_TESTS};	\
			;;						\
		esac

# Check that the dependency_libs line of libregress1.lai is empty.
do-regress: test1
test1:
	@cd ${WRKSRC};							\
	. .libs/libregress1.lai;					\
	test="$$dependency_libs";					\
	expected="";							\
	${TEST_RESULT}

# Check that libregress2.lai links with libregress1.lai.
do-regress: test2
test2:
	@cd ${WRKSRC};							\
	. .libs/libregress2.lai;					\
	test="$$dependency_libs";					\
	expected="${PREFIX}/lib/libregress1.la";			\
	${TEST_RESULT}

.include "../../mk/bsd.pkg.mk"
