#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "preprocessor.h"

#define byte unsigned char
#define u64 unsigned long long
#define i64 long long
#define f64 double

/**
 *This function prints an error and exit the program depending of the error.
 *@param errorNumber(int): An int representing which error has been found.
 *@param LineNumber(int): An int representing at which line the error has been found.
 *@result An error is printed in the terminal and the program exits.
 */
void errorsHandler(int errorNumber, int LineNumber, char *Line)
{
    switch (errorNumber)
    {
    case 0:
        printf("Error:\nFile not found, please enter another path.");
        break;
    case 1:
        printf("Error:\nCommand line argument are required.");
        break;
    case 2:
        printf("Error:\nCommand line argument not recognised.");
        break;
    case 3:
        printf("Error:\nToo many command line arguments.");
        break;
    case 4:
        printf("Error:\nSection data and code not found.");
        break;
    case 5:
        printf("Error:\nSection undefined found at line number:%d\n%s", LineNumber, Line);
        break;
    default:
        printf("Error:\nError not defined.");
        break;
    }
    exit(0);
}

/**
 * This function goes through the arguments and search for errors.
 * @param argc (int): The number of arguments called in the command line.
 * @param argv (char array pointer): An array of all the arguments.
 * @result If there is no errors, does nothing, if there is an error, call the error handler.
 */
void checkArgs(int argc, char *argv[])
{
    if (argc < 3)
    {
        errorsHandler(1, 0, " ");
    }
    if (strcmp(argv[1], "gorasm") != 0 && strcmp(argv[1], "gras") != 0)
    {
        errorsHandler(2, 0, " ");
    }
    if (argc > 3)
    {
        errorsHandler(3, 0, " ");
    }
}

/**
 * This functions checks if there is a section .data or .code.
 * @param asm_file(FILE pointer): A pointer to an assembly file.
 * @result If there is no .data or .code section in the assembly file, return an error.
 */
void sectionNotFound(FILE *asm_file)
{
    bool error = true;
    char line[100];
    rewind(asm_file);
    while (fgets(line, sizeof(line), asm_file))
    {
        if (strstr(line, ".code") || strstr(line, ".data"))
        {
            error = false;
        }
    }
    if (error)
    {
        errorsHandler(4, 0, " ");
    }
    rewind(asm_file);
}

/**
 * This functions returns the position of the first character other than spaces.
 * @param line(char pointer): A pointer to a char.
 * @result The index of the first character other than a space.
 */
char *suppressIndentation(char *line)
{
    // Find the index of the first non-whitespace character
    int index = 0;
    while (line[index] == ' ' || line[index] == '\t')
    {
        index++;
    }

    char *noIntendLine = &line[index];
    return noIntendLine;
}

void incorrectSection(FILE *asm_file)
{
    char line[100];
    int LineNumber = 1;
    while (fgets(line, sizeof(line), asm_file))
    {
        char *noIntendLine = suppressIndentation(line);
        if (noIntendLine[0] == '.')
        {
            if (!strstr(line, ".data") && !strstr(line, ".code"))
            {
                errorsHandler(5, LineNumber, line);
            }
        }
        LineNumber++;
    }
    rewind(asm_file);
}

#endif
