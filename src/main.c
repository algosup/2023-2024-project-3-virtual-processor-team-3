#include "cpu.h"

int main(int argc, char const *argv[])
{
    argv[1] = "out.bin";
    // if (argc < 2)
    // {
        // printf("Usage: %s <file>\n", argv[0]);
        // return 1;
    // }
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Error: File not found\n");
        return 1;
    }
    int i;
    uint mem[10];
    for (i = 0; i < 10; i++)
    {
        fscanf(file, "%d", &mem[i]);
    }
    fclose(file);
    cpu_t *cpu = new_cpu(mem, 10);
    run_cpu(cpu);
    printf("Result: %d\n", cpu->r[1]);
    free_cpu(cpu);
    return 0;
}
