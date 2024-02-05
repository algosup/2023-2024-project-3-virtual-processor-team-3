#include "..\src\cpu.h"

void testMul(void);
void testMulh(void);
void testMulhu(void);
void testMulhsu(void);

int main(void)
{
    testMul();
    testMulh();
    testMulhu();
    testMulhsu();
    return 0;
}

void testMul(void)
{
    uint memMul[] =
    {
        0B00000010010100100000000110110011, // mul x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memMul);
    cpu->x[4] = 4;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("Mul: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testMulh(void)
{
    uint memMulh[] =
    {
        0B00000010010100100001000110110011, // mulh x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memMulh);
    cpu->x[4] = -1048576;
    cpu->x[5] = 1048576;
    run_cpu(cpu);
    printf("Mulh: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testMulhu(void)
{
    uint memMulhu[] =
    {
        0B00000010010100100011000110110011, // mulhu x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memMulhu);
    cpu->x[4] = 1048576;
    cpu->x[5] = 1048576;
    run_cpu(cpu);
    printf("Mulhu: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testMulhsu(void)
{
    uint memMulhsu[] =
    {
        0B00000010010100100010000110110011, // mulhsu x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memMulhsu);
    cpu->x[4] = -1048576;
    cpu->x[5] = 1048576;
    run_cpu(cpu);
    printf("Mulhsu: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}