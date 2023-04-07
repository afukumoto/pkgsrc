$NetBSD$

--- src/develop/masks/gradient.c.orig	2023-12-14 19:44:41.000000000 +0000
+++ src/develop/masks/gradient.c
@@ -1172,13 +1172,9 @@ static int _gradient_get_mask(const dt_i
   if(points == NULL) return 0;
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(grid, gh, gw, px, py) \
   shared(points) schedule(static) collapse(2)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int j = 0; j < gh; j++)
     for(int i = 0; i < gw; i++)
@@ -1230,13 +1226,9 @@ static int _gradient_get_mask(const dt_i
   }
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(lutsize, lutmax, hwscale, state, normf, compression) \
   shared(lut) schedule(static)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int n = 0; n < lutsize; n++)
   {
@@ -1253,13 +1245,9 @@ static int _gradient_get_mask(const dt_i
 
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(gh, gw, sinv, cosv, xoffset, yoffset, hwscale, ihwscale, curvature, compression) \
   shared(points, clut) schedule(static) collapse(2)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int j = 0; j < gh; j++)
   {
@@ -1292,13 +1280,9 @@ static int _gradient_get_mask(const dt_i
 
 // we fill the mask buffer by interpolation
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(h, w, gw, grid, bufptr) \
   shared(points) schedule(simd:static)
-#else
-#pragma omp parallel for shared(points, buffer)
-#endif
 #endif
   for(int j = 0; j < h; j++)
   {
@@ -1355,13 +1339,9 @@ static int _gradient_get_mask_roi(const 
   if(points == NULL) return 0;
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(iscale, gh, gw, py, px, grid) \
   shared(points) schedule(static) collapse(2)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int j = 0; j < gh; j++)
     for(int i = 0; i < gw; i++)
@@ -1415,13 +1395,9 @@ static int _gradient_get_mask_roi(const 
   }
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(lutsize, lutmax, hwscale, state, normf, compression) \
   shared(lut) schedule(static)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int n = 0; n < lutsize; n++)
   {
@@ -1437,13 +1413,9 @@ static int _gradient_get_mask_roi(const 
   float *clut = lut + lutmax;
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(gh, gw, sinv, cosv, xoffset, yoffset, hwscale, ihwscale, curvature, compression) \
   shared(points, clut) schedule(static) collapse(2)
-#else
-#pragma omp parallel for shared(points)
-#endif
 #endif
   for(int j = 0; j < gh; j++)
   {
@@ -1470,13 +1442,9 @@ static int _gradient_get_mask_roi(const 
 
 // we fill the mask buffer by interpolation
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(h, w, grid, gw) \
   shared(buffer, points) schedule(simd:static)
-#else
-#pragma omp parallel for shared(points, buffer)
-#endif
 #endif
   for(int j = 0; j < h; j++)
   {
