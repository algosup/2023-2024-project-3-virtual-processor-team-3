#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define byte unsigned char
#define u64 unsigned long long
#define i64 long long
#define f64 double

/**
 *This function prints an error and exit the program depending of the error.
 *@param errorNumber(int): An int representing which error has been found.
 *@result An error is printed in the terminal and the program exits.
 */
void errorsHandler(int errorNumber)
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
        errorsHandler(1);
    }
    if (strcmp(argv[1], "gorasm") != 0 && strcmp(argv[1], "gras") != 0)
    {
        errorsHandler(2);
    }
    if (argc > 3)
    {
        errorsHandler(3);
    }
}

void sectionNotFound(FILE *asm_file)
{
    bool error = true;
    char line[100];
    while (fgets(line, 100, asm_file))
    {
        if (strstr(line, ".code") || strstr(line, ".data"))
        {
            error=false;
        }
        else
        {

        }
    }
    if(error){
        errorsHandler(4);
    }
}

void incorrectSection (FILE *asm_file)
{
    char line[100];
    while (fgets(line, 100, asm_file))
    {
        if (strstr(line, ".")){
            if (strstr(line, ".data" ) || strstr(line, ".code")){
                continue;
            }
            else{
                errorsHandler(4);
            }
        }
    }
}