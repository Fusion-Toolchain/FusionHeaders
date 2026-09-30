/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    FusionBuffer.h
 * @brief   Public API for code buffers.
 * @author     Ewerton23929dev
 *
 * @details
 * Exposes buffer creation, retrieval of executable memory, writing the content
 * to an IO sink and buffer reuse across compilations.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_BUFFER_H
#define FUSION_BUFFER_H
#include "FusionTypes.h"
#include "IO/FusionGenericIO.h"

typedef struct {
    void* userdata;
    void* (*alloc)(void* userdata, size_t size);
    void  (*free)(void* userdata, void* ptr, size_t size);
} FusExecMemAllocator;
typedef struct FusBufferExecutable_T* FusBufferExecutable;

/*
 * @breif Create Buffer
 * @param FusBufferExecutable* out
 * @param size_t Buffer Size
 * @return FusBufferContext_t* Buffer Access
*/
FusStatusFlag_t fusCreateBufferExecutable(FusInstance instance, FusBufferExecutable* out, size_t buffer_size, FusExecMemAllocator* allocator);
FusStatusFlag_t fusMakeExecutable(FusBufferExecutable buffer);
FusStatusFlag_t fusGetExecutableController(FusBufferExecutable buffer, FusBufferController* controller);

FusStatusFlag_t fusBufferIOSink(FusBufferController* buffer, FusIOSink sink);
void fusReUsedBuffer(FusBufferExecutable buffer);
/*
 * @brief Destroy Buffer Access
*/
void fusDestroyBufferExecutable(FusInstance instance, FusBufferExecutable buffer);
#endif