#ifndef STR_MANIPULATION_H
#define STR_MANIPULATION_H

#include <string.h>

/**
 * This functions returns the position of the first character other than spaces.
 * @param line(char pointer): A pointer to a char.
 * @result The index of the first character other than a space.
 */
char *suppressIndentation(char *line)
{
    // Find the index of the first non-whitespace character
    int index = 0;
    while (line[index] == ' ' || line[index] == '\t')
    {
        index++;
    }

    char *noIntendLine = &line[index];
    return noIntendLine;
}

/**
 * This functions checks if a line is empty or not.
 * @param line (char pointer): A string representing a line.
 * @result The line if it contains anything or nothing if there is nothing but a line feed.
 */
char *removeBlanks(char *line)
{
    if (strcmp(line, "\n") == 0)
    {
        return NULL;
    }
    return line;
}

#endif