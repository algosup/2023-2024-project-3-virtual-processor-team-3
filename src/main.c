#include "general.h"
#include "preprocessor.h"
#include "assembler.h"
#include "processor.h"

int main(int argc, char *argv[])
{

    // Check if command-line arguments are correct
    int argument = checkArgs(argc, argv);
    char *grml;

    // Depending on the argument, call either the assembler, the processor or both of them
    switch (argument)
    {
    case 1:
        preprocessing(argv[2]); // Call the preprocessor
        assembling(argv[2]);    // Call the assembler

        // Remove all temporary files
        remove("./data.txt");
        remove("./code.txt");

        printf("Preprocessing done");
        break;
    case 2:
        processing(argv[2]); // Call the processor 
        break;
    case 3:
        preprocessing(argv[2]); // Call the preprocessor
        assembling(argv[2]); // Call the assembler 

        // Remove all temporary files
        remove("./data.txt");
        remove("./code.txt");

        grml = strtok(argv[2], ".");
        grml = strcat(grml, ".grml");
        processing(grml); // Call the processor 
        break;
    default:
        break;
    }

    return 0;
}
