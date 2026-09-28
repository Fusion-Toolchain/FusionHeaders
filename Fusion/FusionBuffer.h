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

/*
 * @breif Create Buffer
 * @param size_t Buffer Size
 * @return FusBufferContext_t* Buffer Access
*/
FusBufferContext_t* fusCreateBufferCode(FusInstance instance, size_t buffer_size);
FusStatusFlag_t fusExecutableBuffer(FusBufferContext_t* buffer);
FusStatusFlag_t fusBufferIOSink(FusBufferContext_t* buffer, FusIOSink sink);
void fusReUsedBuffer(FusBufferContext_t* buffer);
/*
 * @brief Destroy Buffer Access
*/
void fusDestroyBufferCode(FusInstance instance, FusBufferContext_t* buffer);

#endif