$NetBSD: patch-funcs_func__pjsip__aor.c,v 1.1 2024/04/08 03:20:08 jnemeth Exp $

--- funcs/func_pjsip_aor.c.orig	2018-06-20 14:41:48.304859278 +0000
+++ funcs/func_pjsip_aor.c
@@ -34,13 +34,14 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjlib.h>
-
 #include "asterisk/app.h"
 #include "asterisk/pbx.h"
 #include "asterisk/module.h"
 #include "asterisk/sorcery.h"
+
+#include <pjsip.h>
+#include <pjlib.h>
+
 #include "asterisk/res_pjsip.h"
 
 /*** DOCUMENTATION
