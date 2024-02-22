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
 * This functions turns every characters in a string into lower cases characters.
 * @param line (char pointer): A string representing a line.
 * @result The input string with uppercase characters changed into lowercase.
 */
char *removeBlanks(char *line)
{
    for (char *character = line; *character; character++)
    {
        *character = tolower(*character); 
    }
    return line;
}

#endif