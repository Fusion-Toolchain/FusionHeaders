/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    FusionCompile.h
 * @brief   Public API of the engine compiler.
 * @author     Ewerton23929dev
 *
 * @details
 * Declares the entry point that walks a backend command chain, turns HIDR nodes
 * into bytes and returns the resulting buffer.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_COMPILE_H
#define FUSION_COMPILE_H
#include "FusionTypes.h"
#include "Backend/FusionBackend.h"
#include "FusionRule.h"

/*
 * @brief Mount Bytes Of Mir
 * @param FusBufferContext_t* Buffer Acess
 * @param FusMirNode_t* Mir Node
 * @return FusStatusFlag_t Build Flag
*/
FusStatusFlag_t fusMountHidrsBytes(FusInstance instance,FusCommandRuleBase_t* compiler_rule,FusBackendReturn* out);
FusBufferContext_t* fusGetStreamBufferCompiler(FusInstance instance, FusBackendReturn ctx_backend);
void fusDestroyBackendReturn(FusInstance instance, FusBackendReturn ctx_backend);

#endif