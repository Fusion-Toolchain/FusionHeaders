/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_Helper_Codebase.h
 * @brief   Shared language macros.
 * @author     Ewerton23929dev
 *
 * @details
 * Defines branch prediction hints, compiler attributes and asserts used across
 * the whole project, isolating differences between GCC, Clang and other
 * compilers.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_HELPER_CODEBASE_H
#define FUSION_INTERNAL_HELPER_CODEBASE_H

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)

#if defined(__GNUC__) || defined(__clang__)
    #define FUS_ATTR(...) __attribute__((__VA_ARGS__))

    #define ATTR_WARN_UNUSED     warn_unused_result
    #define ATTR_NONNULL(...)    nonnull(__VA_ARGS__)
    #define ATTR_MALLOC          malloc
    #define ATTR_INLINE          always_inline
#else
    #define FUS_ATTR(...)
    #define ATTR_WARN_UNUSED
    #define ATTR_NONNULL(...)
    #define ATTR_MALLOC
    #define ATTR_INLINE
#endif

#define FUS_UNUSED(x) (void)(x)

#endif