$NetBSD$

--- src/common/utility.c.orig	2024-12-15 21:38:01.000000000 +0000
+++ src/common/utility.c
@@ -130,6 +130,16 @@ guint dt_util_str_occurence(const gchar 
 
 gchar *dt_util_float_to_str(const gchar *format, const double value)
 {
+#if defined(__NetBSD__)
+  locale_t nlocale;
+  int len;
+  gchar *txt;
+
+  nlocale = newlocale(LC_NUMERIC_MASK, "C", (locale_t) 0);
+  len = asprintf_l(&txt, nlocale, format, value);
+  freelocale(nlocale);
+  return txt;
+#else
 #if defined(WIN32)
   _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
   setlocale (LC_NUMERIC, "C");
@@ -147,6 +157,7 @@ gchar *dt_util_float_to_str(const gchar 
   freelocale(nlocale);
 #endif
   return txt;
+#endif
 }
 
 gchar *dt_util_str_replace(const gchar *string, const gchar *pattern, const gchar *substitute)
