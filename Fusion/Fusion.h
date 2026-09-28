/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fusion.h
 * @brief   Aggregating header for the public Fusion API.
 * @author     Ewerton23929dev
 *
 * @details
 * Collects IR, backend, linker, compile rules, IO and buffers into a single
 * include point, and exposes status code to string conversion.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERFACE_H
#define FUSION_INTERFACE_H

#include "IRTypes/HidrType.h"
#include "Backend/FusionBackend.h"
#include "Linker/FusionLinkerInterface.h"
#include "FusionRule.h"
#include "IRTypes/HidrHelper.h"
#include "IO/FusionGenericIO.h"
#include "FusionBuffer.h"
#include "FusionCompile.h"
#include "FusionInstance.h"

/*
 * @brief Status By String
 * @param FusStatusFlag_t Status Code
 * @return const char* String Error
*/
const char* fusStrError(FusStatusFlag_t status);

#endif