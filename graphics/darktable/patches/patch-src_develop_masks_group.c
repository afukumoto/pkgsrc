$NetBSD$

--- src/develop/masks/group.c.orig	2022-02-09 10:21:58.000000000 +0000
+++ src/develop/masks/group.c
@@ -407,14 +407,10 @@ static void _combine_masks_union(float *
   if (inverted)
   {
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for simd default(none) \
   dt_omp_firstprivate(npixels, opacity) \
   dt_omp_sharedconst(dest, newmask) aligned(dest, newmask : 64) \
   schedule(simd:static)
-#else
-#pragma omp parallel for shared(dest, newmask)
-#endif
 #endif
     for(int index = 0; index < npixels; index++)
     {
@@ -425,14 +421,10 @@ static void _combine_masks_union(float *
   else
   {
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for simd default(none) \
   dt_omp_firstprivate(npixels, opacity) \
   dt_omp_sharedconst(dest, newmask) aligned(dest, newmask : 64) \
   schedule(simd:static)
-#else
-#pragma omp parallel for shared(dest, newmask)
-#endif
 #endif
     for(int index = 0; index < npixels; index++)
     {
@@ -448,14 +440,10 @@ static void _combine_masks_intersect(flo
   if (inverted)
   {
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for simd default(none) \
   dt_omp_firstprivate(npixels, opacity) \
   dt_omp_sharedconst(dest, newmask) aligned(dest, newmask : 64) \
   schedule(simd:static)
-#else
-#pragma omp parallel for shared(dest, newmask)
-#endif
 #endif
     for(int index = 0; index < npixels; index++)
     {
@@ -466,14 +454,10 @@ static void _combine_masks_intersect(flo
   else
   {
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for simd default(none) \
   dt_omp_firstprivate(npixels, opacity) \
   dt_omp_sharedconst(dest, newmask) aligned(dest, newmask : 64) \
   schedule(simd:static)
-#else
-#pragma omp parallel for shared(dest, newmask)
-#endif
 #endif
     for(int index = 0; index < npixels; index++)
     {
@@ -498,14 +482,10 @@ static void _combine_masks_difference(fl
   if (inverted)
   {
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for simd default(none) \
   dt_omp_firstprivate(npixels, opacity) \
   dt_omp_sharedconst(dest, newmask) aligned(dest, newmask : 64) \
   schedule(simd:static)
-#else
-#pragma omp parallel for shared(dest, newmask)
-#endif
 #endif
     for(int index = 0; index < npixels; index++)
     {
@@ -516,14 +496,10 @@ static void _combine_masks_difference(fl
   else
   {
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for simd default(none) \
   dt_omp_firstprivate(npixels, opacity) \
   dt_omp_sharedconst(dest, newmask) aligned(dest, newmask : 64) \
   schedule(simd:static)
-#else
-#pragma omp parallel for shared(dest, newmask)
-#endif
 #endif
     for(int index = 0; index < npixels; index++)
     {
@@ -539,14 +515,10 @@ static void _combine_masks_exclusion(flo
   if (inverted)
   {
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for simd default(none) \
   dt_omp_firstprivate(npixels, opacity) \
   dt_omp_sharedconst(dest, newmask) aligned(dest, newmask : 64) \
   schedule(simd:static)
-#else
-#pragma omp parallel for shared(dest, newmask)
-#endif
 #endif
     for(int index = 0; index < npixels; index++)
     {
@@ -560,14 +532,10 @@ static void _combine_masks_exclusion(flo
   else
   {
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for simd default(none) \
   dt_omp_firstprivate(npixels, opacity) \
   dt_omp_sharedconst(dest, newmask) aligned(dest, newmask : 64) \
   schedule(simd:static)
-#else
-#pragma omp parallel for shared(dest, newmask)
-#endif
 #endif
     for(int index = 0; index < npixels; index++)
     {
@@ -635,13 +603,9 @@ static int _group_get_mask_roi(const dt_
         else // if we are here, this mean that we just have to copy the shape and null other parts
         {
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel for simd default(none) \
           dt_omp_firstprivate(npixels, op, inverted) \
           dt_omp_sharedconst(buffer, bufs) schedule(simd:static) aligned(buffer, bufs : 64)
-#else
-#pragma omp parallel for shared(bufs, buffer)
-#endif
 #endif
           for(int index = 0; index < npixels; index++)
           {
