#include "..\src\cpu.h"

void sumInt(void);
void fibonacci(void);
void factorial(void);
void power(void);

int main(void)
{
    sumInt();
    fibonacci();
    factorial();
    power();
    return 0;
}

void sumInt(void)
{
    uint mem[]=
    {
        0B00000000000100000000000010010011, // addi x1, x0, 1
        0B00000000101000000000000100010011, // addi x2, x0, 10
        0B00000000000100000000000110010011, // addi x3, x0, 1
        //
        0B00000000001000001000000010110011, // add x1, x1, x2
        0B01000000001100010000000100110011, // sub x2, x2, x3
        0B00000000001000011101011001100011, // jine x2, x3, 12
    };

    int maxmem = sizeof(mem)/sizeof(mem[0]);
    cpu_t *cpu = new_cpu(mem, maxmem);
    run_cpu(cpu);
    printf("Sum: %d\n", cpu->r[1]);
    free_cpu(cpu);
}

void fibonacci(void)
{
    uint mem[]=
    {
        0B00000000000100000000000010010011, // addi x1, x0, 1 == n-2
        0B00000000000100000000000010010011, // addi x2, x0, 1 == n-1
        0B00000000100100000000001000010011, // addi x4, x0, 10
        //
        0B00000000001000001000000110110011, // add x3, x1, x2 == n
        0B00000000000000010000000010110011, // add x1, x2, x0
        0B00000000000000011000000100110011, // add x2, x3, x0
        0B11111111111100100000001000010011, // addi x4, x4, -1
        0B00000000010000000101011001100011, // jine x4, x0, 12
    };

    int maxmem = sizeof(mem)/sizeof(mem[0]);
    cpu_t *cpu = new_cpu(mem, maxmem);
    run_cpu(cpu);
    printf("Fibonacci: %d\n", cpu->r[3]);
    free_cpu(cpu);
}

void factorial(void){
    uint mem[]=
    {
        0B00000000000100000000000010010011, // addi x1, x0, 1
        0B00000000100000000000000100010011, // addi x2, x0, 8
        0B00000000000100000000000110010011, // addi x3, x0, 1
        //
        0B00000010001000001000000010110011, // mul x1, x1, x2
        0B01000000001100010000000100110011, // sub x2, x2, x3
        0B00000000001000011101011001100011, // jine x2, x3, 12
    };

    int maxmem = sizeof(mem)/sizeof(mem[0]);
    cpu_t *cpu = new_cpu(mem, maxmem);
    run_cpu(cpu);
    printf("Factorial: %d\n", cpu->r[1]);
    free_cpu(cpu);
}

void power(void)
{
    uint mem[]=
    {
        0B00000000011000000000000010010011, // addi x1, x0, 6
        0B00000000001100000000000100010011, // addi x2, x0, 3
        0B00000000000100000000000110010011, // addi x3, x0, 1
        //
        0B00000010001100001000000110110011, // mul x3, x3, x1
        0B11111111111100010000000100010011, // addi x2, x2, -1
        0B00000000001000000101011001100011, // jine x3, x0, 12
    };

    int maxmem = sizeof(mem)/sizeof(mem[0]);
    cpu_t *cpu = new_cpu(mem, maxmem);
    run_cpu(cpu);
    printf("Power: %d\n", cpu->r[3]);
    free_cpu(cpu);
}