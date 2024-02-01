#include "cpu.h"

int main(void)
{
    int mem[] =
    {
        0B00000000010000101000000110110011, // add x3, x4, x5
    };

    cpu_t *cpu = new_cpu(mem);
    run_cpu(cpu);
    printf("x3: %d\n", cpu->x[3]);

    free_cpu(cpu);
    return 0;
}