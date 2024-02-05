#include "..\src\cpu.h"

// 156 = 0B10011100 = 0 0 000100 1110 0;  

void testJie(void);
void testJine(void);
void testJige(void);
void testJigeu(void);
void testJile(void);
void testJileu(void);

int main (void)
{
    testJie();
    testJine();
    testJige();
    testJigeu();
    testJile();
    testJileu();
    return 0;
}

void testJie(void)
{
    uint memJle[] =
    {
        0B00001000010000011001111001100011, // jle x3, x4, 156
        //IIIIIII2222211111333IIIII0000000
    };
    cpu_t *cpu = new_cpu(memJle, 1);
    cpu->x[3] = 4;
    cpu->x[4] = 4;    
    run_cpu(cpu); 
    printf("Jle: pc: %d\n", cpu->pc);
    free_cpu(cpu);
}

void testJine(void)
{
    uint memJne[] =
    {
        0B00001000010000011101111001100011, // jne x3, x4, 156
        //IIIIIII2222211111333IIIII0000000
    };
    cpu_t *cpu = new_cpu(memJne, 1);
    cpu->x[3] = 4;
    cpu->x[4] = 5; 
    run_cpu(cpu);
    printf("Jne: pc: %d\n", cpu->pc);
    free_cpu(cpu);
}

void testJige(void)
{
    uint memJge[] =
    {
        0B00001000010000011011111001100011, // jge x3, x4, 156
        //IIIIIII2222211111333IIIII0000000
    };
    cpu_t *cpu = new_cpu(memJge, 1);
    cpu->x[3] = 5;
    cpu->x[4] = -4;
    run_cpu(cpu);
    printf("Jige: pc: %d\n", cpu->pc);
    free_cpu(cpu);
}

void testJigeu(void)
{
    uint memJgeu[] =
    {
        0B00001000010000011111111001100011, // jgeu x3, x4, 156
        //IIIIIII2222211111333IIIII0000000
    };
    cpu_t *cpu = new_cpu(memJgeu, 1);
    cpu->x[3] = 5;
    cpu->x[4] = 4;
    run_cpu(cpu);
    printf("Jigeu: pc: %d\n", cpu->pc);
    free_cpu(cpu);
}

void testJile(void)
{
    uint memJle[] =
    {
        0B00001000010000011010111001100011, // jle x3, x4, 156
        //IIIIIII2222211111333IIIII0000000
    };
    cpu_t *cpu = new_cpu(memJle, 1);
    cpu->x[3] = -4;
    cpu->x[4] = 4;
    run_cpu(cpu);
    printf("Jle: pc: %d\n", cpu->pc);
    free_cpu(cpu);
}

void testJileu(void)
{
    uint memJleu[] =
    {
        0B00001000010000011110111001100011, // jleu x3, x4, 156
        //IIIIIII2222211111333IIIII0000000
    };
    cpu_t *cpu = new_cpu(memJleu, 1);
    cpu->x[3] = 4;
    cpu->x[4] = 5;
    run_cpu(cpu);
    printf("Jleu: pc: %d\n", cpu->pc);
    free_cpu(cpu);
}