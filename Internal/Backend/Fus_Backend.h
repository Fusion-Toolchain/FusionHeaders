/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_Backend.h
 * @brief   Internal structures of the backend subsystem.
 * @author     Ewerton23929dev
 *
 * @details
 * Defines the API a backend must expose, the generation context, the data block
 * holding bytes and relocations, and the relocation request. This is the
 * contract between the core and the architecture encoder.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_BACKEND_H
#define FUSION_INTERNAL_BACKEND_H
#include <Internal/Memory/Fus_Arena.h>

#include <Fusion/IRTypes/HidrType.h>
#include <Fusion/Backend/FusionBackend.h>
#include <Fusion/FusionTypes.h>

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Relocation Request Context
 *
 * Issued by the Core to the backend when a relocation entry must be resolved.
 * The backend is solely responsible for interpreting the relocation type and
 * applying the appropriate patch to the target buffer.
 */
typedef struct {
    uint8_t*  buffer;       // Target byte buffer to patch
    size_t    offset;       // Patch offset within the buffer
    uint64_t  sym_addr;     // Resolved address of the referenced symbol
    uint64_t  patch_addr;   // Absolute address of the patch site (required for REL32)
} FusBackendRelocContext_t;

/**
 * @brief Opaque Relocation Type
 *
 * An opaque type whose semantics are defined exclusively by the backend.
 * The Core treats this value as an opaque identifier and forwards it
 * unmodified during relocation resolution.
 *
 * @warning Do not interpret or modify without knowledge of the backend's relocation model.
 */
typedef uint32_t FusBackendRelocationOpaqueType_t;

/**
 * @brief Pending Relocation Entry
 *
 * Recorded by the backend during code generation to indicate a symbol reference
 * that requires future resolution by the Core linker.
 */
typedef struct {
    const char*                      name;
    FusBackendRelocationOpaqueType_t type;
    size_t                           offset;
} FusBackendRelocationNeed_t;

/**
 * @brief Transfer Lifetime Handle
 *
 * Wraps data crossing the backend-Core boundary with an explicit ownership contract.
 * The Core invokes the provided destructor when the transfer is no longer needed,
 * allowing the backend to manage its own memory strategy internally.
 */
typedef struct {
    const void* data;
    void (*free)(const void* data);
} FusBackendTransferLifetime_t;

typedef struct FusBackendGenerateDataBlock FusBackendGenerateDataBlock_t; // forward ref

/**
 * @brief Core Dependency Injection API
 *
 * Injected by the Core into the backend at mount time. Provides the backend
 * with access to Core-managed allocation, data block creation, and transfer
 * lifetime management — without exposing Core internals.
 *
 * The backend must not retain pointers beyond the lifetime of the owning module.
 */
typedef struct FusBackendApi {
    void* (*FusAlloc)(struct FusBackendApi*, size_t);
    void  (*FusFree)(struct FusBackendApi*, void*);
    FusBackendTransferLifetime_t* (*FusCreateTransfer)(
        struct FusBackendApi*, void* data, void (*free)(const void* data)
    );
    void (*FusDestroyTransfer)(
        struct FusBackendApi*, FusBackendTransferLifetime_t*
    );
    FusBackendGenerateDataBlock_t* (*FusCreateDataBlock)(struct FusBackendApi*, size_t, size_t);
    void (*FusDestroyDataBlock)(struct FusBackendApi*, FusBackendGenerateDataBlock_t*);
    FusStatusFlag_t (*FusRegistreRealocationDataBlock)(struct FusBackendApi* api, 
        FusBackendGenerateDataBlock_t* block, const char* name, FusBackendRelocationOpaqueType_t type, size_t offset);
    FusInstance Instance;
} FusBackendApi_t;

/**
 * @brief Generated Code Block
 *
 * Produced by the backend during a generation pass. Contains the emitted byte
 * stream, an associated arena for auxiliary allocations, and a table of pending
 * relocations to be resolved by the Core linker.
 */
typedef struct FusBackendGenerateDataBlock {
    uint8_t*                         buffer_slab;
    size_t                           slab_size;
    size_t                           slab_offset;
    FusMemoryArena_t*                arena;
    FusBackendRelocationNeed_t*       reloc;
    size_t                           reloc_count;
    size_t                           reloc_capacity;
    FusStatusFlag_t                  flag;
    FusBackendApi_t*                 api;
} FusBackendGenerateDataBlock_t;

/**
 * @brief Backend Interface Contract
 *
 * The minimal set of operations a backend must expose to the Core.
 * Defines the fundamental backend capabilities: code generation and relocation resolution.
 */
typedef struct {
    FusBackendTransferLifetime_t* (*FUSI_BackendMountHidrArray)(FusBackendApi_t*, const FusHidrNode_t*, size_t);
    FusStatusFlag_t               (*FUSI_BackendLinkerRelocation)(FusBackendApi_t*, FusBackendRelocationOpaqueType_t, FusBackendRelocContext_t*);
} FusBackendInterface_t;

/**
 * @brief Backend Return Value
 *
 * Standardized return structure from a backend operation.
 * Carries the generated transfer data alongside the API handle
 * required for its lifetime management.
 */
struct FusBackendReturn_T {
    FusBackendTransferLifetime_t* transfer_data;
    FusBackendApi_t*              api;
};

/**
 * @brief Backend Module Descriptor
 *
 * Internal representation of a mounted backend module.
 * Holds the backend's identity, its interface contract, and the
 * API instance allocated for its exclusive use.
 */
typedef struct {
    void* handle;
    FusBackendInterface_t* interface;
} FusBackendDynamic;
struct FusModuleBackend_T {
    FusModuleBackendType_t  type;
    FusBackendDynamic dynamic_save;
    const char*             name;
    FusBackendInterface_t*  interface;
    FusBackendApi_t*        api;
};

/**
 * @brief Backend Entry Point Signature
 *
 * Expected symbol signature for dynamically loaded backends.
 * The backend receives the injected API and returns its interface contract.
 * This is the sole required export of any Fusion-compatible backend module.
 */
typedef FusBackendInterface_t* (*FusBackendInterfaceDefine_t)();

#endif