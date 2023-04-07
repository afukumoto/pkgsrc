$NetBSD$

--- src/develop/masks/brush.c.orig	2023-06-14 16:45:40.000000000 +0000
+++ src/develop/masks/brush.c
@@ -3205,13 +3205,9 @@ static int _brush_get_mask_roi(const dt_
 
   // now we fill the falloff
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(nb_corner, border_count, width, height) \
   shared(buffer, points, border, payload) schedule(static)
-#else
-#pragma omp parallel for shared(buffer)
-#endif
 #endif
   for(int i = _nb_ctrl_point(nb_corner); i < border_count; i++)
   {
