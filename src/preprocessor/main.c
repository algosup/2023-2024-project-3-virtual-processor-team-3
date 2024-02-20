#include "preprocessor.h"

int main(int argc, char *argv[]) {
    // Check if command-line arguments are correct
    checkArgs(argc, argv);

    // Open the assembly file
    FILE *asmFile = fopen(argv[2], "r");
    if (!asmFile) {
        errorsHandler(0, 0, " "); // File not found error
    }

    // Process the assembly file
    sectionNotFound(asmFile);  // Check for .data or .code sections
    incorrectSection(asmFile); // Check for incorrect sections
    isComment(asmFile);        // Remove comments
    fclose(asmFile);

    // Open the file with no comments for further processing
    FILE *noCommentsFile = fopen("./temp_files/noComments.txt", "r");
    if (!noCommentsFile) {
        errorsHandler(0, 0, " "); // File not found error
    }

    // Create separate files for data and code sections
    writeData(noCommentsFile); // Create data file
    writeCode(noCommentsFile); // Create code file
    remove("./temp_files/noComments.txt"); // Remove the file with no comments

    return 0;
}
