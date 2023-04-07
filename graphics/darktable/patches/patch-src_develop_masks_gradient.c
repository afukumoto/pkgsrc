$NetBSD$

--- src/develop/masks/gradient.c.orig	2023-07-19 07:21:40.000000000 +0000
+++ src/develop/masks/gradient.c
@@ -1197,13 +1197,9 @@ static int _gradient_get_mask(const dt_i
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
@@ -1263,13 +1259,9 @@ static int _gradient_get_mask(const dt_i
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
@@ -1286,13 +1278,9 @@ static int _gradient_get_mask(const dt_i
 
 
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
@@ -1325,13 +1313,9 @@ static int _gradient_get_mask(const dt_i
 
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
@@ -1388,13 +1372,9 @@ static int _gradient_get_mask_roi(const 
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
@@ -1456,13 +1436,9 @@ static int _gradient_get_mask_roi(const 
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
@@ -1478,13 +1454,9 @@ static int _gradient_get_mask_roi(const 
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
@@ -1511,13 +1483,9 @@ static int _gradient_get_mask_roi(const 
 
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
