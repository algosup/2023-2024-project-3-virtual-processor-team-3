#include "..\src\cpu.h"

void sumInt(void);
void fibonacci(void);
void factorial(void);
void power(void);
void helloworld(void);

int main(void)
{
    sumInt();
    printf("\n");
    fibonacci();
    printf("\n");
    factorial();
    printf("\n");
    power();
    printf("\n");
    helloworld();
    printf("\n");
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
        0B00000000000100000000111100110011, // add x30, x1, x0
        0B00000000000000000000000001110011, // syscall
    };

    int maxmem = sizeof(mem)/sizeof(mem[0]);
    cpu_t *cpu = new_cpu(mem, maxmem);
    run_cpu(cpu);
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
        0B00000000001100000000111100110011, // add x30, x3, x0
        0B00000000000000000000000001110011, // syscall
    };

    int maxmem = sizeof(mem)/sizeof(mem[0]);
    cpu_t *cpu = new_cpu(mem, maxmem);
    run_cpu(cpu);
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
        0B00000000000100000000111100110011, // add x30, x1, x0
        0B00000000000000000000000001110011, // syscall
    };

    int maxmem = sizeof(mem)/sizeof(mem[0]);
    cpu_t *cpu = new_cpu(mem, maxmem);
    run_cpu(cpu);
    free_cpu(cpu);
}

void power(void)
{
    uint mem[]=
    {
        0B00000000000100000000000010010011, // addi x1, x0, 1
        0B00000000001100000000000100010011, // addi x2, x0, 3
        0B00000000011000000000000110010011, // addi x3, x0, 6
        //
        0B00000010001100001000000010110011, // mul x1, x3, x1
        0B11111111111100010000000100010011, // addi x2, x2, -1
        0B00000000001000000101011001100011, // jine x2, x0, 12
        0B00000000000100000000111100110011, // add x30, x1, x0
        0B00000000000000000000000001110011, // syscall
    };

    int maxmem = sizeof(mem)/sizeof(mem[0]);
    cpu_t *cpu = new_cpu(mem, maxmem);
    run_cpu(cpu);
    free_cpu(cpu);
}

void helloworld (void)
{
    uint mem[]=
    {
        0B00000000000100000000111110010011, // addi x31, x0, 1
        0B00000100100000000000111100010011, // addi x30, x0, 72 == H
        0B00000000000000000000000001110011, // syscall
        0B00000001111011110100111100110011, // xor x30, x30, x30
        0B00000110010100000000111100010011, // addi x30, x0, 101 == e
        0B00000000000000000000000001110011, // syscall
        0B00000001111011110100111100110011, // xor x30, x30, x30
        0B00000110110000000000111100010011, // addi x30, x0, 108 == l
        0B00000000000000000000000001110011, // syscall
        0B00000001111011110100111100110011, // xor x30, x30, x30
        0B00000110110000000000111100010011, // addi x30, x0, 101 == l
        0B00000000000000000000000001110011, // syscall
        0B00000001111011110100111100110011, // xor x30, x30, x30
        0B00000110111100000000111100010011, // addi x30, x0, 101 == o
        0B00000000000000000000000001110011, // syscall
        0B00000001111011110100111100110011, // xor x30, x30, x30
    };

    int maxmem = sizeof(mem)/sizeof(mem[0]);
    cpu_t *cpu = new_cpu(mem, maxmem);
    run_cpu(cpu);
    free_cpu(cpu);
}