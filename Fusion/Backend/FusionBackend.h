/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    FusionBackend.h
 * @brief   Public API for loading backend modules.
 * @author     Ewerton23929dev
 *
 * @details
 * Defines the supported module kinds (static and dynamic) and the loading entry
 * point that binds a backend to an engine instance.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_BACKEND_MODULE_H
#define FUSION_BACKEND_MODULE_H
#include "../FusionTypes.h"

typedef enum {
    FUS_BACKEND_TYPE_NONE,
    FUS_BACKEND_TYPE_STATIC,
    FUS_BACKEND_TYPE_DINAMIC, // AINDA NAO EXISTE
} FusModuleBackendType_t;

FUS_DEFINE_HANDLE(FusModuleBackend)
FUS_DEFINE_HANDLE(FusBackendReturn)

FusStatusFlag_t fusLoaderBackend(FusInstance instance, FusModuleBackend* ctx,const char* name, FusModuleBackendType_t type);
void fusDestroyBackend(FusInstance instance, FusModuleBackend backend);
#endif