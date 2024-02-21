$NetBSD$

--- src/common/exif.cc.orig	2024-02-16 17:31:09.000000000 +0000
+++ src/common/exif.cc
@@ -42,6 +42,8 @@
 
 #include <exiv2/exiv2.hpp>
 
+using namespace std;
+
 #include "control/control.h"
 
 #if defined(_WIN32) && defined(EXV_UNICODE_PATH)
@@ -52,8 +54,6 @@
 
 #include <pugixml.hpp>
 
-using namespace std;
-
 #include "common/color_harmony.h"
 #include "common/colorlabels.h"
 #include "common/darktable.h"
