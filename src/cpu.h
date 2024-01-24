#include "type.h"

void execute(cpu_t *c);
void fetch(cpu_t *c);

cpu_t* new_cpu(f64* memory, i64 mem_size)
{
    cpu_t* cpu = malloc(sizeof(cpu_t));
    cpu->mem = memory;
    cpu->max_mem = mem_size;
    cpu->pc = -1;
    cpu->inst = 0;
    for (int i = 0; i < 16; i++)
    {
        cpu->r[i] = 0;
        cpu->fr[i] = 0;
    }
    return cpu;
}

void cpu_free(cpu_t* cpu)
{
    free(cpu);
}

void run_cpu(cpu_t* cpu)
{
    while (cpu->pc < cpu->max_mem)
    {
        fetch(cpu);
        execute(cpu);
    }
}

void fetch(cpu_t* cpu)
{
    cpu->pc++;
    cpu->inst = cpu->mem[cpu->pc];
    cpu->dest = cpu->mem[cpu->pc+1];
    cpu->arg1 = cpu->mem[cpu->pc+2];
    cpu->arg2 = cpu->mem[cpu->pc+3];
}

void execute(cpu_t* cpu)
{
    switch (cpu->inst)
    {
        case ADD:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] + cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case SUB:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] - cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case MUL:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] * cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case DIV:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] / cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case ADDF:
            cpu->fr[cpu->dest-16] = cpu->fr[(i64)cpu->arg1-16] + cpu->fr[cpu->arg2-16];
            cpu->pc += 3;
            break;
        case SUBF:
            cpu->fr[cpu->dest-16] = cpu->fr[(i64)cpu->arg1-16] - cpu->fr[cpu->arg2-16];
            cpu->pc += 3;
            break;
        case MULF:
            cpu->fr[cpu->dest-16] = cpu->fr[(i64)cpu->arg1-16] * cpu->fr[cpu->arg2-16];
            cpu->pc += 3;
            break;
        case DIVF:
            cpu->fr[cpu->dest-16] = cpu->fr[(i64)cpu->arg1-16] / cpu->fr[cpu->arg2-16];
            cpu->pc += 3;
            break;
        case LII:
			cpu->r[cpu->dest] = cpu->arg1;
			cpu->pc += 2;
			break;
        case LIF:
			cpu->fr[cpu->dest - 16] = cpu->arg1;
			cpu->pc += 2;
			break;
        case PRT:
            printf("%ld\n", cpu->r[cpu->dest]);
            cpu->pc += 1;
            break;
        case PRTF:
            printf("%f\n", cpu->fr[cpu->dest-16]);
            cpu->pc += 1;
            break;
        default:
            printf("Unknown instruction: %d\n", cpu->inst);
            exit(1);
    }
}