/**
 *This function extracts the text present is a file.
 *@param filepath (char pointer): The path of the file to read.
 *@param LineNumber (int): The number of the line to read.
 *@result (Line_t) A struct containing the line number, a string of 100 char to contain a line, and an int to handle errors.
 */


/*
- We need to open a file containing assembly instructions 
- We need to strip commments out (anything between a "//"" and that ends with a line return
- We need to handle assembly directives, macros and etc
- We need to craft instructions once every single bit of preprocessing is done
- We need to serialize it in binary.

*/

/*
#include <stdio.h>

int read (char fileName[])
{
    printf("%s", fileName);
    return 1;
}

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define max line length as 1024
#define MAX_LINE_LENGTH 1024

// Helper function to trim trailing whitespaces
void trimRight(char *str) {
    int end = strlen(str) - 1;
    while (end >= 0 && isspace((unsigned char) str[end])) {
        end--;
    }
    str[end + 1] = '\0';
}

// READ function :: takes a filename
int read(const char *filename) {

    // Open the source assembly file with fopen in read-only mode
    FILE *inputFile = fopen(filename, "r");

    // Handle file opening error
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 0;
    }

    // Create the file for writing the outpur
    FILE *outputFile = fopen("asmOutput.txt", "w");

    // Handle error creating that file
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 0;
    }

    // a "line" is a character array of 1024 long
    char line[MAX_LINE_LENGTH];

    // Iterate over the lines
    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {

        // find the first occurrence of a comment "//"
        char *comment_start = strstr(line, "//");

        // Delete content by terminating the string at beginning
        if (comment_start != NULL) {
            *comment_start = '\0'; 
        }

        // Remove trailing whitespaces
        trimRight(line);

        // Output the result to a file
        fprintf(outputFile, "%s\n", line);
    }

    // close all open files to free up memory
    fclose(inputFile);
    fclose(outputFile);
    return 1;
}


