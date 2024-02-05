#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define byte unsigned char
#define u64 unsigned long long
#define i64 long long
#define f64 double

// Check line by line and if a line contains a ".code" or ".data" directive, it will be printed in command line. If there is a "." something else, it should return an error and if there is something else written in the line, it should return an error as well.

void create_data_file()
{
    FILE *data = fopen("data.txt", "w");
}

void create_code_file()
{
    FILE *code = fopen("code.txt", "w");
}

bool is_error(FILE *asm_file)
{
    bool error = false;
    char line[100];
    while (fgets(line, 100, asm_file))
    {
        if (strstr(line, ".code") || strstr(line, ".data"))
        {
        }
        else
        {
            error = true;
        }
    }
    return error;
}

void write_data(FILE *asm_file) {
    char line[100];
    FILE *data_file = fopen("data.txt", "w");

    while (fgets(line, sizeof(line), asm_file)) {
        if (strstr(line, ".data")) {
            // Write each line to the data file until it encounters a ".code" directive
            while (fgets(line, sizeof(line), asm_file) && strstr(line, ".code") == NULL) {
                fprintf(data_file, "%s", line);
            }
        }
    }

    fclose(data_file);
}

void write_code(FILE *asm_file) {
    char line[100];
    FILE *code_file = fopen("code.txt", "w");

    while (fgets(line, sizeof(line), asm_file)) {
        if (strstr(line, ".code")) {
            while (fgets(line, sizeof(line), asm_file) == NULL) {
                fprintf(code_file, "%s", line);
            }
        }
    }

    fclose(code_file);
}