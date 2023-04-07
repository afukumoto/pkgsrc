$NetBSD$

--- src/develop/masks/circle.c.orig	2023-06-14 16:45:40.000000000 +0000
+++ src/develop/masks/circle.c
@@ -1275,13 +1275,9 @@ static int _circle_get_mask_roi(const dt
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
@@ -1381,14 +1377,10 @@ static int _circle_get_mask_roi(const dt
 
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
@@ -1425,14 +1417,10 @@ static int _circle_get_mask_roi(const dt
   // we calculate the mask values at the transformed points;
   // for results: re-use the points array
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(bbh, bbw, centerx, centery, border2, total2) \
   dt_omp_sharedconst(points) \
   schedule(static) collapse(2) if(bbh*bbw > 50000) num_threads(MIN(dt_get_num_threads(), (h*w)/20000))
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int j = 0; j < bbh; j++)
     for(int i = 0; i < bbw; i++)
@@ -1462,13 +1450,9 @@ static int _circle_get_mask_roi(const dt
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
