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
            cpu->func3 = (cpu->mem[cpu->pc] << 17) >> 29;
            cpu->destination = (cpu->mem[cpu->pc] << 20) >> 27;
            cpu->arg1 = (cpu->mem[cpu->pc] << 12) >> 27;
            cpu->immediate = ((int)cpu->mem[cpu->pc] >> 20);
            if (cpu->func3 == 0) // addi
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] + cpu->immediate;
            }
            else if (cpu->func3 == 0B111) // andi
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] & cpu->immediate;    
            }
            else if (cpu->func3 == 0B110) // ori
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] | cpu->immediate;
            }
            else if (cpu->func3 == 0B100) // xori
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] ^ cpu->immediate;
            }
            else if (cpu->func3 == 0B001) // slli
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] << cpu->immediate;
            }
            else if (cpu->func3 == 0B101) // srli
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] >> cpu->immediate;
            }
            // else if (cpu->func3 == 0B101) // srai
            // {
                // cpu->x[cpu->destination] = cpu->x[cpu->arg1] >> cpu->immediate;
            // }
            else if (cpu->func3 == 0B010) // ilti?
            {
                cpu->x[cpu->destination] = (cpu->x[cpu->arg1] < cpu->immediate)? 1: 0;
            }
            else if (cpu->func3 == 0B011) // iltiu?
            {
                cpu->x[cpu->destination] = (cpu->x[cpu->arg1] < (unsigned int)cpu->immediate)? 1: 0;
            }
            break;
        case AUIPC:
            break;
        case STORE:
            break;
        case OP:
            cpu->func7 = cpu->mem[cpu->pc] >> 25;
            cpu->func3 = (cpu->mem[cpu->pc] << 17) >> 29;
            cpu->destination = (cpu->mem[cpu->pc] << 20) >> 27;
            cpu->arg1 = (cpu->mem[cpu->pc] << 12) >> 27;
            cpu->arg2 = (cpu->mem[cpu->pc] << 7) >> 27;
            if (cpu->func7 == 0 && cpu->func3 == 0)  // add
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] + cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0B100000 && cpu->func3 == 0) // sub
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] - cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B111) // and
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] & cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B110) // or
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] | cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B100) // xor
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] ^ cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B001) // sll
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] << cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B101) // srl
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] >> cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0B0100000 && cpu->func3 == 0B101) // sra
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] >> cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B010) //ilt?
            {
                cpu->x[cpu->destination] = (cpu->x[cpu->arg1] < cpu->x[cpu->arg2])? 1: 0;
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B011) //iltu?
            {
                cpu->x[cpu->destination] = (cpu->x[cpu->arg1] < (unsigned int)cpu->x[cpu->arg2])? 1: 0;
            }
            break;
        case LUI:
            break;
        case BRANCH:
            cpu->func3 = (cpu->mem[cpu->pc] << 17) >> 29;
            cpu->arg1 = (cpu->mem[cpu->pc] << 12) >> 27;
            cpu->arg2 = (cpu->mem[cpu->pc] << 7) >> 27;
            cpu->immediate = ((cpu->mem[cpu->pc] << 20) >> 28)*2 + ((cpu->mem[cpu->pc] << 1) >> 26)*32 + ((cpu->mem[cpu->pc] << 24) >> 31)*2048 + (cpu->mem[cpu->pc] >> 31)*4096;
            if (cpu->func3 == 1) // jie
            {
                if (cpu->x[cpu->arg1] == cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
            }
            else if (cpu->func3 == 0B101) // jine
            {
                if (cpu->x[cpu->arg1] != cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
            }
            else if (cpu->func3 == 0B011) // jige
            {
                if (cpu->x[cpu->arg1] >= cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
            }
            else if (cpu->func3 == 0B111) //jigeu
            {
                if ((uint)cpu->x[cpu->arg1] >= (uint)cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
            }
            else if (cpu->func3 == 0B10) // jile
            {
                if (cpu->x[cpu->arg1] <= cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
            }
            else if (cpu->func3 == 0B110) // jileu
            {
                if ((uint)cpu->x[cpu->arg1] <= (uint)cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
            }
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

#endif