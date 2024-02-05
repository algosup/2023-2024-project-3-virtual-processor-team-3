#include "..\src\cpu.h"

void testAdd(void);
void testSub(void);
void testAnd(void);
void testOr(void);
void testXor(void);
void testSll(void);
void testSrl(void);
void testSra(void);
void testIlt(void);
void testIltu(void);

int main(void)
{
    testAdd();
    testSub();
    testAnd();
    testOr();
    testXor();
    testSll();
    testSrl();
    testSra();
    testIlt();
    testIltu();

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
    printf("Add: x3: %d\n", cpu->x[3]);
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
    printf("Sub: x3: %d\n", cpu->x[3]);
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
    printf("And: x3: %d\n", cpu->x[3]);
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
    printf("Or: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testXor()
{
    uint memOr[]=
    {
        0B00000000010100100100000110110011, // xor x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO
    };
    cpu_t *cpu = new_cpu(memOr);
    cpu->x[4] = 4;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("Xor: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testSll()
{
    uint memSll[]=
    {
        0B00000000010100100001000110110011, // sll x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO
    };
    cpu_t *cpu = new_cpu(memSll);
    cpu->x[4] = 8;
    cpu->x[5] = 2;
    run_cpu(cpu);
    printf("Sll: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testSrl()
{
    uint memSrl[]=
    {
        0B00000000010100100101000110110011, // srl x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO
    };
    cpu_t *cpu = new_cpu(memSrl);
    cpu->x[4] = 8;
    cpu->x[5] = 2;
    run_cpu(cpu);
    printf("Srl: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testSra()
{
    uint memSra[]=
    {
        0B01000000010100100101000110110011, // sra x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO
    };
    cpu_t *cpu = new_cpu(memSra);
    cpu->x[4] = -8;
    cpu->x[5] = 2;
    run_cpu(cpu);
    printf("Sra: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testIlt()
{
    uint memIlt[]=
    {
        0B00000000010100100010000110110011, // ilt x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO
    };
    cpu_t *cpu = new_cpu(memIlt);
    cpu->x[4] = 4;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("Ilt: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testIltu()
{
    uint memIltu[]=
    {
        0B00000000010100100011000110110011, // iltu x3, x4, x5
        //77777772222211111333DDDDDOOOOOOO
    };
    cpu_t *cpu = new_cpu(memIltu);
    cpu->x[4] = 4;
    cpu->x[5] = 5;
    run_cpu(cpu);
    printf("Iltu: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}