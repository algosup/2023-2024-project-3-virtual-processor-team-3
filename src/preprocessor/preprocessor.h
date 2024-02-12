#include "errors.h"

#define byte unsigned char
#define u64 unsigned long long
#define i64 long long
#define f64 double

// Check line by line and if a line contains a ".code" or ".data" directive, it will be printed in command line. If there is a "." something else, it should return an error and if there is something else written in the line, it should return an error as well.

void createDataFile()
{
    FILE *data = fopen("data.txt", "w");
}

void createCodeFile()
{
    FILE *code = fopen("code.txt", "w");
}

void writeData(FILE *asmFile) {
    rewind(asmFile);  // Move the file pointer to the beginning of the file
    char line[100];
    FILE *dataFile = fopen("data.txt", "w");

    while (fgets(line, sizeof(line), asmFile)) {
        if (strstr(line, ".data")) {
            // Write each line to the data file until it encounters a ".code" directive
            while (fgets(line, sizeof(line), asmFile) && strstr(line, ".code") == NULL) {
                fprintf(dataFile, "%s", line);
            }
        }
    }

    fclose(dataFile);
}

void writeCode(FILE *asmFile) {
    rewind(asmFile);  // Move the file pointer to the beginning of the file
    char line[100];
    FILE *codeFile = fopen("code.txt", "w");  // Open in append mode

    while (fgets(line, sizeof(line), asmFile)) {
        if (strstr(line, ".code")) {
            // Write each line to the code file starting from the line after ".code" directive
            while (fgets(line, sizeof(line), asmFile)) {
                fprintf(codeFile, "%s", line);
            }
            break; // Exit the loop after writing the code section
        }
    }

    fclose(codeFile);
}