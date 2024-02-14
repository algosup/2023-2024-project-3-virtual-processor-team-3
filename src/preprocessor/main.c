#include "preprocessor.h"

int main(int argc, char* argv[])
{
    checkArgs(argc,argv);
    FILE *asmFile;
    if (asmFile = fopen(argv[2], "r"))
    {
        sectionNotFound(asmFile);
        // writeData(asmFile);
        // writeCode(asmFile);
    }
    else{
        errorsHandler(0);
    }
    incorrectSection(asmFile);
    isComment(asmFile);
    fclose(asmFile);
    FILE *noCommentsFile = fopen("./temp_files/noComments.txt", "r");
    writeData(noCommentsFile);
    writeCode(noCommentsFile);
    fclose(noCommentsFile);

    return 0;
}