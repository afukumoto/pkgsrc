$NetBSD$

--- src/imageio/imageio_rawspeed.cc.orig	2023-07-19 07:21:40.000000000 +0000
+++ src/imageio/imageio_rawspeed.cc
@@ -29,6 +29,8 @@
 
 #define __STDC_LIMIT_MACROS
 
+using namespace std;
+
 #include "common/colorspaces.h"
 #include "common/darktable.h"
 #include "common/exif.h"
