#include "preprocessor.h"

int main(int argc, char* argv[])
{
    checkArgs(argc,argv);
    FILE *asmFile;
    if (asmFile = fopen(argv[2], "r"))
    {
        sectionNotFound(asmFile);
        writeData(asmFile);
        writeCode(asmFile);
    }
    else{
        errorsHandler(0);
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