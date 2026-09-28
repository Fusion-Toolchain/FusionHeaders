/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    HidrRegistre.h
 * @brief   Register name parsing.
 * @author     Ewerton23929dev
 *
 * @details
 * Converts a textual register name into the identifier used by the HIDR IR.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_HIDR_REGISTRE_H
#define FUSION_HIDR_REGISTRE_H
#include <stdint.h>

#define HIDR_REGISTRE_INVALID 0xFFFFFFFF
typedef uint32_t FusHidrRegistre;

FusHidrRegistre fusInterpreterRegistre(char* string);
#endif