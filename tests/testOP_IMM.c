#include "..\src\cpu.h"

void testAddi(void);
void testAndi(void);
void testOri(void);
void testXori(void);
void testSlli(void);
void testSrli(void);
void testIlti(void);
void testIltiu(void);

int main(void)
{
    testAddi();
    testAndi();
    testOri();
    testXori();
    testSlli();
    testSrli();
    testIlti();
    testIltiu();

    return 0;
}

void testAddi(void){
    uint memAddi[] =
    {
        0B00000000100000100000000110010011, // addi x3, x4, 8
        //IIIIIIIIIIII11111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memAddi);
    cpu->x[4] = 4;
    run_cpu(cpu);
    printf("Addi: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testAndi(void){
    uint memAndi[] =
    {
        0B00000000010100100111000110010011, // andi x3, x4, 5
        //IIIIIIIIIIII11111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memAndi);
    cpu->x[4] = 4;
    run_cpu(cpu);
    printf("Andi: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testOri(void){
    uint memOri[] =
    {
        0B00000000010100100110000110010011, // ori x3, x4, 5
        //IIIIIIIIIIII11111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memOri);
    cpu->x[4] = 4;
    run_cpu(cpu);
    printf("Ori: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testXori(void){
    uint memXori[] =
    {
        0B00000000010100100100000110010011, // xori x3, x4, 5
        //IIIIIIIIIIII11111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memXori);
    cpu->x[4] = 4;
    run_cpu(cpu);
    printf("Xori: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testSlli(void){
    uint memSlli[] =
    {
        0B00000000001100100001000110010011, // slli x3, x4, 3
        //IIIIIIIIIIII11111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memSlli);
    cpu->x[4] = 4;
    run_cpu(cpu);
    printf("Slli: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testSrli(void){
    uint memSrli[] =
    {
        0B00000000001100100101000110010011, // srli x3, x4, 3
        //IIIIIIIIIIII11111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memSrli);
    cpu->x[4] = 32;
    run_cpu(cpu);
    printf("Srli: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testIlti(void){
    uint memIlti[] =
    {
        0B00000000001000100010000110010011, // ilti x3, x4, 32
        //IIIIIIIIIIII11111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memIlti);
    cpu->x[4] = -4;
    run_cpu(cpu);
    printf("Ilti: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}

void testIltiu(void){
    uint memIltiu[] =
    {
        0B00000000000000100011000110010011, // iltiu x3, x4, 1
        //IIIIIIIIIIII11111333DDDDDOOOOOOO      
    };
    cpu_t *cpu = new_cpu(memIltiu);
    cpu->x[4] = 4;
    run_cpu(cpu);
    printf("Iltiu: x3: %d\n", cpu->x[3]);
    free_cpu(cpu);
}