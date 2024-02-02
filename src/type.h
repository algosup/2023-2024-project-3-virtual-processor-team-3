#ifndef TYPE_H
#define TYPE_H

enum InstructionFormat
{
    R,
    I,
    S,
    B,
    U,
    J,
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

enum Register
{
    x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, xA, xB, xC, xD, xE, xF,
    x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x1A, x1B, x1C, x1D, x1E, x1F,
};

typedef struct cpu
{
    int *mem;
    int max_mem;

    int pc;
    int sp;
    int x[32];

    unsigned int instruction;
    unsigned int func7;
    unsigned int func3;
    unsigned destination;
    unsigned int arg1;
    unsigned int arg2;
    int immediate;
}cpu_t;

#endif