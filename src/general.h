#ifndef GENERAL_H
#define GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#include "errors.h"

/**
 * This function goes through the arguments and search for errors.
 * @param argc (int): The number of arguments called in the command line.
 * @param argv (char array pointer): An array of all the arguments.
 * @result If there is no errors, does nothing, if there is an error, call the error handler.
 */
int checkArgs(int argc, char *argv[])
{
    if (argc < 3)
    {
        errorsHandler(1, 0, " ");
    }

    if (strcmp(argv[1], "gorasm") == 0)
    {
        return 1;
    }
    else if (strcmp(argv[1], "goproc") == 0)
    {
        return 2;
    }
    else if (strcmp(argv[1], "gorisk") == 0)
    {
        return 3;
    }
    else
    {
        errorsHandler(2, 0, " ");
    }
    if (argc > 3)
    {
        errorsHandler(3, 0, " ");
    }
}


#endif