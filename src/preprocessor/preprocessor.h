#include "errors.h"

// Check line by line and if a line contains a ".code" or ".data" directive, it will be printed in command line. If there is a "." something else, it should return an error and if there is something else written in the line, it should return an error as well.

// void createDataFile()
// {
//     FILE *data = fopen("data.txt", "w");
// }

// void createCodeFile()
// {
//     FILE *code = fopen("code.txt", "w");
// }

void writeData(FILE *file) {
    rewind(file);  // Move the file pointer to the beginning of the file
    char line[100];
    FILE *dataFile = fopen("./temp_files/data.txt", "w");

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, ".data")) {
            // Write each line to the data file until it encounters a ".code" directive
            while (fgets(line, sizeof(line), file) && strstr(line, ".code") == NULL) {
                fprintf(dataFile, "%s", line);
            }
        }
    }

    fclose(dataFile);
}

void writeCode(FILE *file) {
    rewind(file);  // Move the file pointer to the beginning of the file
    char line[100];
    FILE *codeFile = fopen("./temp_files/code.txt", "w");  // Open in append mode

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, ".code")) {
            // Write each line to the code file starting from the line after ".code" directive
            while (fgets(line, sizeof(line), file)) {
                fprintf(codeFile, "%s", line);
            }
            break; // Exit the loop after writing the code section
        }
    }

    fclose(codeFile);
}

void isComment(FILE *asmFile)
{
    rewind(asmFile);  // Move the file pointer to the beginning of the file
    char line[100];
    FILE *noCommentsFile = fopen("./temp_files/noComments.txt", "w");  // Open in append mode

    while (fgets(line, sizeof(line), asmFile)) {
        char *commentStart = strstr(line, "//");
        
        if (commentStart != NULL) {
            // Single-line comment found, truncate the line at the comment
            *commentStart = '\0';
            fprintf(noCommentsFile, "%s \n", line);
        }
        else {
            fprintf(noCommentsFile, "%s", line);
        }
    }

    fclose(noCommentsFile);  // Close the file after writing
}

