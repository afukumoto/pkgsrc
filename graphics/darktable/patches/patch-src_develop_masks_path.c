$NetBSD$

--- src/develop/masks/path.c.orig	2021-02-03 13:36:49.000000000 +0000
+++ src/develop/masks/path.c
@@ -2835,13 +2835,9 @@ static int dt_path_get_mask_roi(dt_iop_m
       const int yymax = MIN(ymax, height - 1);
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(xxmin, xxmax, yymin, yymax, width) \
   shared(buffer)
-#else
-#pragma omp parallel for shared(buffer)
-#endif
 #endif
       for(int yy = yymin; yy <= yymax; yy++)
       {
@@ -2924,13 +2920,9 @@ static int dt_path_get_mask_roi(dt_iop_m
     }
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(width, height, dindex) \
   shared(buffer, dpoints)
-#else
-#pragma omp parallel for shared(buffer)
-#endif
 #endif
     for(int n = 0; n < dindex; n += 4)
       _path_falloff_roi(buffer, dpoints + n, dpoints + n + 2, width, height);
