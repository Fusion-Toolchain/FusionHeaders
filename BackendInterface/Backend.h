/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Backend.h
 * @brief   Aggregated low level interface for backend implementers.
 * @author     Ewerton23929dev
 *
 * @details
 * Brings together the internal backend structures, the instance context and the
 * error tree, plus the inline FUSB_* helpers used for allocation, deallocation
 * and data block creation. Not intended for applications that only use the
 * public API.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef BACKEND_INTERFACE_SETS_H
#define BACKEND_INTERFACE_SETS_H
#include <Internal/Fus_Instance.h>
#include <Internal/Backend/Fus_Backend.h>
#include <Internal/Fus_TraceTree.h>

// HELPER
#include <Internal/Helpers/Fus_Helper_Codebase.h>

// TYPES
#include <stddef.h>
#include <string.h>

static inline void* FUSB_ALLOC(FusBackendApi_t* api, size_t size)
{
    if (unlikely(!api || size == 0)) return NULL;
    return api->FusAlloc(api,size);
}
static inline void FUSB_FREE(FusBackendApi_t* api, void* ptr)
{
    if (unlikely(!api || !ptr)) return;
    api->FusFree(api,ptr);
}
static inline FusBackendGenerateDataBlock_t* FUSB_CREATE_BLOCK(FusBackendApi_t* api,size_t need_realoc,size_t buffer_size)
{
    if (unlikely(!api || need_realoc == 0 || buffer_size == 0)) return NULL;
    return api->FusCreateDataBlock(api,need_realoc,buffer_size);
}
static inline void FUSB_DESTROY_BLOCK(FusBackendApi_t* api, FusBackendGenerateDataBlock_t* block)
{
    if (unlikely(!api || !block)) return;
    api->FusDestroyDataBlock(api,block);
}
static inline FusBackendTransferLifetime_t* FUSB_CREATE_TRASNFER(FusBackendApi_t* api,void* data,void (*free)(const void*))
{
    if (unlikely(!api || !data || !free)) return NULL;
    return api->FusCreateTransfer(api,data,free);
}
static inline void FUSB_DESTROY_TRASNFER(FusBackendApi_t* api, FusBackendTransferLifetime_t* lifetime)
{
    if (unlikely(!api || !lifetime)) return;
    api->FusDestroyTransfer(api,lifetime);
}
static inline FusStatusFlag_t FUSB_GET_TRACE_FUSION(FusBackendApi_t* api, FusTraceTree* tree_out)
{
    if (unlikely(!api)) return FUSION_ERRO;
    struct FusInstance_T* real_instance = api->Instance;
    if (!real_instance) return FUSION_ERRO;

    *tree_out = real_instance->trace;
    return FUSION_OK;
}
static inline FusStatusFlag_t FUSB_REGISTRE_REALOCATION(FusBackendApi_t* api,
    FusBackendGenerateDataBlock_t* block, const char* name, FusBackendRelocationOpaqueType_t type, size_t offset
)
{
    if (unlikely(!api)) return FUSION_ERRO;
    return api->FusRegistreRealocationDataBlock(api,block,name,type,offset);
}

#endif