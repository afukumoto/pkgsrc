$NetBSD$

--- src/common/darktable.h.orig	2023-02-15 16:52:33.000000000 +0000
+++ src/common/darktable.h
@@ -129,7 +129,12 @@ typedef unsigned int u_int;
 /* TL;DR : use only on SIMD functions containing low-level paralellized/vectorized loops */
 #if __has_attribute(target_clones) && !defined(_WIN32) && !defined(NATIVE_ARCH)
 # if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64)
+#ifdef __clang__
+/* https://github.com/llvm/llvm-project/issues/61219 */
+#define __DT_CLONE_TARGETS__
+#else
 #define __DT_CLONE_TARGETS__ __attribute__((target_clones("default", "sse2", "sse3", "sse4.1", "sse4.2", "popcnt", "avx", "avx2", "avx512f", "fma4")))
+#endif
 # elif defined(__PPC64__)
 /* __PPC64__ is the only macro tested for in is_supported_platform.h, other macros would fail there anyway. */
 #define __DT_CLONE_TARGETS__ __attribute__((target_clones("default","cpu=power9")))
