#include "assembler.h"
#include <ctype.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: File not found\n");
        return 1;
    }
    assemble(file);
    fclose(file);
    return 0;
}