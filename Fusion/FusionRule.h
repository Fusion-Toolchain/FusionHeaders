/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    FusionRule.h
 * @brief   Command chain of the compilation pipeline.
 * @author     Ewerton23929dev
 *
 * @details
 * Defines the command kinds (buffer, HIDR, backend, linker) and the rule
 * structure the user assembles to describe, step by step, how code must be
 * generated. The declared order is the executed order.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_PUBLIC_RULE_H
#define FUSION_PUBLIC_RULE_H
#include "Backend/FusionBackend.h"
#include "Fusion/IRTypes/HidrHelper.h"
#include "IRTypes/HidrType.h"
#include "FusionTypes.h"

#include <stddef.h>

typedef enum {
    FUS_COMMAND_SEND_BUFFER,
    FUS_COMMAND_SEND_HIDR,
    FUS_COMMAND_SEND_BACKEND,
    FUS_COMMAND_SEND_LINKER,
} FusCommandRuleType_t;
typedef struct FusCommandRuleBase {
    FusCommandRuleType_t       sType;
    struct FusRuleBase* pNext;
} FusCommandRuleBase_t;

typedef struct {
    FusCommandRuleType_t sType;
    const FusCommandRuleBase_t* pNext;

    FusBufferContext_t* buffer;
} FusCommandBuffer;
typedef struct {
    FusCommandRuleType_t sType;
    const FusCommandRuleBase_t* pNext;

    FusCodeMount code;
} FusCommandHidr;
typedef struct {
    FusCommandRuleType_t sType;
    const FusCommandRuleBase_t* pNext;

    FusModuleBackend backend;
} FusCommandBackend;
#endif