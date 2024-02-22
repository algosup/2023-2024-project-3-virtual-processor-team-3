#include "general.h"
#include "preprocessor.h"
#include "assembler.h"
#include "processor.h"

int main(int argc, char *argv[])
{

    // Check if command-line arguments are correct
    int argument = checkArgs(argc, argv);
    char *bin;

    // Depending on the argument, call either the assembler, the processor or both of them
    switch (argument)
    {
    case 1:
        preprocessing(argv[2]); // Call the preprocessor
        assembling(argv[2]);    // Call the assembler TO DO: CHANGE THE FUNCTION CALL

        // Remove all temporary files
        remove("./data.txt");
        remove("./code.txt");

        printf("Preprocessing done");
        break;
    case 2:
        processing(argv[2]); // Call the processor TO DO: CHANGE THE FUNCTION CALL
        break;
    case 3:
        preprocessing(argv[2]); // Call the preprocessor
        assembling(argv[2]); // Call the assembler TO DO: CHANGE THE FUNCTION CALL

        // Remove all temporary files
        remove("./data.txt");
        remove("./code.txt");

        bin = strtok(argv[2], ".");
        bin = strcat(bin, ".bin");
        processing(bin); // Call the processor TO DO: CHANGE THE FUNCTION CALL
        break;
    default:
        break;
    }

    return 0;
}
