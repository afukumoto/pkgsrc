# $NetBSD: Makefile,v 1.38 2024/11/16 12:04:13 wiz Exp $

DISTNAME=		File-BaseDir-0.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/File-BaseDir
COMMENT=		Perl module for the XDG Base Directory Specification
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-IPC-System-Simple-[0-9]*:../../devel/p5-IPC-System-Simple
# for make test
TOOL_DEPENDS+=		xdg-user-dirs-[0-9]*:../../x11/xdg-user-dirs
TOOL_DEPENDS+=		p5-File-Which-[0-9]*:../../devel/p5-File-Which

SHAREDIR=		${PREFIX}/share
SHAREDIR_SPLIT=		${SHAREDIR:S/\// /g}
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	lib/File/BaseDir.pm t/01_vars.t t/03_OO.t
SUBST_VARS.paths=	SHAREDIR_SPLIT

PERL5_PACKLIST=		auto/File/BaseDir/.packlist

pre-test:
	${MKDIR} ${WRKDIR}/.home/.config/user-dirs.dirs

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
