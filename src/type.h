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
    R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, RA, RB, RC, RD, RE, RF,
    F0, F1, F2, F3, F4, F5, F6, F7, F8, F9, FA, FB, FC, FD, FE, FF,
};

enum opcode
{
    LII, LIF,
    STI, STF, LDI, LDF,
    MOV, MOVF,
    ADD, SUB, MUL, DIV,
    ADDF, SUBF, MULF, DIVF,
    PRT, PRTF,
    PUSH, POP,
    PUSHF, POPF,
    STOP
};

typedef struct
{
    f64 *mem;
    i64 max_mem;

    i64 pc;
    i64 sp;
    i64 r[16];
    f64 fr[16];

    i64 inst;
    i64 dest;
    f64 arg1;
    i64 arg2;
} cpu_t;

#endif