# $NetBSD: Makefile,v 1.54 2024/09/06 18:48:53 bsiegert Exp $

DISTNAME=	terraform-provider-local-1.4.0
PKGREVISION=	51
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/local/
COMMENT=	Terraform provider for local resources
LICENSE=	mpl-2.0

DEPENDS+=	terraform-[0-9]*:../../net/terraform

UNLIMIT_RESOURCES=	datasize virtualsize

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/terraform-providers/${GITHUB_PROJECT}

GO_BUILD_PATTERN?=	${GO_SRCPATH}/.

USE_TOOLS+=	bash
REPLACE_BASH+=	scripts/*.sh

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
