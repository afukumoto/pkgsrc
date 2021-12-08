$NetBSD$

--- src/develop/masks/brush.c.orig	2021-02-03 13:36:49.000000000 +0000
+++ src/develop/masks/brush.c
@@ -2862,13 +2862,9 @@ static int dt_brush_get_mask_roi(dt_iop_
 
   // now we fill the falloff
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(nb_corner, border_count, width, height) \
   shared(buffer, points, border, payload)
-#else
-#pragma omp parallel for shared(buffer)
-#endif
 #endif
   for(int i = nb_corner * 3; i < border_count; i++)
   {
