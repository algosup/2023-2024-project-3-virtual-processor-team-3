#ifndef CPU_H
#define CPU_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "type.h"

void fetch(cpu_t* cpu);
void execute(cpu_t* cpu);

/** This function initialises a new cpu in the memory.
*It loads the binary code in the virtual memory allocated to the cpu, and initialises all the registers at 0.
* @param mem: the binary code, 
* @param maxmem: max size of the memory
* @result cpu_t *cpu: the cpu created
*/
cpu_t* new_cpu(uint *mem, int maxmem)
{
    cpu_t* cpu = malloc(sizeof(cpu_t));
    cpu->mem = mem;
    cpu->max_mem = maxmem;
    cpu->pc = 0;
    cpu->sp = 1023;
    for (int i = 0; i < 32; i++)
    {
        cpu->r[i] = 0;
    }
    return cpu;
}

/** This function free the memory that was allocated to the cpu.
* @param cpu: cpu_t* cpu: current created cpu
* @result: None
*/
void free_cpu(cpu_t* cpu)
{
    free(cpu);
}

/** This function executes the code stored in the memory of the cpu.
* @param cpu: cpu_t* cpu: current created cpu
* @result: None
*/
void run_cpu(cpu_t* cpu)
{
    while (cpu->pc/4 < cpu->max_mem)
    {
        fetch(cpu);
        execute(cpu);
    }
}

/** This function takes the last 7 bits of the current 32 bits of code.
*The last 7 bits determines which type of operation will be executed.
* @param cpu: cpu_t* cpu: current created cpu
* @result: None
*/
void fetch(cpu_t* cpu)
{
    cpu->instruction = (cpu->mem[cpu->pc/4] << 25) >> 25;
}

/** This function executes the current line of binary code.
* It checks the operation type, load the different arguments and does the operation required.
* @param cpu: cpu_t* cpu: current created cpu
* @result: None
*/
void execute(cpu_t* cpu)
{
    switch(cpu->instruction)
    {
        case LOAD:
            cpu->func3 = (cpu->mem[cpu->pc/4] << 17) >> 29;
            cpu->destination = (cpu->mem[cpu->pc/4] << 20) >> 27;
            cpu->arg1 = (cpu->mem[cpu->pc/4] << 12) >> 27; // address to take from
            cpu->immediate = ((int)cpu->mem[cpu->pc/4] >> 20); // offset from this address
            if (cpu->func3 == 0) // lb
            {
                if (cpu->mem[cpu->arg1 + cpu->immediate] >> 7 == 0)
                {
                    cpu->r[cpu->destination] = cpu->mem[cpu->r[cpu->arg1]/4 + cpu->immediate/4];
                }
                else
                {
                    cpu->r[cpu->destination] = (int)cpu->mem[cpu->r[cpu->arg1]/4 + cpu->immediate/4];
                    cpu->r[cpu->destination] = (cpu->r[cpu->destination] << 24) >> 24;
                }
            }
            else if (cpu->func3 == 0B1) // lh
            {
                if (cpu->mem[cpu->arg1 + cpu->immediate] >> 15 == 0)
                {
                    cpu->r[cpu->destination] = cpu->mem[cpu->r[cpu->arg1]/4 + cpu->immediate/4];
                }
                else
                {
                    cpu->r[cpu->destination] = (int)cpu->mem[cpu->r[cpu->arg1]/4 + cpu->immediate/4];
                    cpu->r[cpu->destination] = (cpu->r[cpu->destination] << 16) >> 16;
                }
            }
            else if (cpu->func3 == 0B10 || cpu->func3 == 0B11 || cpu->func3 == 0B100) // lw || lbu || lhu
            {
                cpu->r[cpu->destination] = cpu->mem[cpu->r[cpu->arg1]/4 + cpu->immediate/4];
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
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] + cpu->immediate;
            }
            else if (cpu->func3 == 0B111) // andi
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] & cpu->immediate;    
            }
            else if (cpu->func3 == 0B110) // ori
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] | cpu->immediate;
            }
            else if (cpu->func3 == 0B100) // xori
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] ^ cpu->immediate;
            }
            else if (cpu->func3 == 0B001) // slli
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] << cpu->immediate;
            }
            else if (cpu->func3 == 0B101) // srli
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] >> cpu->immediate;
            }
            // else if (cpu->func3 == 0B101) // srai
            // {
                // cpu->r[cpu->destination] = cpu->r[cpu->arg1] >> cpu->immediate;
            // }
            else if (cpu->func3 == 0B010) // ilti?
            {
                cpu->r[cpu->destination] = (cpu->r[cpu->arg1] < cpu->immediate)? 1: 0;
            }
            else if (cpu->func3 == 0B011) // iltiu?
            {
                cpu->r[cpu->destination] = (cpu->r[cpu->arg1] < (uint)cpu->immediate)? 1: 0;
            }
            cpu->pc += 4;
            break;
        case AUIPC:
            cpu->destination = (cpu->mem[cpu->pc/4] << 20) >> 27;
            cpu->immediate = (cpu->mem[cpu->pc/4] >> 12) * pow(2, 12);
            cpu->pc = (((cpu->pc + cpu->immediate) >> 12 )<< 12);
            break;
        case STORE:
            cpu->func3 = (cpu->mem[cpu->pc/4] << 17) >> 29;
            cpu->arg1 = (cpu->mem[cpu->pc/4] << 12) >> 27; // in this register, there is the address where you want to store
            cpu->arg2 = (cpu->mem[cpu->pc/4] << 7) >> 27; // which register to store
            cpu->immediate = ((cpu->mem[cpu->pc/4] << 20) >> 27) + (cpu->mem[cpu->pc/4] >> 25)*32; // offset
            if (cpu->func3 == 1) // sb
            {
                cpu->mem[cpu->r[cpu->arg1]/4 + cpu->immediate/4] = (cpu->r[cpu->arg2] << 24) >> 24;
            }
            else if (cpu->func3 == 0B10) // sh
            {
                cpu->mem[cpu->r[cpu->arg1]/4 + cpu->immediate/4] = (cpu->r[cpu->arg2] << 16) >> 16;
            }
            else if (cpu->func3 == 0B11) // sw
            {
                cpu->mem[cpu->r[cpu->arg1]/4 + cpu->immediate/4] = cpu->r[cpu->arg2];
            }
            cpu->pc += 4;
            break;
        case OP:
            cpu->func7 = cpu->mem[cpu->pc/4] >> 25;
            cpu->func3 = (cpu->mem[cpu->pc/4] << 17) >> 29;
            cpu->destination = (cpu->mem[cpu->pc/4] << 20) >> 27;
            cpu->arg1 = (cpu->mem[cpu->pc/4] << 12) >> 27;
            cpu->arg2 = (cpu->mem[cpu->pc/4] << 7) >> 27;
            if (cpu->func7 == 0 && cpu->func3 == 0)  // add
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] + cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0B100000 && cpu->func3 == 0) // sub
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] - cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B111) // and
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] & cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B110) // or
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] | cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B100) // xor
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] ^ cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B001) // sll
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] << cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B101) // srl
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] >> cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0B0100000 && cpu->func3 == 0B101) // sra
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] >> cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B010) //ilt?
            {
                cpu->r[cpu->destination] = (cpu->r[cpu->arg1] < cpu->r[cpu->arg2])? 1: 0;
            }
            else if (cpu->func7 == 0 && cpu->func3 == 0B011) //iltu?
            {
                cpu->r[cpu->destination] = (cpu->r[cpu->arg1] < (uint)cpu->r[cpu->arg2])? 1: 0;
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0) //mul
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] * cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B1) // mulh
            {
                long long result = (ll)cpu->r[cpu->arg1] * (ll)cpu->r[cpu->arg2];
                cpu->r[cpu->destination] = (result >> 32);
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B11) // mulhu
            {
                long long result = (ull)cpu->r[cpu->arg1] * (ull)cpu->r[cpu->arg2];
                cpu->r[cpu->destination] = (result >> 32);
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B10) // mulhsu
            {
                long long result = (ll)cpu->r[cpu->arg1] * (ull)cpu->r[cpu->arg2];
                cpu->r[cpu->destination] = (result >> 32);
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B100) // div
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] / cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B101) // divu
            {
                cpu->r[cpu->destination] = (uint)cpu->r[cpu->arg1] / (uint)cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B110) //rem
            {
                cpu->r[cpu->destination] = cpu->r[cpu->arg1] % cpu->r[cpu->arg2];
            }
            else if (cpu->func7 == 0B1 && cpu->func3 == 0B111) // remu
            {
                cpu->r[cpu->destination] = (uint)cpu->r[cpu->arg1] % (uint)cpu->r[cpu->arg2];
            }
            cpu->pc += 4;
            break;
        case LUI:
            cpu->destination = (cpu->mem[cpu->pc/4] << 20) >> 27;
            cpu->immediate = (cpu->mem[cpu->pc/4] >> 12) * pow(2, 12);
            cpu->r[cpu->destination] = cpu->immediate;
            cpu->pc += 4;
            break;
        case BRANCH:
            cpu->func3 = (cpu->mem[cpu->pc/4] << 17) >> 29;
            cpu->arg1 = (cpu->mem[cpu->pc/4] << 12) >> 27;
            cpu->arg2 = (cpu->mem[cpu->pc/4] << 7) >> 27;
            cpu->immediate = ((cpu->mem[cpu->pc/4] << 20) >> 28)*2 + 
                                ((cpu->mem[cpu->pc/4] << 1) >> 26)*32 + 
                                ((cpu->mem[cpu->pc/4] << 24) >> 31)*2048 + 
                                (cpu->mem[cpu->pc/4] >> 31)*4096;

            if (cpu->func3 == 1) // jie
            {
                if (cpu->r[cpu->arg1] == cpu->r[cpu->arg2])
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
                if (cpu->r[cpu->arg1] != cpu->r[cpu->arg2])
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
                if (cpu->r[cpu->arg1] >= cpu->r[cpu->arg2])
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
                if ((uint)cpu->r[cpu->arg1] >= (uint)cpu->r[cpu->arg2])
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
                if (cpu->r[cpu->arg1] <= cpu->r[cpu->arg2])
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
                if ((uint)cpu->r[cpu->arg1] <= (uint)cpu->r[cpu->arg2])
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
            cpu->destination = (cpu->mem[cpu->pc/4] << 20) >> 27;
            cpu->immediate = ((cpu->mem[cpu->pc/4] << 7) >> 28)*2 + 
                                ((cpu->mem[cpu->pc/4] << 1) >> 26)*32 + 
                                ((cpu->mem[cpu->pc/4] << 11) >> 31)*2048 + 
                                ((cpu->mem[cpu->pc/4] << 12) >> 24)*4096 + 
                                (cpu->mem[cpu->pc/4] >> 31)* pow(2, 20);
            cpu->r[cpu->destination] = cpu->immediate;
            break;
        case SYSTEM:
            if (cpu->r[31] == 0B0)
            {
                printf("%d", cpu->r[30]);
            }
            else if (cpu->r[31] == 0B1)
            {
                printf("%c", cpu->r[30]);
            }
            cpu->pc += 4;
            break;
        default:
            cpu->pc += 4;
            break;
    }
}

#endif