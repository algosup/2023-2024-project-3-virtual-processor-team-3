#include "../src/cpu.h"

void testLb(void);
void testLh(void);
void testLw(void);
void testLbu(void);
void testLhu(void);

int main(void)
{
    testLb();
    testLh();
    testLw();
    testLbu();
    testLhu();
}

void testLb(void)
{
    uint memLb[] = 
    {
        0B00000000000000010000000010000011, // lb r1, 0(x2)
        //IIIIIIIIIIII11111333DDDDD0000000
        0B00000000000000000000000010111111,
    };
    int maxmem = sizeof(memLb)/sizeof(memLb[0]);
    cpu_t *cpu = new_cpu(memLb, maxmem);
    cpu->r[2] = 4;
    run_cpu(cpu);
    printf("lb : x1 : %d\n", cpu->r[1]);
    free_cpu(cpu);
}

void testLh(void)
{
    uint memLh[] = 
    {
        0B00000000000000010001000010000011, // lh r1, 0(x2)
        0B00000000000000001011111111111111,
    };
    int maxmem = sizeof(memLh)/sizeof(memLh[0]);
    cpu_t *cpu = new_cpu(memLh, maxmem);
    cpu->r[2] = 4;
    run_cpu(cpu);
    printf("lh : x1 : %d\n", cpu->r[1]);
    free_cpu(cpu);
}

void testLw(void)
{
    uint memLw[] = 
    {
        0B00000000000000010010000010000011, // lw r1, 0(x2)
        //IIIIIIIIIIII11111333DDDDD0000000
        0B00000000100000001011111111111111,
    };
    int maxmem = sizeof(memLw)/sizeof(memLw[0]);
    cpu_t *cpu = new_cpu(memLw, maxmem);
    cpu->r[2] = 4;
    run_cpu(cpu);
    printf("lw : x1 : %d\n", cpu->r[1]);
    free_cpu(cpu);
}

void testLbu(void)
{
    uint memLbu[] = 
    {
        0B00000000000000010011000010000011, // lb r1, 0(x2)
        //IIIIIIIIIIII11111333DDDDD0000000
        0B00000000000000000000000010111111,
    };
    int maxmem = sizeof(memLbu)/sizeof(memLbu[0]);
    cpu_t *cpu = new_cpu(memLbu, maxmem);
    cpu->r[2] = 4;
    run_cpu(cpu);
    printf("lbu : x1 : %d\n", cpu->r[1]);
    free_cpu(cpu);
}

void testLhu(void)
{
    uint memLhu[] = 
    {
        0B00000000000000010100000010000011, // lh r1, 0(x2)
        0B00000000000000001011111111111111,
    };
    int maxmem = sizeof(memLhu)/sizeof(memLhu[0]);
    cpu_t *cpu = new_cpu(memLhu, maxmem);
    cpu->r[2] = 4;
    run_cpu(cpu);
    printf("lh : x1 : %d\n", cpu->r[1]);
    free_cpu(cpu);
}