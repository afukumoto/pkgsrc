$NetBSD$

--- src/develop/openmp_maths.h.orig	2024-12-15 21:38:01.000000000 +0000
+++ src/develop/openmp_maths.h
@@ -47,7 +47,7 @@ extern float sqrtf(const float x);
 DT_OMP_DECLARE_SIMD()
 extern float cbrtf(const float x);
 
-DT_OMP_DECLARE_SIMD()
+//DT_OMP_DECLARE_SIMD()
 extern float log2f(const float x);
 
 DT_OMP_DECLARE_SIMD()
