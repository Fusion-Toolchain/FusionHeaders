/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    FusionInstance.h
 * @brief   Public API for the engine instance lifecycle.
 * @author     Ewerton23929dev
 *
 * @details
 * Declares creation and destruction of the instance, the single context that
 * aggregates the subsystems (trace, memory, tables) and the user supplied
 * allocator.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INSTANCE_H
#define FUSION_INSTANCE_H
#include "FusionTypes.h"

FusStatusFlag_t fusCreateInstance(FusInstance* ctx,FusInstanceMyAllocation_t* allocation);
FusStatusFlag_t fusDestroyInstance(FusInstance ctx);
#endif