#include "cpu.h"

void testAddi(void);

int main(void)
{
    testAddi();

    return 0;
}

void testAddi(void){
    uint memAddi[] =
    {
        0B00000000100000100000000110010011, // addi x3, x4, 8
        //IIIIIIIIIIII11111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memAddi);
    cpu->x[4] = 4;
    run_cpu(cpu);
    printf("Addi: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}