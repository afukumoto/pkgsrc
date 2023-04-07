$NetBSD$

--- src/develop/masks/ellipse.c.orig	2023-02-15 16:52:33.000000000 +0000
+++ src/develop/masks/ellipse.c
@@ -1445,13 +1445,9 @@ static void _fill_mask(const size_t nump
   // be rotated, but we can compensate for that by applying a rotation matrix for the same rotation in the opposite
   // direction before projecting the vector.
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(numpoints, bufptr, points, center, alpha, a2, b2, ta2, tb2, cos_alpha, sin_alpha, out_scale) \
   schedule(static)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(size_t i = 0; i < numpoints; i++)
     {
@@ -1748,13 +1744,9 @@ static int _ellipse_get_mask_roi(const d
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
@@ -1835,13 +1827,9 @@ static int _ellipse_get_mask_roi(const d
 
   // we populate the grid points in module coordinates
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(grid, bbxm, bbym, bbXM, bbYM, bbw, iscale, px, py) \
   shared(points) schedule(static) collapse(2)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int j = bbym; j <= bbYM; j++)
     for(int i = bbxm; i <= bbXM; i++)
@@ -1888,13 +1876,9 @@ static int _ellipse_get_mask_roi(const d
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
