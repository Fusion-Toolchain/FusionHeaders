/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    FusionFileIO.h
 * @brief   File backed IO sink.
 * @author     Ewerton23929dev
 *
 * @details
 * Creates a sink that writes the code buffer to a filesystem path.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_IO_FILE_H
#define FUSION_IO_FILE_H
#include <Fusion/FusionTypes.h>
#include "FusionGenericIO.h"

FUS_API FusStatusFlag_t fusIOFileSink(FusIOSink* out,const char* path);
#endif