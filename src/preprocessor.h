#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include "general.h"
#include "errors.h"

/**
 * This functions creates a new file named data.txt.
 * @param file(FILE pointer): A pointer to an assembly file.
 * @result Create a new file with all lines in the data section without it's comments.
 */
void writeData(FILE *file)
{
    rewind(file); // Move the file pointer to the beginning of the file
    char line[100];
    FILE *dataFile = fopen("./data.txt", "w");

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, ".data"))
        {
            // Write each line to the data file until it encounters a ".code" directive
            while (fgets(line, sizeof(line), file) && strstr(line, ".code") == NULL)
            {
                char *noIntendLine = suppressIndentation(line);
                if (removeBlanks(noIntendLine) == 0)
                {
                    continue;
                }
                fprintf(dataFile, "%s", noIntendLine);
            }
        }
    }

    fclose(dataFile);
}

/**
 * This function creates a new text file named code.txt
 * @param file (File pointer): A pointer to an assembly file.
 * @result A new temporary file which contains all lines present in the section code, without comments.
 */
void writeCode(FILE *file)
{
    rewind(file); // Move the file pointer to the beginning of the file
    char line[100];
    FILE *codeFile = fopen("./code.txt", "w"); // Open in append mode

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, ".code"))
        {

            // Write each line to the code file starting from the line after ".code" directive
            while (fgets(line, sizeof(line), file))
            {
                char *noIntendLine = suppressIndentation(line);
                if (removeBlanks(noIntendLine) == 0)
                {
                    continue;
                }
                fprintf(codeFile, "%s", noIntendLine);
            }
            break; // Exit the loop after writing the code section
        }
    }

    fclose(codeFile);
}

/**
 * This functions removes all comments in the assembly file.
 * @param asm_file(FILE pointer): A pointer to an assembly file.
 * @result Create a file with no comments.
 */
void isComment(FILE *asm_file)
{
    rewind(asm_file); // Move the file pointer to the beginning of the file
    char line[100];
    FILE *noCommentsFile = fopen("./noComments.txt", "w"); // Open in append mode

    while (fgets(line, sizeof(line), asm_file))
    {
        char *commentStart = strstr(line, "//");

        if (commentStart != NULL)
        {
            // Single-line comment found, truncate the line at the comment
            *commentStart = '\0';
            fprintf(noCommentsFile, "%s \n", line);
        }
        else
        {
            // No comment found, write the line as is
            fprintf(noCommentsFile, "%s", line);
        }
    }

    fclose(noCommentsFile); // Close the file after writing
}


/**
 * This function executes the preprocessing on a given file.
 * @param file (char pointer): A .gras file containing ALGORISK assembly.
 * @result Creates two different temporary files needed for the assembler.
*/
void preprocessing(char *file)
{

    // Open the assembly file
    FILE *asmFile = fopen(file, "r");
    if (!asmFile)
    {
        errorsHandler(0, 0, " "); // File not found error
    }

    // Process the assembly file
    sectionNotFound(asmFile);  // Check for .data or .code sections
    incorrectSection(asmFile); // Check for incorrect sections
    isComment(asmFile);        // Remove comments
    fclose(asmFile);

    // Open the file with no comments for further processing
    FILE *noCommentsFile = fopen("./noComments.txt", "r");
    if (!noCommentsFile)
    {
        errorsHandler(0, 0, " "); // File not found error
    }

    // Create separate files for data and code sections
    writeData(noCommentsFile);             // Create data file
    writeCode(noCommentsFile);             // Create code file
    fclose(noCommentsFile);
    remove("./noComments.txt"); // Remove the file with no comments
}

#endif