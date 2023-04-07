$NetBSD$

--- src/develop/masks/circle.c.orig	2023-02-15 16:52:33.000000000 +0000
+++ src/develop/masks/circle.c
@@ -1129,13 +1129,9 @@ static int _circle_get_mask_roi(const dt
   if(circ == NULL) return 0;
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(circpts, centerx, centery, total) \
   dt_omp_sharedconst(circ) schedule(static) if(circpts/8 > 1000)
-#else
-#pragma omp parallel for shared(points) schedule(static)
-#endif
 #endif
   for(int n = 0; n < circpts / 8; n++)
   {
@@ -1229,14 +1225,10 @@ static int _circle_get_mask_roi(const dt
 
   // we populate the grid points in module coordinates
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(iscale, bbxm, bbym, bbXM, bbYM, bbw, px, py, grid) \
   dt_omp_sharedconst(points) \
   schedule(static) collapse(2) if(bbw*bbh > 50000)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int j = bbym; j <= bbYM; j++)
     for(int i = bbxm; i <= bbXM; i++)
@@ -1270,14 +1262,10 @@ static int _circle_get_mask_roi(const dt
   // we calculate the mask values at the transformed points;
   // for results: re-use the points array
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(bbh, bbw, centerx, centery, border2, total2) \
   dt_omp_sharedconst(points) \
   schedule(static) collapse(2) if(bbh*bbw > 50000) num_threads(MIN(darktable.num_openmp_threads,(h*w)/20000))
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int j = 0; j < bbh; j++)
     for(int i = 0; i < bbw; i++)
@@ -1304,13 +1292,9 @@ static int _circle_get_mask_roi(const dt
   const int endx = MIN(w, bbXM * grid);
   const int endy = MIN(h, bbYM * grid);
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(grid, bbxm, bbym, bbw, endx, endy, w) \
   dt_omp_sharedconst(buffer, points) schedule(static)
-#else
-#pragma omp parallel for shared(buffer)
-#endif
 #endif
   for(int j = bbym * grid; j < endy; j++)
   {
