#include "cpu.h"

void testAdd(void);
void testSub(void);
void testAnd(void);
void testOr(void);


int main(void)
{
    testAdd();
    testSub();
    testAnd();
    testOr();

    return 0;
}

void testAdd()
{
    uint memAdd[] =
    {
        0B00000000010100100000000110110011, // add x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memAdd);
    cpu->x[4] = 4;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testSub()
{
    uint memSub[]=
    {
        0B01000000010100100000000110110011, // sub x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO
    };
    cpu_t *cpu = new_cpu(memSub);
    cpu->x[4] = 4;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testAnd()
{
    uint memAnd[]=
    {
        0B00000000010100100111000110110011, // and x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO
    };
    cpu_t *cpu = new_cpu(memAnd);
    cpu->x[4] = 4;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testOr()
{
    uint memOr[]=
    {
        0B00000000010100100110000110110011, // or x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO
    };
    cpu_t *cpu = new_cpu(memOr);
    cpu->x[4] = 4;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}