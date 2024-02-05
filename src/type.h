#ifndef TYPE_H
#define TYPE_H

#define uint unsigned int

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
    // Memory
    uint *mem;
    int max_mem;

    // Registers
    int pc;
    int sp;
    int x[32];

    // alu
    uint instruction;
    uint func7;
    uint func3;
    uint destination;
    uint arg1;
    uint arg2;
    int immediate;
}cpu_t;

#endif