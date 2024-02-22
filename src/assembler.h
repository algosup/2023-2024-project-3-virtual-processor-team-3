#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#include "type.h"

uint extractNumber(const char *str) {
    uint number = 0;
    int i = 0;
    
    // Skip non-digit characters
    while (str[i] && !isdigit(str[i])) {
        i++;
    }
    
    // Extract number
    while (isdigit(str[i])) {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    
    return number;
}

void assemble(FILE *file)
{
    char line[BITS + 1];
    uint bits = 0;

    FILE *out = fopen("out.gras", "wb");

    while (fgets(line, sizeof(line), file)) {
        // split the line in two at the first space
        char *lineOpcode = strtok(line, " ");
        char *lineDest = strtok(NULL, " ");
        char *lineArg1 = strtok(NULL, " ");
        char *lineArg2 = strtok(NULL, " ");
        uint Dest, Arg1, Arg2;
        // check if the opcode is valid
        for (int i = 0; i < sizeof(opcode)/sizeof(opcode[0]); i++)
        {
            if (strcmp(lineOpcode, opcode[i]) == 0)
            {
                // if it is, call the corresponding function
                switch (i)
                {
                    case 0: // add 
                        if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + Dest * pow(2, 7) + 0B0110011;
                        break; 
                    case 1: // sub
                        if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = 0B100000 * pow (2, 25) + Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + Dest * pow(2, 7) + 0B0110011;
                        break;
                    case 2: // sll
                        if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B1 * pow (2, 12) + Dest * pow(2, 7) + 0B0110011;
                        break;
                    case 3: // srl
                        if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B101 * pow (2, 12) + Dest * pow(2, 7) + 0B0110011;
                        break;
                    case 4: // sra
                        if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = 0B100000 * pow (2, 25) + Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B101 * pow (2, 12) + Dest * pow(2, 7) + 0B0110011;
                        break;
                    case 5: // xor
                        if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B100 * pow (2, 12) + Dest * pow(2, 7) + 0B0110011;
                        break;
                    case 6: // or
                        if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B110 * pow (2, 12) + Dest * pow(2, 7) + 0B0110011;
                        break;
                    case 7: // and
                        if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B111 * pow (2, 12) + Dest * pow(2, 7) + 0B0110011;
                        break;
                    case 8: // ilt?
                        if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B010 * pow (2, 12) + Dest * pow(2, 7) + 0B0110011;
                        break;
                    case 9: // iltu?
                        if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B011 * pow (2, 12) + Dest * pow(2, 7) + 0B0110011;
                        break;
                    case 10: // addi
                        if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + Dest * pow(2, 7) + 0B0010011;
                        break;
                    case 11: // slli
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B1 * pow(2, 12) + Dest * pow(2, 7) + 0B0010011;
                        break;
                    case 12: // srli
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B101 * pow(2, 12) + Dest * pow(2, 7) + 0B0010011;
                        break;
                    case 13: // xori
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B100 * pow(2, 12) + Dest * pow(2, 7) + 0B0010011;
                        break;
                    case 14: // ori
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B110 * pow(2, 12) + Dest * pow(2, 7) + 0B0010011;
                        break;
                    case 15: // andi
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B111 * pow(2, 12) + Dest * pow(2, 7) + 0B0010011;
                        break;
                    case 16: // ilti?
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B010 * pow(2, 12) + Dest * pow(2, 7) + 0B0010011;
                        break;
                    case 17: // iltiu?
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = Arg2 * pow(2, 20) + Arg1 * pow(2, 15) + 0B011 * pow(2, 12) + Dest * pow(2, 7) + 0B0010011;
                        break;
                    case 18: // jie
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = ((Arg2 >> 12) & 0x1) << 31 | ((Arg2 >> 5) & 0x3F) << 25 | Arg1 << 20 | Dest << 15 | 0B101 << 12 | ((Arg2 >> 1) & 0xF) << 8 | ((Arg2 >> 11) & 0x1) << 7 | 0B1100011;
                        break;
                    case 19: // jine
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = ((Arg2 >> 12) & 0x1) << 31 | ((Arg2 >> 5) & 0x3F) << 25 | Arg1 << 20 | Dest << 15 | 0B101 << 12 | ((Arg2 >> 1) & 0xF) << 8 | ((Arg2 >> 11) & 0x1) << 7 | 0B1100011;
                        break;
                    case 20: // jige
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = ((Arg2 >> 12) & 0x1) << 31 | ((Arg2 >> 5) & 0x3F) << 25 | Arg1 << 20 | Dest << 15 | 0B101 << 12 | ((Arg2 >> 1) & 0xF) << 8 | ((Arg2 >> 11) & 0x1) << 7 | 0B1100011;
                        break;
                    case 21: // jigeu
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = ((Arg2 >> 12) & 0x1) << 31 | ((Arg2 >> 5) & 0x3F) << 25 | Arg1 << 20 | Dest << 15 | 0B101 << 12 | ((Arg2 >> 1) & 0xF) << 8 | ((Arg2 >> 11) & 0x1) << 7 | 0B1100011;
                        break;
                    case 22: // jile
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = ((Arg2 >> 12) & 0x1) << 31 | ((Arg2 >> 5) & 0x3F) << 25 | Arg1 << 20 | Dest << 15 | 0B101 << 12 | ((Arg2 >> 1) & 0xF) << 8 | ((Arg2 >> 11) & 0x1) << 7 | 0B1100011;
                        break;
                    case 23: // jileu
                    if (lineDest == NULL || lineArg1 == NULL || lineArg2 == NULL)
                        {
                            printf("Error: Invalid number of arguments\n");
                            return;
                        }
                        Dest = extractNumber(lineDest);
                        Arg1 = extractNumber(lineArg1);
                        Arg2 = extractNumber(lineArg2);
                        bits = ((Arg2 >> 12) & 0x1) << 31 | ((Arg2 >> 5) & 0x3F) << 25 | Arg1 << 20 | Dest << 15 | 0B101 << 12 | ((Arg2 >> 1) & 0xF) << 8 | ((Arg2 >> 11) & 0x1) << 7 | 0B1100011;
                        break;
                }
            }
        }
        // write the bits to the file
        //fwrite(&bits, sizeof(uint), 1, out);
        printf("%d\n", bits);
        bits = 0;
    }
}

#endif