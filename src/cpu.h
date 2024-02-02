#ifndef CPU_H
#define CPU_H

#include "type.h"

void execute(cpu_t *c);
void fetch(cpu_t *c);

cpu_t* new_cpu(f64* memory, i64 mem_size)
{
    cpu_t* cpu = malloc(sizeof(cpu_t));
    cpu->mem = memory;
    cpu->max_mem = mem_size;
    cpu->pc = -1;
    cpu->sp = mem_size - 1;
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
    while (cpu->inst != BREAK)
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
        // case LII:
		// 	cpu->r[cpu->dest] = cpu->arg1;
		// 	cpu->pc += 2;
		// 	break;
        // case LIF:
		// 	cpu->fr[cpu->dest - 16] = cpu->arg1;
		// 	cpu->pc += 2;
		// 	break;
        // case STI:
        //     cpu->mem[cpu->dest] = cpu->r[(i64)cpu->arg1];
        //     cpu->pc += 2;
        //     break;
        // case STF:
        //     cpu->mem[cpu->dest] = cpu->fr[(i64)cpu->arg1-16];
        //     cpu->pc += 2;
        //     break;
        // case LDI:
        //     cpu->r[cpu->dest] = cpu->mem[(i64)cpu->arg1];
        //     cpu->pc += 2;
        //     break;
        // case LDF:
        //     cpu->fr[cpu->dest-16] = cpu->mem[(i64)cpu->arg1];
        //     cpu->pc += 2;
        //     break;
        // case MOV:
        //     cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1];
        //     cpu->pc += 2;
        //     break;
        // case MOVF:
        //     cpu->fr[cpu->dest-16] = cpu->fr[(i64)cpu->arg1-16];
        //     cpu->pc += 2;
        //     break;
        // case ADD:
        //     cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] + cpu->r[cpu->arg2];
        //     cpu->pc += 3;
        //     break;
        // case SUB:
        //     cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] - cpu->r[cpu->arg2];
        //     cpu->pc += 3;
        //     break;
        // case MUL:
        //     cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] * cpu->r[cpu->arg2];
        //     cpu->pc += 3;
        //     break;
        // case DIV:
        //     cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] / cpu->r[cpu->arg2];
        //     cpu->pc += 3;
        //     break;
        // case ADDF:
        //     cpu->fr[cpu->dest-16] = cpu->fr[(i64)cpu->arg1-16] + cpu->fr[cpu->arg2-16];
        //     cpu->pc += 3;
        //     break;
        // case SUBF:
        //     cpu->fr[cpu->dest-16] = cpu->fr[(i64)cpu->arg1-16] - cpu->fr[cpu->arg2-16];
        //     cpu->pc += 3;
        //     break;
        // case MULF:
        //     cpu->fr[cpu->dest-16] = cpu->fr[(i64)cpu->arg1-16] * cpu->fr[cpu->arg2-16];
        //     cpu->pc += 3;
        //     break;
        // case DIVF:
        //     cpu->fr[cpu->dest-16] = cpu->fr[(i64)cpu->arg1-16] / cpu->fr[cpu->arg2-16];
        //     cpu->pc += 3;
        //     break;
        case PRT:
            printf("%ld\n", cpu->r[cpu->dest]);
            cpu->pc += 1;
            break;
        // case PRTF:
        //     printf("%f\n", cpu->fr[cpu->dest-16]);
        //     cpu->pc += 1;
        //     break;
        // case PUSH:
		// 	cpu->mem[--cpu->sp] = cpu->r[(i64)cpu->mem[++cpu->pc]];
		// 	break;
        // case POP:
		// 	cpu->r[(i64)cpu->mem[++cpu->pc]] = cpu->mem[cpu->sp++];
		// 	break;
        // case PUSHF:
        //     cpu->mem[--cpu->sp] = cpu->fr[(i64)cpu->mem[++cpu->pc]-16];
        //     break;
        // case POPF:
        //     cpu->fr[(i64)cpu->mem[++cpu->pc]-16] = cpu->mem[cpu->sp++];
        //     break;
        // case STOP:
        //     cpu->pc = cpu->max_mem;
        //     break;

        case ADD:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] + cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case ADDI:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] + cpu->arg2;
            cpu->pc += 3;
            break;
        case SUB:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] - cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case AND:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] & cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case ANDI:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] & cpu->arg2;
            cpu->pc += 3;
            break;
        case OR:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] | cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case ORI:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] | cpu->arg2;
            cpu->pc += 3;
            break;
        case XOR:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] ^ cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case XORI:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] ^ cpu->arg2;
            cpu->pc += 3;
            break;
        case SLL:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] << cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case SLLI:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] << cpu->arg2;
            cpu->pc += 3;
            break;
        case SRL:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] >> cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case SRLI:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] >> cpu->arg2;
            cpu->pc += 3;
            break;
        case SRA:
            cpu->r[cpu->dest] = (i64)cpu->r[(i64)cpu->arg1] >> cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case SRAI:
            cpu->r[cpu->dest] = (i64)cpu->r[(i64)cpu->arg1] >> cpu->arg2;
            cpu->pc += 3;
            break;
        case ILT:
            if (cpu->r[(i64)cpu->arg1] < cpu->r[cpu->arg2])
                cpu->r[cpu->dest] = 1;
            else
                cpu->r[cpu->dest] = 0;
            cpu->pc += 3;
            break;
        case ILTI:
            if (cpu->r[(i64)cpu->arg1] < cpu->arg2)
                cpu->r[cpu->dest] = 1;
            else
                cpu->r[cpu->dest] = 0;
            cpu->pc += 3;
            break;
        case ILTU:
            if ((u64)cpu->r[(i64)cpu->arg1] < (u64)cpu->r[cpu->arg2])
                cpu->r[cpu->dest] = 1;
            else
                cpu->r[cpu->dest] = 0;
            cpu->pc += 3;
            break;
        case ILTUI:
            if ((u64)cpu->r[(i64)cpu->arg1] < (u64)cpu->arg2)
                cpu->r[cpu->dest] = 1;
            else
                cpu->r[cpu->dest] = 0;
            cpu->pc += 3;
            break;
        case JIE:
            if (cpu->r[(i64)cpu->arg1] == cpu->r[cpu->arg2])
                cpu->pc = cpu->dest;
            else
                cpu->pc += 3;
            break;
        case JINE:
            if (cpu->r[(i64)cpu->arg1] != cpu->r[cpu->arg2])
                cpu->pc = cpu->dest;
            else
                cpu->pc += 3;
            break;
        case JIGE:
            if (cpu->r[(i64)cpu->arg1] >= cpu->r[cpu->arg2])
                cpu->pc = cpu->dest;
            else
                cpu->pc += 3;
            break;
        case JIGEU:
            if ((u64)cpu->r[(i64)cpu->arg1] >= (u64)cpu->r[cpu->arg2])
                cpu->pc = cpu->dest;
            else
                cpu->pc += 3;
            break;
        case JILE:
            if (cpu->r[(i64)cpu->arg1] <= cpu->r[cpu->arg2])
                cpu->pc = cpu->dest;
            else
                cpu->pc += 3;
            break;
        case JILEU:
            if ((u64)cpu->r[(i64)cpu->arg1] <= (u64)cpu->r[cpu->arg2])
                cpu->pc = cpu->dest;
            else
                cpu->pc += 3;
            break;
        case JAL:
            cpu->r[cpu->dest] = cpu->pc + 2;
            cpu->pc = cpu->arg1;
            break;
        case JALR:
            cpu->r[cpu->dest] = cpu->pc + 2;
            cpu->pc = cpu->r[(i64)cpu->arg1];
            break;
        case LB:
            cpu->r[cpu->dest] = cpu->mem[(i64)cpu->arg1];
            cpu->pc += 2;
            break;
        case LBU:
            cpu->r[cpu->dest] = (u64)cpu->mem[(i64)cpu->arg1];
            cpu->pc += 2;
            break;
        case LH:
            cpu->r[cpu->dest] = cpu->mem[(i64)cpu->arg1];
            cpu->pc += 2;
            break;
        case LHU:
            cpu->r[cpu->dest] = (u64)cpu->mem[(i64)cpu->arg1];
            cpu->pc += 2;
            break;
        case LW:
            cpu->r[cpu->dest] = cpu->mem[(i64)cpu->arg1];
            cpu->pc += 2;
            break;
        case LUI:
            cpu->r[cpu->dest] = (i64)cpu->arg1 << 12;
            cpu->pc += 2;
            break;
        case AUIPC:
            cpu->r[cpu->dest] = cpu->pc + ((u64)cpu->arg2 << 12);
            cpu->pc += 2;
            break;
        case SB:
            cpu->mem[(i64)cpu->arg1] = cpu->r[cpu->dest];
            cpu->pc += 2;
            break;
        case SH:
            cpu->mem[(i64)cpu->arg1] = cpu->r[cpu->dest];
            cpu->pc += 2;
            break;
        case SW:
            cpu->mem[(i64)cpu->arg1] = cpu->r[cpu->dest];
            cpu->pc += 2;
            break;
        case MUL:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] * cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case MULH:
            cpu->r[cpu->dest] = (i64)cpu->r[(i64)cpu->arg1] * (i64)cpu->r[cpu->arg2] >> 32;
            cpu->pc += 3;
            break;
        case MULHU:
            cpu->r[cpu->dest] = (u64)cpu->r[(i64)cpu->arg1] * (u64)cpu->r[cpu->arg2] >> 32;
            cpu->pc += 3;
            break;
        case MULHSU:
            cpu->r[cpu->dest] = (i64)cpu->r[(i64)cpu->arg1] * (u64)cpu->r[cpu->arg2] >> 32;
            cpu->pc += 3;
            break;
        case DIV:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] / cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case DIVU:
            cpu->r[cpu->dest] = (u64)cpu->r[(i64)cpu->arg1] / (u64)cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case REM:
            cpu->r[cpu->dest] = cpu->r[(i64)cpu->arg1] % cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        case REMU:
            cpu->r[cpu->dest] = (u64)cpu->r[(i64)cpu->arg1] % (u64)cpu->r[cpu->arg2];
            cpu->pc += 3;
            break;
        
        default:
            printf("Unknown instruction: %d\n", cpu->inst);
            exit(1);
    }
}

#endif