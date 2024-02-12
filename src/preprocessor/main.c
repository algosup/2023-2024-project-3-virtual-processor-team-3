#include "preprocessor.h"

int main(int argc, char* argv[])
{
    FILE *asm_file;
    if (asm_file = fopen(argv[2], "r"))
    {
        sectionNotFound(asm_file);
        write_data(asm_file);
        write_code(asm_file);
    }
    else{
        errors(0);
    }
    // if (is_error(asm_file))
    // {
    //     printf("Error detected in the assembly file.\n");
    // }
    // else
    // {
    //     write_data(asm_file);
    // }

    return 0;
}