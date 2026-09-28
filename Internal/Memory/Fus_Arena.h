/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_Arena.h
 * @brief   Arena allocator.
 * @author     Ewerton23929dev
 *
 * @details
 * Reserves one contiguous block and serves sequential allocations by offset,
 * with no per object free cost. Used for structures that die together.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_ARENA_H
#define FUSION_INTERNAL_ARENA_H
#include <stddef.h>

/*
 * @brief Struct Arena Fusion
*/
typedef struct {
    void* data;
    size_t size;
    size_t offset;
} FusMemoryArena_t;

/*
 * @brief Create Arena
 * @param size_t Request Size
 * @return FusMemoryArena_t* Arena Access
*/
FusMemoryArena_t* fusiCreateArena(size_t size);
/*
 * @brief Alloc Item in Arena
 * @param FusMemoryArena_t* Arena Access
 * @param size_t Item Size
 * @return void* Data
*/
void* fusiAllocArena(FusMemoryArena_t* arena, size_t size);
/*
 * @brief Clear/Reset Arena
 * @param FusMemoryArena_t* Arena
*/
char* fusiArenaPushString(FusMemoryArena_t* arena, const char* str);
//char* fusiArenaPrintf(FusMemoryArena_t* arena, const char* fmt, ...);
void fusiResetArena(FusMemoryArena_t* arena);
/*
 * @brief Destroy Arena
 * @param FusMemoryArena_t* Arena Access
*/
void fusiDestroyArena(FusMemoryArena_t* arena);

#endif