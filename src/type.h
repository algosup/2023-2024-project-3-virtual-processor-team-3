#ifndef TYPE_H
#define TYPE_H

#define uint unsigned int
#define ull unsigned long long
#define ll long long

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

typedef struct cpu
{
    // Memory
    uint *mem;
    int max_mem;

    // Registers
    int pc;
    int sp;
    int r[32];

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