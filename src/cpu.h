#ifndef CPU_H
#define CPU_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "type.h"

void fetch(cpu_t* cpu);
void execute(cpu_t* cpu);

void add(cpu_t *cpu);

cpu_t* new_cpu(int *mem)
{
    cpu_t* cpu = malloc(sizeof(cpu_t));
    cpu->mem = mem;
    cpu->max_mem = 4194304;
    cpu->pc = -1;
    cpu->sp = cpu->max_mem -1;
    for (int i = 0; i < 32; i++)
    {
        cpu->x[i] = 0;
    }
    cpu->x[4] = 2;
    cpu->x[5] = 5;

    return cpu;
}

void free_cpu(cpu_t* cpu)
{
    free(cpu);
}

void run_cpu(cpu_t* cpu)
{
    //while (cpu->mem < cpu->max_mem)  // TODO: change exit condition
    //{
    //    fetch(cpu);
    //    execute(cpu);
    //}

    fetch(cpu);
    execute(cpu);
}

void fetch(cpu_t* cpu)
{
    cpu->pc++;
    cpu->instruction = (cpu->mem[cpu->pc] << 25) >> 25;
}

void execute(cpu_t* cpu)
{
    switch(cpu->instruction)
    {
        case LOAD:
            break;
        case OP_IMM:
            break;
        case AUIPC:
            break;
        case STORE:
            break;
        case OP:
            cpu->func7 = cpu->mem[cpu->pc] >> 25;
            cpu->func3 = (cpu->mem[cpu->pc] << 17) >> 29;
            cpu->destination = (cpu->mem[cpu->pc] << 22) >> 27;
            cpu->arg1 = (cpu->mem[cpu->pc] << 12) >> 27;
            cpu->arg2 = (cpu->mem[cpu->pc] << 7) >> 27;
            if (cpu->func7 == 0 && cpu->func3 == 0)
            {
                add(cpu);
            }
            break;
        case LUI:
            break;
        case BRANCH:
            break;
        case JALR:
            break;
        case JAL:
            break;
        case SYSTEM:
            break;
        default:
            break;
    }
}

void add(cpu_t *cpu)
{
    cpu->x[cpu->destination] = cpu->x[cpu->arg1] + cpu->x[cpu->arg2];
}

#endif