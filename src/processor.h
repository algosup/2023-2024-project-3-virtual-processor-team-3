#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "cpu.h"
#include <ctype.h>

#define MAXMEM 1024
#define BITS 32

/**
 * This function executes the processing on a given grml file.
 * @param file (char pointer): A . grml file containing the binary of a .gras file.
 * @result Execute the instructions contained on a .grml file.
*/
int processing(char* file)
{
    
    FILE *binaryFile = fopen(file, "rb");
    if (!binaryFile)
    {
        errorsHandler(0, 0, " "); // File not found error
    }

    char line[BITS + 1];
    uint mem[MAXMEM];
    int count = 0;

    for (int i = 0; i < MAXMEM; i++)
    {
        mem[i] = 0;
    }

    while (fgets(line, sizeof(line), binaryFile)) {
        mem[count++] = (uint)strtoul(line, NULL, 2);
        if (count >= MAXMEM) {
            printf("Maximum number of numbers reached\n");
            break;
        }
    }

    fclose(binaryFile);

    cpu_t *cpu = new_cpu(mem, count);
    run_cpu(cpu);
    free_cpu(cpu);

    return 0;
}
#endif