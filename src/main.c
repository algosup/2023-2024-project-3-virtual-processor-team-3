#include "cpu.h"

int main(int argc, char **argv) 
{
    f64 memint[]=
    {
        ADDI, R1, 3,
        ADDI, R2, 4,
        ADD, R3, R2, R1,
        SUB, R4, R3, R2,
        MUL, R5, R3, R4,
        DIV, R6, R5, R4,
        PRT, R3,
        PRT, R4,
        PRT, R5,
        PRT, R6,
        SB, R6, 40,
        LB, R7, 40,
        PRT, R7,
        BREAK,
        0, 0, 0
    };

    // f64 memflt[]=
    // {
    //     LIF, F0, 4.25,
    //     LIF, F1, 5.33,
    //     ADDF, F2, F1, F0,
    //     SUBF, F3, F2, F1,
    //     MULF, F4, F2, F3,
    //     DIVF, F5, F4, F3,
    //     PRTF, F2,
    //     PRTF, F3,
    //     PRTF, F4,
    //     PRTF, F5,
    //     STF, 40, F5,
    //     LDF, F6, 40,
    //     PRTF, F6,
    //     STOP,
    //     0, 0, 0
    // };

    int memint_size = sizeof(memint) / sizeof(f64);
    // int memflt_size = sizeof(memflt) / sizeof(f64);

    cpu_t *cpu = new_cpu(memint, memint_size);

    run_cpu(cpu);

    cpu_free(cpu);

    return 0;
}