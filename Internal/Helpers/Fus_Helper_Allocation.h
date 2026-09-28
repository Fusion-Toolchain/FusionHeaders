/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_Helper_Allocation.h
 * @brief   Internal allocation helpers.
 * @author     Ewerton23929dev
 *
 * @details
 * Wraps the user allocation vtable in null checked inline functions so internal
 * code does not repeat the same verifications.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_HELPER_ALLOCATION_H
#define FUSION_INTERNAL_HELPER_ALLOCATION_H
#include <Internal/Fus_Instance.h>
#include <stddef.h>

static inline void* FUSIH_ALLOC(FusInstanceMyAllocation_t* alloc, size_t size)
{
    if (!alloc || size == 0) return NULL;
    return alloc->Alloc(alloc->userdata, size);
}
static inline void FUSIH_FREE(FusInstanceMyAllocation_t* alloc, void* ptr)
{
    if (!alloc || !ptr) return;
    alloc->Free(alloc->userdata,ptr);
}
static inline void* FUSIH_REALLOC(FusInstanceMyAllocation_t* alloc, void* ptr, size_t size)
{
    if (!alloc || !ptr || size == 0) return NULL;
    return alloc->Realloc(alloc->userdata,ptr,size); 
}

#endif