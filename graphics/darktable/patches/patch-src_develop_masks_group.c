$NetBSD$

--- src/develop/masks/group.c.orig	2023-02-15 16:52:33.000000000 +0000
+++ src/develop/masks/group.c
@@ -406,14 +406,10 @@ static void _combine_masks_union(float *
   if(inverted)
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
@@ -424,14 +420,10 @@ static void _combine_masks_union(float *
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
@@ -447,14 +439,10 @@ static void _combine_masks_intersect(flo
   if(inverted)
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
@@ -465,14 +453,10 @@ static void _combine_masks_intersect(flo
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
@@ -497,14 +481,10 @@ static void _combine_masks_difference(fl
   if(inverted)
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
@@ -515,14 +495,10 @@ static void _combine_masks_difference(fl
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
@@ -538,14 +514,10 @@ static void _combine_masks_exclusion(flo
   if(inverted)
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
@@ -559,14 +531,10 @@ static void _combine_masks_exclusion(flo
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
@@ -634,13 +602,9 @@ static int _group_get_mask_roi(const dt_
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
