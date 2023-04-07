$NetBSD$

--- src/iop/demosaicing/amaze.cc.orig	2023-06-14 16:45:40.000000000 +0000
+++ src/iop/demosaicing/amaze.cc
@@ -24,6 +24,8 @@
 #include <cstdlib>
 #include <cstring>
 
+using namespace std;
+
 #include "develop/imageop.h"
 #include "develop/imageop_math.h"
 #include "common/math.h"
