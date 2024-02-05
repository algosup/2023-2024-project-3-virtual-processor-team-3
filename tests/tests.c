#include "..\src\cpu.h"

void sumInt(void);

int main(void)
{
    sumInt();
    return 0;
}

void sumInt(void)
{
    uint mem[]=
    {
        0B00000000000100000000000010010011, // addi x1, x0, 1
        0B00000000101000000000000100010011, // addi x2, x0, 10
        0B00000000000100000000000110010011, // addi x3, x0, 1
        //
        0B00000000001000001000000010110011, // add x1, x1, x2
        0B01000000001100010000000100110011, // sub x2, x2, x3
        0B00000000001000011101011001100011, // jine x2, x3, 12
    };

    int maxmem = sizeof(mem)/sizeof(mem[0]);
    cpu_t *cpu = new_cpu(mem, maxmem);
    run_cpu(cpu);
    printf("Sum: x1: %d\n", cpu->x[1]);
    free_cpu(cpu);
}

// 12 = 0B 0 0 000000 0110 0