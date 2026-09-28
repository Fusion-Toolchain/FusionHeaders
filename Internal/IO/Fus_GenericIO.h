/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_GenericIO.h
 * @brief   Internal generic IO structures.
 * @author     Ewerton23929dev
 *
 * @details
 * Defines the write/flush/seek/close vtable and the sink context, so any
 * destination can be plugged in without touching the engine.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_IO_SYSTEM_H
#define FUSION_INTERNAL_IO_SYSTEM_H
#include <Fusion/FusionTypes.h>
#include <Fusion/IO/FusionGenericIO.h>

#include <stddef.h>

typedef struct {
    FusStatusFlag_t (*write)(void* ctx, const void* data, size_t size);
    FusStatusFlag_t (*flush)(void* ctx);
    FusStatusFlag_t (*seek)(void* ctx, size_t offset);
    void            (*close)(void* ctx);
} FusIOSinkInterfaceDefine;
struct FusIOSink_T {
    FusIOSinkInterfaceDefine interface;
    void*           ctx;
};

FusStatusFlag_t fusiIOCreateGenericIOSink(FusIOSink* out,FusIOSinkInterfaceDefine interface,void* ctx_data);
#endif