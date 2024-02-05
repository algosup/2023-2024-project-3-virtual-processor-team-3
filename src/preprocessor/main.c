#include "preprocessor.h"

int main()
{
    FILE *asm_file = fopen("asm.txt", "r");
    write_data(asm_file);
    write_code(asm_file);

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