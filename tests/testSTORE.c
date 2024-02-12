#include "../src/cpu.h"

void testSb(void);
void testSh(void);
void testSw(void);

int main(void)
{
    testSb();
    testSh();
    testSw();
}

void testSb(void)
{
    uint memSb[] =
    {
        0B00000000000100010001000000100011,
        //IIIIIII2222211111333IIIIIOOOOOOO
        0B00000000000000000000000000000000,
    };
    int maxmem = sizeof(memSb)/sizeof(memSb[0]);
    cpu_t *cpu = new_cpu(memSb, maxmem);
    cpu->x[1] = 5;
    cpu->x[2] = 4;
    run_cpu(cpu);
    printf("Sb : mem : %d\n", cpu->mem[1]);
    free_cpu(cpu);
}

void testSh(void)
{
    uint memSh[] =
    {
        0B00000000000100010010000000100011,
        //IIIIIII2222211111333IIIIIOOOOOOO
        0B00000000000000000000000000000000,
    };
    int maxmem = sizeof(memSh)/sizeof(memSh[0]);
    cpu_t *cpu = new_cpu(memSh, maxmem);
    cpu->x[1] = 1000;
    cpu->x[2] = 4;
    run_cpu(cpu);
    printf("Sh : mem : %d\n", cpu->mem[1]);
    free_cpu(cpu);
}

void testSw(void)
{
    uint memSw[] =
    {
        0B00000000000100010011000000100011,
        //IIIIIII2222211111333IIIIIOOOOOOO
        0B00000000000000000000000000000000,
    };
    int maxmem = sizeof(memSw)/sizeof(memSw[0]);
    cpu_t *cpu = new_cpu(memSw, maxmem);
    cpu->x[1] = 70000;
    cpu->x[2] = 4;
    run_cpu(cpu);
    printf("Sh : mem : %d\n", cpu->mem[1]);
    free_cpu(cpu);
}