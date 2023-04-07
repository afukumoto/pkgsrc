$NetBSD$

--- src/develop/masks/path.c.orig	2023-02-15 16:52:33.000000000 +0000
+++ src/develop/masks/path.c
@@ -2878,13 +2878,9 @@ static int _path_get_mask_roi(const dt_i
       const int yymax = MIN(ymax, height - 1);
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(xxmin, xxmax, yymin, yymax, width) \
   shared(buffer) schedule(static) num_threads(MIN(8,darktable.num_openmp_threads))
-#else
-#pragma omp parallel for shared(buffer)
-#endif
 #endif
       for(int yy = yymin; yy <= yymax; yy++)
       {
@@ -2969,13 +2965,9 @@ static int _path_get_mask_roi(const dt_i
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
