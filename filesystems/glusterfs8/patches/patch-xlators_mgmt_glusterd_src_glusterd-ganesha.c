$NetBSD: patch-xlators_mgmt_glusterd_src_glusterd-ganesha.c,v 1.2 2024/08/06 21:10:48 riastradh Exp $

Avoid ctype(3) abuse.
https://github.com/gluster/glusterfs/issues/4397

--- xlators/mgmt/glusterd/src/glusterd-ganesha.c.orig	2020-09-16 18:40:32.450503707 +0000
+++ xlators/mgmt/glusterd/src/glusterd-ganesha.c
@@ -52,7 +52,7 @@ parsing_ganesha_ha_conf(const char *key)
         if (*pointer == '#') {
             continue;
         }
-        while (isblank(*pointer)) {
+        while (isblank((unsigned char)*pointer)) {
             pointer++;
         }
         if (strncmp(pointer, key, strlen(key))) {
@@ -80,7 +80,7 @@ parsing_ganesha_ha_conf(const char *key)
         do {
             end_pointer++;
         } while (!(*end_pointer == '\'' || *end_pointer == '"' ||
-                   isspace(*end_pointer) || *end_pointer == '\0'));
+                   isspace((unsigned char)*end_pointer) || *end_pointer == '\0'));
         *end_pointer = '\0';
 
         /* got it. copy it and return */
