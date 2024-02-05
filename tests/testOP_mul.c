#include "..\src\cpu.h"

void testMul(void);
void testMulh(void);
void testMulhu(void);
void testMulhsu(void);
void testDiv(void);
void testDivu(void);
void testRem(void);
void testRemu(void);

int main(void)
{
    testMul();
    testMulh();
    testMulhu();
    testMulhsu();
    testDiv();
    testDivu();
    testRem();
    testRemu();
    return 0;
}

void testMul(void)
{
    uint memMul[] =
    {
        0B00000010010100100000000110110011, // mul x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memMul, 1);
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
    cpu_t *cpu = new_cpu(memMulh, 1);
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
    cpu_t *cpu = new_cpu(memMulhu, 1);
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
    cpu_t *cpu = new_cpu(memMulhsu, 1);
    cpu->x[4] = -1048576;
    cpu->x[5] = 1048576;
    run_cpu(cpu);
    printf("Mulhsu: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testDiv(void)
{
    uint memDiv[] =
    {
        0B00000010010100100100000110110011, // div x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memDiv, 1);
    cpu->x[4] = -20;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("Div: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testDivu(void)
{
    uint memDivu[] =
    {
        0B00000010010100100101000110110011, // divu x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memDivu, 1);
    cpu->x[4] = 20;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("Divu: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testRem(void)
{
    uint memRem[] =
    {
        0B00000010010100100110000110110011, // rem x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memRem, 1);
    cpu->x[4] = 21;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("Rem: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testRemu(void)
{
    uint memRemu[] =
    {
        0B00000010010100100111000110110011, // remu x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memRemu, 1);
    cpu->x[4] = 21;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("Remu: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}