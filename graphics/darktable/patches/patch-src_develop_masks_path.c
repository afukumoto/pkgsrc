$NetBSD$

--- src/develop/masks/path.c.orig	2023-06-14 16:45:40.000000000 +0000
+++ src/develop/masks/path.c
@@ -3299,13 +3299,9 @@ static int _path_get_mask_roi(const dt_i
       const int yymax = MIN(ymax, height - 1);
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(xxmin, xxmax, yymin, yymax, width) \
   shared(buffer) schedule(static) num_threads(MIN(8, dt_get_num_threads()))
-#else
-#pragma omp parallel for shared(buffer)
-#endif
 #endif
       for(int yy = yymin; yy <= yymax; yy++)
       {
@@ -3394,13 +3390,9 @@ static int _path_get_mask_roi(const dt_i
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
