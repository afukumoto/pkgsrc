$NetBSD$

--- src/imageio/format/exr.cc.orig	2023-02-15 16:52:33.000000000 +0000
+++ src/imageio/format/exr.cc
@@ -19,6 +19,8 @@
 // needs to be defined before any system header includes for control/conf.h to work in C++ code
 #define __STDC_FORMAT_MACROS
 
+using namespace std;
+
 #include <cstdio>
 #include <cstdlib>
 #include <memory>
