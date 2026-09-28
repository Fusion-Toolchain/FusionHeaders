/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_StaticBackend.h
 * @brief   Static backend registration.
 * @author     Ewerton23929dev
 *
 * @details
 * REGISTER_BACKEND places a backend in the .static_modules_backend section so
 * the loader can find modules at link time without the user instantiating
 * them manually.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_STATIC_BACKEND_H
#define FUSION_INTERNAL_STATIC_BACKEND_H
#include "Fus_Backend.h"
#include <string.h>

typedef struct {
    const char* name;
    FusBackendInterfaceDefine_t fn;
} ModuleStaticEntry_t;

#define REGISTER_BACKEND(mod_name, mod_fn) \
    static const ModuleStaticEntry_t __entry_##mod_name \
    __attribute__((used, section(".static_modules_backend"), aligned(8))) = { \
        .name = #mod_name, \
        .fn   = mod_fn \
    };

static inline ModuleStaticEntry_t* fusiGetStaticBackend(const char* name)
{
    if (!name) return NULL;

    extern ModuleStaticEntry_t __start_static_modules_backend[];
    extern ModuleStaticEntry_t __stop_static_modules_backend[];

    if (&__start_static_modules_backend[0] >= &__stop_static_modules_backend[0])
        return NULL;

    for (ModuleStaticEntry_t* e = __start_static_modules_backend;
         e < __stop_static_modules_backend;
         e++)
    {
        if (!e->name) continue;

        if (strcmp(e->name, name) == 0)
            return e;
    }

    return NULL;
}

#endif