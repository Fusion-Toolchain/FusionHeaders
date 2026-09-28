/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_Helper_HidrHelper.h
 * @brief   Internal HIDR helpers for the core.
 * @author     Ewerton23929dev
 *
 * @details
 * FUSIH_ prefixed variant of the HIDR node accessors, used by the core so it
 * does not collide with the helpers exposed to the user.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_HIDR_HELPER_H
#define FUSION_INTERNAL_HIDR_HELPER_H

#include <Fusion/IRTypes/HidrType.h>

#include <stdbool.h>
#include <stdint.h>

// HELPERS

static inline FusHidrOperandType_t FUSIH_MirGetSrcType(const FusHidrNode_t* n) { return n->src.type; }
static inline FusHidrOperandType_t FUSIH_MirGetDstType(const FusHidrNode_t* n) { return n->dst.type; }

static inline FusHidrVirtualReg_t FUSIH_MirGetSrcReg(const FusHidrNode_t* n) { return n->src.data.reg; }
static inline FusHidrVirtualReg_t FUSIH_MirGetDstReg(const FusHidrNode_t* n) { return n->dst.data.reg; }

static inline int64_t  FUSIH_MirGetSrcImm(const FusHidrNode_t* n) { return n->src.data.imm.imm; }
static inline int64_t  FUSIH_FusMirGetDstImm(const FusHidrNode_t* n) { return n->dst.data.imm.imm; }

static inline FusHidrImmSize_t FUSIH_MirGetSrcImmSize(const FusHidrNode_t* n) { return n->src.data.imm.size; }
static inline FusHidrImmSize_t FUSIH_MirGetDstImmSize(const FusHidrNode_t* n) { return n->dst.data.imm.size; }

static inline FusHidrVirtualReg_t FUSIH_MirGetMemRefBase(const FusHidrNode_t* n, bool src)
{
    return src ? n->src.data.memory_ref.base : n->dst.data.memory_ref.base;
}

static inline int16_t FUSIH_MirGetMemRefOffset(const FusHidrNode_t* n, bool src)
{
    return src ? (int16_t)n->src.data.memory_ref.offset : (int16_t)n->dst.data.memory_ref.offset;
}

#endif