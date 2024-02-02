#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifndef TYPE_H
#define TYPE_H

#define byte unsigned char
#define u64 unsigned long long
#define i64 long long
#define f64 double

enum registers
{
    R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15,
    R16, R17, R18, R19, R20, R21, R22, R23, R24, R25, R26, R27, R28,
};

enum Opcode {
    ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, MUL, MULH, MULHU, MULHSU, DIV, DIVU, REM, REMU,
    ADDI, ANDI, ORI, XORI, SLLI, SRLI, SRAI, ILT, ILTI, ILTU, ILTUI, LB, LBU, LH, LHU, LW,
    JIE, JINE, JIGE, JIGEU, JILE, JILEU,
    JAL, JALR,
    LUI, AUIPC,
    SB, SH, SW,
    SYSCALL, BREAK, PRT
};

typedef struct
{
    f64 *mem;
    i64 max_mem;

    i64 pc;
    i64 sp;
    long r[16];
    f64 fr[16];

    int inst;
    i64 dest;
    f64 arg1;
    i64 arg2;
} cpu_t;

#endif