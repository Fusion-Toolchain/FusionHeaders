/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_Instance.h
 * @brief   Internal structure of the engine instance.
 * @author     Ewerton23929dev
 *
 * @details
 * Aggregates the user allocator, the handle table, the error tree and the memory
 * subsystems, so any internal module recovers the whole context from a single
 * pointer.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_INSTANCE_H
#define FUSION_INTERNAL_INSTANCE_H
#include <Fusion/FusionTypes.h>

// SUB-SYSTEM
#include <Internal/Fus_TraceTree.h>
#include <Internal/Memory/Fus_Handle.h>
#include <Internal/Memory/Fus_Slab.h>
#include <Internal/Memory/Fus_LargerBlocks.h>

struct FusInstance_T {
    FusInstanceMyAllocation_t* allocation;

    FusTable_t table;
    FusSlab_t* slab;
    FusLargerBlock_t larger_alloc;
    FusTraceTree trace;
};

#endif