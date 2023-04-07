$NetBSD$

--- src/develop/masks/group.c.orig	2023-06-14 16:45:40.000000000 +0000
+++ src/develop/masks/group.c
@@ -482,14 +482,10 @@ static void _combine_masks_union(float *
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
@@ -500,14 +496,10 @@ static void _combine_masks_union(float *
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
@@ -526,14 +518,10 @@ static void _combine_masks_intersect(flo
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
@@ -544,14 +532,10 @@ static void _combine_masks_intersect(flo
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
@@ -579,14 +563,10 @@ static void _combine_masks_difference(fl
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
@@ -597,14 +577,10 @@ static void _combine_masks_difference(fl
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
@@ -623,14 +599,10 @@ static void _combine_masks_sum(float *co
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
@@ -641,14 +613,10 @@ static void _combine_masks_sum(float *co
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
@@ -667,14 +635,10 @@ static void _combine_masks_exclusion(flo
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
@@ -689,14 +653,10 @@ static void _combine_masks_exclusion(flo
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
@@ -772,13 +732,9 @@ static int _group_get_mask_roi(const dt_
              // the shape and null other parts
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
