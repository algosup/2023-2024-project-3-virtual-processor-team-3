#include "preprocessor.h"

int main(int argc, char *argv[])
{
    checkArgs(argc, argv); // Check if arguments are correct
    FILE *asmFile;

    if (asmFile = fopen(argv[2], "r")) // If file not found, return error
    {
        sectionNotFound(asmFile);  // Check if there are .data or .code sections
        incorrectSection(asmFile); // Check if there are incorrect sections
        isComment(asmFile);        // Remove comments
        fclose(asmFile);

        FILE *noCommentsFile = fopen("./temp_files/noComments.txt", "r");
        writeData(noCommentsFile); // Create data file
        writeCode(noCommentsFile); // Create code file
        fclose(noCommentsFile);
    }
    else
    {
        errorsHandler(0, 0, " ");
    }

    return 0;
}