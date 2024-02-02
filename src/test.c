#include "cpu.h"

void testAdd(int* memAdd);
void testSub(int* memSub);
void testAnd(int* memAnd);


int main(void)
{
    int memadd[] =
    {
        0B00000000010100100000000110110011, // add x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO      
    };
    
    int memsub[]=
    {
        0B01000000010100100000000110110011, // sub x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO
    };

    int memand[]=
    {
        0B00000000010100100111000110110011, // and x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO
    };

    testAdd(memadd);
    testSub(memsub);
    testAnd(memand);

    return 0;
}

void testAdd(int* memAdd)
{
    cpu_t *cpu = new_cpu(memAdd);
    run_cpu(cpu);
    printf("x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testSub(int* memSub)
{
    cpu_t *cpu = new_cpu(memSub);
    run_cpu(cpu);
    printf("x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testAnd(int* memAnd)
{
    cpu_t *cpu = new_cpu(memAnd);
    run_cpu(cpu);
    printf("x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}