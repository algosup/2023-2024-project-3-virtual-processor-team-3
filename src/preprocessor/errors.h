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
void errors(int errorNumber )
{
    switch (errorNumber)
    {
    case 0:
        printf("Error:\nFile not found, please enter another path.");
        break;
    case 1:
        printf("Error:\nCommand line argument not recognised.");
        break;
    case 2:
        printf("Error:\nSection data and code not found.");
        break;
    default:
        printf("Error:\nError not defined.");
        break;
    }
    exit(0);
}