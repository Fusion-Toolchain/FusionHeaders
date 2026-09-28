/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    Fus_HidrRegistre.h
 * @brief   Internal register mapping.
 * @author     Ewerton23929dev
 *
 * @details
 * Defines the register groups and the tables associating IR identifiers with
 * the physical registers of each architecture.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_INTERNAL_HIDR_REGISTRE_H
#define FUSION_INTERNAL_HIDR_REGISTRE_H
#include <Fusion/IRTypes/HidrType.h>

#include <stdint.h>
#include <stddef.h>

// ─── GROUP
#define HIDR_REGISTRE_GROUP_GP      0x0  // General Purpose
#define HIDR_REGISTRE_GROUP_FLOAT   0x1  // Ponto Flutuante
#define HIDR_REGISTRE_GROUP_SIMD    0x2  // SIMD / Vetorial
#define HIDR_REGISTRE_GROUP_CTRL    0x3  // Controle (PC, FLAGS, STATUS)
#define HIDR_REGISTRE_GROUP_SEG     0x4  // Segmento (x86)
#define HIDR_REGISTRE_GROUP_DEBUG   0x5  // Debug

// ─── ROLE
#define HIDR_REGISTRE_ROLE_ACC      0x0  // Acumulador
#define HIDR_REGISTRE_ROLE_BASE     0x1  // Base
#define HIDR_REGISTRE_ROLE_COUNTER  0x2  // Contador
#define HIDR_REGISTRE_ROLE_DATA     0x3  // Dado geral
#define HIDR_REGISTRE_ROLE_SP       0x4  // Stack Pointer
#define HIDR_REGISTRE_ROLE_BP       0x5  // Base Pointer
#define HIDR_REGISTRE_ROLE_SRC      0x6  // Source (origem)
#define HIDR_REGISTRE_ROLE_DST      0x7  // Destination (destino)
#define HIDR_REGISTRE_ROLE_LINK     0x8  // Link Register (ARM / RISC-V)
#define HIDR_REGISTRE_ROLE_RET      0x9  // Valor de retorno
#define HIDR_REGISTRE_ROLE_ARG      0xA  // Argumento de função
#define HIDR_REGISTRE_ROLE_TMP      0xB  // Temporário (caller-saved)

// ─── SIZE
#define HIDR_REGISTRE_SIZE_8        0x0  // 8 bits
#define HIDR_REGISTRE_SIZE_16       0x1  // 16 bits
#define HIDR_REGISTRE_SIZE_32       0x2  // 32 bits
#define HIDR_REGISTRE_SIZE_64       0x3  // 64 bits
#define HIDR_REGISTRE_SIZE_128      0x4  // 128 bits (SIMD)
#define HIDR_REGISTRE_SIZE_256      0x5  // 256 bits (AVX)
#define HIDR_REGISTRE_SIZE_512      0x6  // 512 bits (AVX-512)

// ─── FLAGS
#define HIDR_REGISTRE_FLAG_CALLER_SAVED  (1 << 0)  // Salvo pelo chamador
#define HIDR_REGISTRE_FLAG_CALLEE_SAVED  (1 << 1)  // Salvo pelo chamado
#define HIDR_REGISTRE_FLAG_VOLATILE      (1 << 2)  // Pode ser alterado a qualquer momento
#define HIDR_REGISTRE_FLAG_RESERVED      (1 << 3)  // Reservado pela ISA

typedef struct __attribute__((packed)) {
    uint8_t index  : 8;   // [07..00] 
    uint8_t flags  : 4;   // [11..08]
    uint8_t size   : 4;   // [15..12]
    uint8_t role   : 4;   // [19..16]
    uint8_t group  : 4;   // [23..20]
    uint8_t _pad   : 8;   // [31..24] reservado
} HidrRegDesc;
typedef union {
    HidrRegDesc desc;
    uint32_t      raw;
} HidrRegistre;
#define FUS_HIDR_REG_INTERNAL(reg) ((HidrRegistre){ .raw = (reg) })

HidrRegistre fusiConvertStringToRegistre(const char* registre);
void fusiRegistreToString(HidrRegistre reg, char* buf, size_t len);
#endif