/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_Slab.h
 * @brief   Slab allocator.
 * @author     Ewerton23929dev
 *
 * @details
 * Splits memory into fixed size slots with a free list and, in debug builds,
 * usage markers. Backs the small and frequent objects of the engine.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_SLAB_H
#define FUSION_INTERNAL_SLAB_H
#include <Fusion/FusionTypes.h>

#include <stddef.h>

typedef struct FusSlab FusSlab_t;

FusSlab_t* fusiCreateSlab(
    FusInstanceMyAllocation_t* allocation,
    size_t initial_slots,
    size_t min_slots,
    size_t min_size,
    size_t max_size
);
void* fusiAllocSlab(FusSlab_t* ctx, size_t size);
void fusiFreeSlab(FusSlab_t* ctx, void* ptr);
void fusiSlabTrace(FusSlab_t* ctx);
void fusiDestroySlab(FusSlab_t* ctx);

#endif