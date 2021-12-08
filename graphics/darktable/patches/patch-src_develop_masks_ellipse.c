$NetBSD$

--- src/develop/masks/ellipse.c.orig	2021-05-30 07:33:48.569157105 +0000
+++ src/develop/masks/ellipse.c
@@ -1768,13 +1768,9 @@ static int dt_ellipse_get_mask_roi(dt_io
   if(ell == NULL) return 0;
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(ellpts, center, ta, tb, cosa, sina) \
   shared(ell)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int n = 0; n < ellpts; n++)
   {
@@ -1850,13 +1846,9 @@ static int dt_ellipse_get_mask_roi(dt_io
 
   // we populate the grid points in module coordinates
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(grid, bbxm, bbym, bbXM, bbYM, bbw, iscale, px, py) \
   shared(points)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int j = bbym; j <= bbYM; j++)
     for(int i = bbxm; i <= bbXM; i++)
@@ -1887,13 +1879,9 @@ static int dt_ellipse_get_mask_roi(dt_io
   // we calculate the mask values at the transformed points;
   // for results: re-use the points array
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(bbh, bbw, center, alpha, a2, b2, ta2, tb2) \
   shared(points)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int j = 0; j < bbh; j++)
     for(int i = 0; i < bbw; i++)
@@ -1930,13 +1918,9 @@ static int dt_ellipse_get_mask_roi(dt_io
   const int endx = MIN(w, bbXM * grid);
   const int endy = MIN(h, bbYM * grid);
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(grid, bbxm, bbym, bbw, endx, endy, w) \
   shared(buffer, points)
-#else
-#pragma omp parallel for shared(buffer)
-#endif
 #endif
   for(int j = bbym * grid; j < endy; j++)
   {
