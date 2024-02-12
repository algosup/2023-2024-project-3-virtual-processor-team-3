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

cpu_t* new_cpu(int *mem, int maxmem)
{
    cpu_t* cpu = malloc(sizeof(cpu_t));
    cpu->mem = mem;
    cpu->max_mem = maxmem;
    cpu->pc = 0;
    cpu->sp = maxmem -1;
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
    while (cpu->pc/4 < cpu->max_mem)
    {
        fetch(cpu);
        execute(cpu);
    }
}

void fetch(cpu_t* cpu)
{
    cpu->instruction = (cpu->mem[cpu->pc/4] << 25) >> 25;
}

void execute(cpu_t* cpu)
{
    switch(cpu->instruction)
    {
        case LOAD:
            cpu->func3 = (cpu->mem[cpu->pc/4] << 17) >> 29;
            cpu->destination = (cpu->mem[cpu->pc/4] << 20) >> 27;
            cpu->arg1 = (cpu->mem[cpu->pc/4] << 12) >> 27; // address to take from
            cpu->immediate = ((int)cpu->mem[cpu->pc/4] >> 20); // offset from this address
            if (cpu->func3 == 1) // lb
            {
                if (cpu->mem[cpu->arg1 + cpu->immediate] >> 7 == 0)
                {
                    cpu->x[cpu->destination] = cpu->mem[cpu->x[cpu->arg1]/4 + cpu->immediate/4];
                }
                else
                {
                    cpu->x[cpu->destination] = (int)cpu->mem[cpu->x[cpu->arg1]/4 + cpu->immediate/4];
                    cpu->x[cpu->destination] = (cpu->x[cpu->destination] << 24) >> 24;
                }
            }
            else if (cpu->func3 == 0B10) // lh
            {
                if (cpu->mem[cpu->arg1 + cpu->immediate] >> 15 == 0)
                {
                    cpu->x[cpu->destination] = cpu->mem[cpu->x[cpu->arg1]/4 + cpu->immediate/4];
                }
                else
                {
                    cpu->x[cpu->destination] = (int)cpu->mem[cpu->x[cpu->arg1]/4 + cpu->immediate/4];
                    cpu->x[cpu->destination] = (cpu->x[cpu->destination] << 16) >> 16;
                }
            }
            else if (cpu->func3 == 0B11 || cpu->func3 == 0B100 || cpu->func3 == 0B101) // lw || lbu || lhu
            {
                cpu->x[cpu->destination] = cpu->mem[cpu->x[cpu->arg1]/4 + cpu->immediate/4];
            }
            cpu->pc += 4;
            break;
        case OP_IMM:
            cpu->func3 = (cpu->mem[cpu->pc/4] << 17) >> 29;
            cpu->destination = (cpu->mem[cpu->pc/4] << 20) >> 27;
            cpu->arg1 = (cpu->mem[cpu->pc/4] << 12) >> 27;
            cpu->immediate = ((int)cpu->mem[cpu->pc/4] >> 20);
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
                cpu->x[cpu->destination] = (cpu->x[cpu->arg1] < (uint)cpu->immediate)? 1: 0;
            }
            cpu->pc += 4;
            break;
        case AUIPC:
            break;
        case STORE:
            break;
        case OP:
            cpu->func7 = cpu->mem[cpu->pc/4] >> 25;
            cpu->func3 = (cpu->mem[cpu->pc/4] << 17) >> 29;
            cpu->destination = (cpu->mem[cpu->pc/4] << 20) >> 27;
            cpu->arg1 = (cpu->mem[cpu->pc/4] << 12) >> 27;
            cpu->arg2 = (cpu->mem[cpu->pc/4] << 7) >> 27;
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
                cpu->x[cpu->destination] = (cpu->x[cpu->arg1] < (uint)cpu->x[cpu->arg2])? 1: 0;
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0) //mul
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] * cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B1) // mulh
            {
                long long result = (ll)cpu->x[cpu->arg1] * (ll)cpu->x[cpu->arg2];
                cpu->x[cpu->destination] = (result >> 32);
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B11) // mulhu
            {
                long long result = (ull)cpu->x[cpu->arg1] * (ull)cpu->x[cpu->arg2];
                cpu->x[cpu->destination] = (result >> 32);
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B10) // mulhsu
            {
                long long result = (ll)cpu->x[cpu->arg1] * (ull)cpu->x[cpu->arg2];
                cpu->x[cpu->destination] = (result >> 32);
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B100) // div
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] / cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B101) // divu
            {
                cpu->x[cpu->destination] = (uint)cpu->x[cpu->arg1] / (uint)cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B110) //rem
            {
                cpu->x[cpu->destination] = cpu->x[cpu->arg1] % cpu->x[cpu->arg2];
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B111) // remu
            {
                cpu->x[cpu->destination] = (uint)cpu->x[cpu->arg1] % (uint)cpu->x[cpu->arg2];
            }
            cpu->pc += 4;
            break;
        case LUI:
            break;
        case BRANCH:
            cpu->func3 = (cpu->mem[cpu->pc/4] << 17) >> 29;
            cpu->arg1 = (cpu->mem[cpu->pc/4] << 12) >> 27;
            cpu->arg2 = (cpu->mem[cpu->pc/4] << 7) >> 27;
            cpu->immediate = ((cpu->mem[cpu->pc/4] << 20) >> 28)*2 + ((cpu->mem[cpu->pc/4] << 1) >> 26)*32 + ((cpu->mem[cpu->pc/4] << 24) >> 31)*2048 + (cpu->mem[cpu->pc/4] >> 31)*4096;
            if (cpu->func3 == 1) // jie
            {
                if (cpu->x[cpu->arg1] == cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
                else
                {
                    cpu->pc += 4;
                }
            }
            else if (cpu->func3 == 0B101) // jine
            {
                if (cpu->x[cpu->arg1] != cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
                else
                {
                    cpu->pc += 4;
                }
            }
            else if (cpu->func3 == 0B011) // jige
            {
                if (cpu->x[cpu->arg1] >= cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
                else
                {
                    cpu->pc += 4;
                }
            }
            else if (cpu->func3 == 0B111) //jigeu
            {
                if ((uint)cpu->x[cpu->arg1] >= (uint)cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
                else
                {
                    cpu->pc += 4;
                }
            }
            else if (cpu->func3 == 0B10) // jile
            {
                if (cpu->x[cpu->arg1] <= cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
                else
                {
                    cpu->pc += 4;
                }
            }
            else if (cpu->func3 == 0B110) // jileu
            {
                if ((uint)cpu->x[cpu->arg1] <= (uint)cpu->x[cpu->arg2])
                {
                    cpu->pc = cpu->immediate;
                }
                else
                {
                    cpu->pc += 4;
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
            cpu->pc += 4;
            break;
    }
}

#endif