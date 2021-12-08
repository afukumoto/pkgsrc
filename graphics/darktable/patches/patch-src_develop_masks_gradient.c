$NetBSD$

--- src/develop/masks/gradient.c.orig	2021-02-03 13:36:49.000000000 +0000
+++ src/develop/masks/gradient.c
@@ -1108,13 +1108,9 @@ static int dt_gradient_get_mask(dt_iop_m
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
@@ -1165,13 +1161,9 @@ static int dt_gradient_get_mask(dt_iop_m
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
@@ -1185,13 +1177,9 @@ static int dt_gradient_get_mask(dt_iop_m
 
 
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
@@ -1223,13 +1211,9 @@ static int dt_gradient_get_mask(dt_iop_m
 
 // we fill the mask buffer by interpolation
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(h, w, gw, grid) \
   shared(buffer, points) schedule(static)
-#else
-#pragma omp parallel for shared(points, buffer)
-#endif
 #endif
   for(int j = 0; j < h; j++)
   {
@@ -1279,13 +1263,9 @@ static int dt_gradient_get_mask_roi(dt_i
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
@@ -1339,13 +1319,9 @@ static int dt_gradient_get_mask_roi(dt_i
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
@@ -1358,13 +1334,9 @@ static int dt_gradient_get_mask_roi(dt_i
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
@@ -1387,13 +1359,9 @@ static int dt_gradient_get_mask_roi(dt_i
 
 // we fill the mask buffer by interpolation
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) \
   dt_omp_firstprivate(h, w, grid, gw) \
   shared(buffer, points) schedule(static)
-#else
-#pragma omp parallel for shared(points, buffer)
-#endif
 #endif
   for(int j = 0; j < h; j++)
   {
