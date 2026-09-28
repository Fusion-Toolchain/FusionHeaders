/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    FusionTypes.h
 * @brief   Base types, export macros and engine allocator.
 * @author     Ewerton23929dev
 *
 * @details
 * Centralizes the return status, the opaque handle macro, the symbol visibility
 * attribute and the allocation vtable the user fills in so the engine has no
 * allocator of its own.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_CORE_TYPES_H
#define FUSION_CORE_TYPES_H
#include <stddef.h>

#ifdef _WIN32
#define FUS_API __declspec(dllexport)
#else
#define FUS_API __attribute__((visibility("default")))
#endif

#define FUS_DEFINE_HANDLE(object) typedef struct object##_T* object;

typedef enum {
    FUSION_OK = 1,
    FUSION_ERRO = 0
} FusStatusFlag_t;
typedef struct {
    void* (*Alloc)(void*,size_t);
    void (*Free)(void*,void*);
    void* (*Realloc)(
        void* userdata,
        void* old_ptr,
        size_t new_size
    );

    void* userdata;
} FusInstanceMyAllocation_t;
typedef struct FusInstance_T* FusInstance;

typedef struct {
    unsigned char* buffer;
    size_t buffer_size;
    size_t offset;
} FusBufferContext_t;

#endif