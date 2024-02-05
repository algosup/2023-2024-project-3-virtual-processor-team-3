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

enum BaseOpcode
{
    LOAD = 0B0000011,
    OP_IMM = 0B0010011,
    AUIPC = 0B0010111,
    STORE = 0B0100011,
    OP = 0B0110011,
    LUI = 0B0110111,
    BRANCH = 0B1100011,
    JALR = 0B1100111,
    JAL = 0B1101111,
    SYSTEM = 0B1110011,
};

enum Sections
{
    DATA, CODE
};

typedef struct 
{
    int *mem;
    int max_mem;

    int pc;
    int sp;
    int x[32];

    int section;

    unsigned int instruction;
    unsigned int func7;
    unsigned int func3;
    unsigned destination;
    unsigned int arg1;
    unsigned int arg2;
    int immediate;
} cpu_t;

#endif