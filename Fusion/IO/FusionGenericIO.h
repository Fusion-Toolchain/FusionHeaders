/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    FusionGenericIO.h
 * @brief   Generic IO sink abstraction.
 * @author     Ewerton23929dev
 *
 * @details
 * Defines the opaque sink handle and its destruction, letting the user choose
 * the output destination (file, socket, memory).
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_GENERIC_IO_H
#define FUSION_GENERIC_IO_H

typedef struct FusIOSink_T* FusIOSink;
void fusDestroyIOSink(FusIOSink ctx);
#endif