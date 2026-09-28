/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_Linker.h
 * @brief   Internal structures of the linker.
 * @author     Ewerton23929dev
 *
 * @details
 * Joins symbols, relocation requests and the section table into a single link
 * context, exposing the operations used by the pipeline.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_LINKER_H
#define FUSION_INTERNAL_LINKER_H
#include <Fusion/Linker/FusionLinkerInterface.h>

#include <Internal/Backend/Fus_Backend.h>
#include <stddef.h>

#include "Fus_Hashtable.h"
#include "Fusion/FusionTypes.h"


typedef struct {
    FusLinkerContextSymbol_t* symbol;
    FusBackendRelocationOpaqueType_t type;

    size_t section_index;
    size_t offset;
} FusLinkerContextReloc_t;

struct FusLinkerContext_T {
    FusLinkerContextSection_t* sections;
    size_t sections_count;
    size_t sections_capacity;
    FusLinkerContextSymbol_t* symbols;
    size_t symbols_count;
    size_t symbols_capacity;
    FusLinkerContextReloc_t* realocs;
    size_t realocs_count;

    FdbHashTable_t* section_table;
    FdbHashTable_t* symbols_table;
    FusMemoryArena_t* arena;

    FusInstance inst_ref;
};

#endif