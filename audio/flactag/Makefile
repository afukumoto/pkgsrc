# $NetBSD: Makefile,v 1.44 2025/01/06 21:49:01 ktnb Exp $
#

DISTNAME=	flactag-2.0.4
PKGREVISION=	29
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flactag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://software.gently.org.uk/flactag-1.1/
COMMENT=	Tagger for flac album files
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pkg-config
GNU_CONFIGURE=	yes

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# "ripflag" doesn't work well, "discid" pollutes the namespace
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flactag ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flactag.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libdiscid/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../textproc/unac/buildlink3.mk"
.include "../../audio/libmusicbrainz5/buildlink3.mk"
.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
