# $NetBSD: buildlink3.mk,v 1.10 2024/11/14 22:20:44 wiz Exp $

BUILDLINK_TREE+=	akonadi-search

.if !defined(AKONADI_SEARCH_BUILDLINK3_MK)
AKONADI_SEARCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-search+=	akonadi-search>=17.12.1
BUILDLINK_ABI_DEPENDS.akonadi-search?=	akonadi-search>=23.08.4nb6
BUILDLINK_PKGSRCDIR.akonadi-search?=	../../misc/akonadi-search

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/krunner/buildlink3.mk"
.include "../../mail/akonadi-mime/buildlink3.mk"
.include "../../misc/kcontacts/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../time/kcalendarcore/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# AKONADI_SEARCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-search
