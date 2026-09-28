/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_LargerBlocks.h
 * @brief   Large block allocator.
 * @author     Ewerton23929dev
 *
 * @details
 * Serves requests that do not fit in a slab slot, growing through larger blocks
 * kept in a list and returned to the pool when released.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_LARGER_BLOCKS_H
#define FUSION_INTERNAL_LARGER_BLOCKS_H
#include <Fusion/FusionTypes.h>

#include <stddef.h>

/**
 * @brief Contexto Type
 *  Opaque Larger Block Context
 */
typedef struct FusLargerBlock_T* FusLargerBlock_t;

/**
 * @brief Init Larger Bloc Context
 *
 * @warning Use start!
 * 
 * @param alloc 
 * @param ctx 
 * @param pool_size 
 * @return FusStatusFlag_t 
 */
FusStatusFlag_t fusiInitLargerBlocks(FusInstanceMyAllocation_t* alloc, FusLargerBlock_t* ctx ,size_t pool_size);
/**
 * @brief Close Larger Block Context
 * 
 * @warning Use for Destroy!
 *
 * @param alloc 
 * @param ctx 
 */
void fusiCloseLargerBlocks(FusInstanceMyAllocation_t* alloc, FusLargerBlock_t* ctx);

/**
 * @brief Alloc Block in Larger Block System
 * 
 * @param ctx 
 * @param size 
 * @return void* 
 */
void* fusiAllocLargerBlocks(FusLargerBlock_t* ctx,size_t size);
/**
 * @brief Free Larger Block
 * 
 * @param ctx 
 * @param ptr 
 */
void fusiFreeLargerBlocks(FusLargerBlock_t* ctx, void* ptr);

#endif // FUSION_INTERNAL_LARGER_BLOCKS_H