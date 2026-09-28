/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_TraceTree.h
 * @brief   Internal API of the trace tree.
 * @author     Ewerton23929dev
 *
 * @details
 * Declares the error context lifecycle and the FUS_PUSH_ERR macro, which
 * records file, line and message without repeating the status code by hand.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_TRACE_TREE_H
#define FUSION_INTERNAL_TRACE_TREE_H
#include <Fusion/FusionTypes.h>

#include <Fusion/FusionTrace.h> // PUBLIC

#include <stdint.h>

FusStatusFlag_t fusiCreateTraceContext(FusInstanceMyAllocation_t* allocator,FusTraceTree* out);
void fusiDestroyTraceContext(FusInstanceMyAllocation_t* allocator, FusTraceTree* tree_ctx);

#define FUS_PUSH_ERR(trace, code, msg) \
    fusPushError(trace, code, __FILE__, __LINE__, msg)

#define FUS_RETURN_ERR_VAL(trace, code, retval, msg) \
do { \
    FUS_PUSH_ERR(trace, code, msg); \
    return (retval); \
} while(0)

#define FUS_TRACE_AND_GOTO(trace, code, label, msg) \
do { \
    FUS_PUSH_ERR(trace, code, msg); \
    goto label; \
} while(0)

#define FUS_RETURN_ERR(trace, code, msg) \
    FUS_RETURN_ERR_VAL(trace, code, FUSION_ERRO, msg)

#endif