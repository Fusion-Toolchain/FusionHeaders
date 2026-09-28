/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_CodeBuffer.h
 * @brief   Internal structure of the code mount point.
 * @author     Ewerton23929dev
 *
 * @details
 * Holds the HIDR node list, its count, the reserved capacity and the owning
 * instance, so mounting and generation share the same buffer.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_PRIVATE_CODE_BUFFER_H
#define FUSION_PRIVATE_CODE_BUFFER_H
#include <Fusion/IRTypes/HidrHelper.h>

struct FusCodeMount_T {
    uint32_t code_count;
    uint32_t code_capacity;

    FusHidrNode_t* code_arry;
    struct FusInstance_T* ref_ctx;
};

#endif