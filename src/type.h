#ifndef TYPE_H
#define TYPE_H

#define uint unsigned int
#define ull unsigned long long
#define ll long long
#define MAXMEM 1024
#define BITS 32

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

char *opcode[] = {
    // OP
    "add", "sub", "sll", "srl", "sra", "xor", "or", "and", "ilt?", "iltu?",
    // OP-IMM
    "addi", "slli", "srli", "xori", "ori", "andi", "ilti?", "iltiu?",
    // BRANCH
    "jie", "jine", "jige", "jigeu", "jile", "jileu",
    // LUI
    "lui",
    // AUIPC
    "auipc",
    // JAL
    "jal",
    // LOAD
    "lb", "lh", "lw", "lbu", "lhu",
    // STORE
    "sb", "sh", "sw",
    // SYSCALL
    "syscall",
    // OP-mul
    "mul", "mulh", "mulhsu", "mulhu", "div", "divu", "rem", "remu"
};