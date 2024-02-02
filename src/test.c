#include "cpu.h"

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

    cpu_t *cpu = new_cpu(memsub);
    run_cpu(cpu);
    printf("x3: %d\n", cpu->x[3]);

    free_cpu(cpu);
    return 0;
}