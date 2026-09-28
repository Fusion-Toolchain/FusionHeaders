/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    FusionTrace.h
 * @brief   Public API of the error tree.
 * @author     Ewerton23929dev
 *
 * @details
 * Allows pushing errors with file and line, clearing the tree and dumping it as
 * text for diagnostics.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_PUBLIC_TRACE_TREE_H
#define FUSION_PUBLIC_TRACE_TREE_H
#include <Fusion/FusionTypes.h>
#include <stdint.h>

typedef struct FusTraceTree_T* FusTraceTree;

FusStatusFlag_t fusPushError(
    FusTraceTree tree_ctx, FusStatusFlag_t code,
    const char* file, uint32_t line, const char* message
);
void fusClearErrors(FusTraceTree tree_ctx);
void fusDumpTrace(FusTraceTree tree_ctx);

FusStatusFlag_t fusInstanceGetTrace(FusInstance instance, FusTraceTree* out);

#endif