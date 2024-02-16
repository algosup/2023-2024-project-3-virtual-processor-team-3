#include "cpu.h"
#include <ctype.h>

#define MAXMEM 1024
#define BITS 32

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Error: File not found\n");
        return 1;
    }

    char line[BITS + 1];
    uint mem[MAXMEM];
    int count = 0;

    for (int i = 0; i < MAXMEM; i++)
    {
        mem[i] = 0;
    }

    while (fgets(line, sizeof(line), file)) {
        mem[count++] = (uint)strtoul(line, NULL, 2);
        if (count >= MAXMEM) {
            printf("Maximum number of numbers reached\n");
            break;
        }
    }

    fclose(file);

    cpu_t *cpu = new_cpu(mem, count);
    run_cpu(cpu);
    printf("Result: %d\n", cpu->r[1]);
    free_cpu(cpu);

    return 0;
}