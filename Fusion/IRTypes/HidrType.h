/**
 * ███████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗
 * ██╔════╝██║   ██║██╔════╝██║██╔═══██╗████╗  ██║
 * █████╗  ██║   ██║███████╗██║██║   ██║██╔██╗ ██║
 * ██╔══╝  ██║   ██║╚════██║██║██║   ██║██║╚██╗██║
 * ██║     ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║
 * ╚═╝      ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝
 *
 * @file    HidrType.h
 * @brief   Definition of the HIDR intermediate representation.
 * @author     Ewerton23929dev
 *
 * @details
 * Describes the instruction node, operand types, operation sizes and the opcode
 * catalog. HIDR is the only representation the engine consumes: the user
 * assembles the node list in the order the code must be produced.
 * @copyright  Copyright (c) 2026 Ewerton23929dev. All rights reserved.
 */

#ifndef FUSION_HIDR_TYPE_H
#define FUSION_HIDR_TYPE_H

#include <stddef.h>
#include <stdint.h>

#include "HidrRegistre.h"

/*
 * @brief Hidr Opcode Types
*/
typedef enum {
    HIDR_INSTR_NONE = 0,

    HIDR_INSTR_MOV,
    HIDR_INSTR_ADD,
    HIDR_INSTR_RET,
    HIDR_INSTR_CALL,
    HIDR_INSTR_ADDR,
    HIDR_INSTR_PUSH,
    HIDR_INSTR_POP,
    HIDR_INSTR_SYSCALL,
    HIDR_INSTR_CMP
} FusHidrNodeKind_t;
/*
 * @brief Hidr Operand Types
*/
typedef enum {
    HIDR_OPERAND_TYPE_NONE = 0,

    HIDR_OPERAND_TYPE_REG,
    HIDR_OPERAND_TYPE_IMM,
    HIDR_OPERAND_TYPE_MEM_REF,
    HIDR_OPERAND_TYPE_SYM,
} FusHidrOperandType_t;

/*
 * @brief Hidr Imm Size Types
 * @note Future Remove
*/
typedef enum {
    HIDR_IMM_NONE = 0,

    HIDR_IMM8,
    HIDR_IMM16,
    HIDR_IMM32,
    HIDR_IMM64,
} FusHidrImmSize_t;
/*
 * @brief Hidr Imm Struct Type
*/
typedef struct {
    uint64_t imm;
    FusHidrImmSize_t size;
} FusHidrImm_t;
typedef struct {
    FusHidrRegistre base;
    uint16_t offset;
} FusHidrMemRef_t;
typedef struct {
    const char* name;
} FusHidrSysm_t;

/*
 * @brief Hidr Operand Struct Type
*/
typedef struct {
    FusHidrOperandType_t type;
    union {
        FusHidrRegistre reg;
        FusHidrMemRef_t memory_ref;
        FusHidrImm_t imm;
        FusHidrSysm_t sym;
    } data;
} FusHidrOperand_t;

typedef enum {
    HIDR_OP_SIZE_NONE = 0,
    HIDR_OP_SIZE_8,
    HIDR_OP_SIZE_16,
    HIDR_OP_SIZE_32,
    HIDR_OP_SIZE_64
} FusHidrOpcodeSize_t;

/*
 * @brief Hidr Node Struct
*/
typedef struct {
    FusHidrOpcodeSize_t op_size;

    FusHidrNodeKind_t opcode;
    FusHidrOperand_t src;
    FusHidrOperand_t dst;
} FusHidrNode_t;

static inline FusHidrOperand_t FUS_HIDR_Reg(char* registre_description)
{
    return (FusHidrOperand_t){
        .type = HIDR_OPERAND_TYPE_REG,
        .data.reg = fusInterpreterRegistre(registre_description)
    };
}

static inline FusHidrOperand_t FUS_HIDR_Sym(const char* sym_name)
{
    return (FusHidrOperand_t){
        .type = HIDR_OPERAND_TYPE_SYM,
        .data.sym.name = sym_name
    };
}

static inline FusHidrOperand_t FUS_HIDR_Mem(FusHidrRegistre base_reg, int offset)
{
    return (FusHidrOperand_t){
        .type = HIDR_OPERAND_TYPE_MEM_REF,
        .data.memory_ref = { .base = base_reg, .offset = offset }
    };
}

static inline FusHidrOperand_t FUS_HIDR_Imm(uint64_t imm, FusHidrImmSize_t size)
{
    return (FusHidrOperand_t){
        .type = HIDR_OPERAND_TYPE_IMM,
        .data.imm = {
            .imm  = imm,
            .size = size
        }
    };
}
#define FUS_HIDR_None() \
    (FusHidrOperand_t){ .type = HIDR_OPERAND_TYPE_NONE }

#endif