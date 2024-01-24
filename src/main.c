#include "cpu.h"

int main(int argc, char **argv) 
{
    f64 mem[]=
    {
        LII, R0, 3,
        LII, R1, 4,
        ADD, R2, R1, R0,
        SUB, R3, R2, R1,
        MUL, R4, R2, R3,
        DIV, R5, R4, R3,
        PRT, R2,
        PRT, R3,
        PRT, R4,
        PRT, R5,
        LIF, F0, 4.25,
        LIF, F1, 5.33,
        ADDF, F2, F1, F0,
        SUBF, F3, F2, F1,
        MULF, F4, F2, F3,
        DIVF, F5, F4, F3,
        PRTF, F2,
        PRTF, F3,
        PRTF, F4,
        PRTF, F5,
    };

    int mem_size = sizeof(mem) / sizeof(f64) - 1;

    cpu_t *cpu = new_cpu(mem, mem_size);

    run_cpu(cpu);

    cpu_free(cpu);

    return 0;
}