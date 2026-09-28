/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    HidrHelper.h
 * @brief   Public API for building HIDR nodes.
 * @author     Ewerton23929dev
 *
 * @details
 * Exposes creation and destruction of the code mount point, node insertion and
 * the FUS_HIDRM macro, which allows writing a node in a readable form instead
 * of filling the structure by hand.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_PUBLIC_CODEMOUNT_H
#define FUSION_PUBLIC_CODEMOUNT_H
#include "../FusionTypes.h"
#include "HidrType.h"

FUS_DEFINE_HANDLE(FusCodeMount);

FUS_API FusStatusFlag_t fusCreateCodeMount(FusInstance* ctx, FusCodeMount* out);
FUS_API void fusDestroyCodeMount(FusInstance ctx, FusCodeMount code);

FUS_API FusStatusFlag_t fusInsertCodeBlock(struct FusCodeMount_T* mount, FusHidrNode_t node);

static inline FusHidrNode_t FUS_HIDRM(
    FusHidrNodeKind_t   op,
    FusHidrOpcodeSize_t size,
    FusHidrOperand_t    dst,
    FusHidrOperand_t    src)
{
    return (FusHidrNode_t){
        .opcode  = op,
        .op_size = size,
        .dst     = dst,
        .src     = src
    };
}

#define FUS_REG(r)      (FusHidrOperand_t){ .type = HIDR_OPERAND_TYPE_REG,     .data.reg = (r) }
#define FUS_IMM(v, s)   (FusHidrOperand_t){ .type = HIDR_OPERAND_TYPE_IMM,     .data.imm = { .imm = (v), .size = (s) } }
#define FUS_SYM(n)      (FusHidrOperand_t){ .type = HIDR_OPERAND_TYPE_SYM,     .data.sym.name = (n) }
#define FUS_MEM(b, o)   (FusHidrOperand_t){ .type = HIDR_OPERAND_TYPE_MEM_REF, .data.memory_ref = { .base = (b), .offset = (o) } }

#endif