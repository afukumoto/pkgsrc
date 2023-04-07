$NetBSD$

--- src/imageio/imageio_exr.cc.orig	2023-12-14 19:44:41.000000000 +0000
+++ src/imageio/imageio_exr.cc
@@ -34,6 +34,8 @@
 #include <OpenEXR/ImfThreading.h>
 #include <OpenEXR/ImfTiledInputFile.h>
 
+using namespace std;
+
 #include "common/colorspaces.h"
 #include "common/darktable.h"
 #include "common/exif.h"
