#include "lineParserUtils.h"

// tip: don't hesitate to collapse/uncollapse the comment headers to make the code structure more obvious.

// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ PARSE DATA LINE ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // Function designed to parse the Data section
    int ParseLineData(char *line, DataSection_t *dataSection, SymbolTableNode_t **head) {
        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Syntax Checking Preparation⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // Create a copy of the passed line, for deeper checks
            char lineCopy[MAX_CHARS_PER_LINE];
            strcpy(lineCopy, line);      

            // Variables for tokenisation
            char *token;
            char label[MAX_MNEMO_LENGTH];

            int lineNum = dataSection->bytesCount;


        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Syntax Checking⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // Check if the line starts with a letter
            if (isalpha(line[0])) {
                
                // If it does, check for the presence of a colon
                if (strchr(lineCopy, ':') != NULL) {

                    // If there is one, extract the label up to the colon
                    token = strtok(line, ":");

                    // Take that label and check that it doesn't exceed max label length
                    if (token != NULL && strlen(token) <= MAX_MNEMO_LENGTH - 1) {

                        // Check each character of the label
                        for (int i = 0; i < (int)(strlen(token)); i++) {
                            char c = token[i];

                            // Check if use the characters allowed for labels
                            if (!(isalpha((unsigned char)c) || isdigit((unsigned char)c) || c == '_' || c == '-')) {

                                // If not, return error
                                printf(" ⚠️  Invalid character '%c' in label \"%s\" , line %d. Allowed characters (A-Z, a-z, 0-9 _ - )\n", c, token, lineNum);
                                return 1;
                            }
                        }

                        // If it doesn't, copy it to the label variable for further checking
                        strcpy(label, token);

                        // Check if it has already been declared in the symbol table
                        if (!isLabelExists(head, label)) {
                            
                            // If it hasn't, check for the presence of a directive by  using lineCopy for syntax check to preserve 
                            // original line formatting. Start by skipping the label and colon
                            char *directiveCheck = lineCopy + strlen(label) + 1;

                            // Skip whitespacses after the colon before checking for the directive dot
                            while (*directiveCheck && isspace(*directiveCheck)) {
                                directiveCheck++;
                            }

                            // Check if the first non-space character after the colon is effectively a dot
                            if (*directiveCheck == '.') {

                                // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Directive Logic Preparation⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
                                    // If dot has been found, let's move on to directive logic!
                                    // Skip the dot
                                    directiveCheck++; 

                                    // Point to the beginning of the directive
                                    char *directiveName = directiveCheck;

                                    // Find the end of the directive name (space or end of string)
                                    while (*directiveCheck && !isspace(*directiveCheck)) {
                                        directiveCheck++;
                                    }

                                    // Force null termination of sting
                                    *directiveCheck = '\0';

                                    // Known directives
                                    const char *knownDirectives[] = {"byte", "half", "word", "asciz", "alloc"};
                                    int knownDirectivesCount = sizeof(knownDirectives) / sizeof(knownDirectives[0]);
                                    int isDirectiveFound = 0;

                                    // Iterate through the array to see if it matches known directives
                                    for (int i = 0; i < knownDirectivesCount; i++) {
                                        if (strcmp(directiveName, knownDirectives[i]) == 0) {
                                            isDirectiveFound = 1;
                                            break;
                                        }
                                    }

                                    // If it matches, proceed with the directive-specific logic
                                    if (isDirectiveFound) {                                        

                                        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Directive-specific logic⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
                                            // ❑ .byte Directive ❑
                                                if (strcmp(directiveName, "byte") == 0) {

                                                    // Create a new variable (for consistency and readability) for syntax chacking
                                                    // This pointer will start after the directive
                                                    char *valuesStart = directiveCheck+1;

                                                    // Skip whitespaces after the directive
                                                    while (*valuesStart && isspace((unsigned char)*valuesStart)) valuesStart++;

                                                    // tokenise the string for comma separated values
                                                    char *byteValueStr = strtok(valuesStart, ",");

                                                    // We can handle a maximum of 512 values
                                                    int byteValues[ MAX_BYTE_ARRAY_DECLR ];

                                                    // Start the count at 0
                                                    int byteCount = 0;

                                                    // As long as there are values tokenised
                                                    while (byteValueStr) {

                                                        // Trim leading spaces for each value, if not yet trimmed, although redundant thanks to strtok (better be safe ok?)
                                                        while (isspace((unsigned char)*byteValueStr)) byteValueStr++;

                                                        // Trim trailing spaces going through the string and setting space chars to '\0'
                                                        char *trimmedByteValueStr = byteValueStr;
                                                        char *end = trimmedByteValueStr + strlen(trimmedByteValueStr) - 1;

                                                        // Keep doing it until we have reached a non space char
                                                        while(end > trimmedByteValueStr && isspace((unsigned char)*end)) {
                                                            *end = '\0';
                                                            end--;
                                                        }

                                                        // Initialise the future value
                                                        int byteValue;

                                                        // Check if it is in bounds and an integer
                                                        if (!isValidByteInt(trimmedByteValueStr, &byteValue)) {
                                                            printf("⚠️  Invalid byte value '%s' (must be an integer within [-128, 255]) (line %d), at position %d in array declaration\n", byteValueStr, lineNum, byteCount);
                                                            return 1;
                                                        }

                                                        // Store the byte value
                                                        byteValues[byteCount++] = byteValue;

                                                        // Move to the next byte value
                                                        byteValueStr = strtok(NULL, ",");
                                                    }

                                                    // Once all values extracted, if there are any:
                                                    if (byteCount > 0 && byteCount <= MAX_BYTE_ARRAY_DECLR ) {

                                                        // Check if there is enough Memory Left for writing all the values
                                                        // Compare if available memory is smaller than what is attempted to be written
                                                        if (MAX_DATA_MEMORY - dataSection->bytesCount >= byteCount){

                                                            // Hurray, we can finally write it to memory!

                                                            // proceed to write byte by byte
                                                            for (int i = 0; i < byteCount; i++){

                                                                // Fill the memory with the values 
                                                                dataSection->bytes[dataSection->bytesCount] = byteValues[i];

                                                                // Increment the bytes count by one byte
                                                                dataSection->bytesCount++;
                                                            }
                                                            
                                                            // Create an entry for that label at the current address in the lookup table
                                                            insertNode(head, label, lineNum);

                                                            return 0;

                                                        } 
                                                        // Otherwise, not enough memory left, throw an error:
                                                        else {
                                                            printf("⚠️  Not enough memory left for byte declaration! Need %d, Have %d\n", byteCount, MAX_DATA_MEMORY - dataSection->bytesCount);
                                                            return 1;
                                                        }
                                                    } 
                                                    // Otherwise, if there are too many values
                                                    else if (byteCount > MAX_BYTE_ARRAY_DECLR ){
                                                        printf("⚠️  Too many byte values found in declaration (must be <= 512) (line %d)\n", lineNum);
                                                        return 1;

                                                    }
                                                    // Otherwise, if there are none, return error:
                                                    else {
                                                        printf("⚠️  No valid byte values found (line %d)\n", lineNum);
                                                        return 1;
                                                    }
                                                }   



                                            // ❑ .half Directive ❑
                                                if (strcmp(directiveName, "half") == 0) {

                                                    // Create a new variable (for consistency and readability) for syntax chacking
                                                    // This pointer will start after the directive
                                                    char *valuesStart = directiveCheck+1;

                                                    // Skip whitespaces after the directive
                                                    while (*valuesStart && isspace((unsigned char)*valuesStart)) valuesStart++;

                                                    // tokenise the string for comma separated values
                                                    char *halfValueStr = strtok(valuesStart, ",");

                                                    // We can handle a maximum of 256 values
                                                    int halfValues[ MAX_HALF_ARRAY_DECLR ];

                                                    // Start the count at 0
                                                    int halfCount = 0;

                                                    // As long as there are values tokenised
                                                    while (halfValueStr) {

                                                        // Trim leading spaces for each value
                                                        while (isspace((unsigned char)*halfValueStr)) halfValueStr++;

                                                        // Trim trailing spaces going through the string and setting space chars to '\0'
                                                        char *trimmedHalfValueStr = halfValueStr;
                                                        char *end = trimmedHalfValueStr + strlen(trimmedHalfValueStr) - 1;

                                                        // Keep doing it until we have reached a non space char
                                                        while(end > trimmedHalfValueStr && isspace((unsigned char)*end)) {
                                                            *end = '\0';
                                                            end--;
                                                        }

                                                        // Initialise the future value
                                                        int halfValue;

                                                        // Check if it is in bounds and an integer
                                                        if (!isValidHalfInt(trimmedHalfValueStr, &halfValue)) {
                                                            printf("⚠️  Invalid half value '%s' (must be an integer within [-32768, 65535]) (line %d), at position %d in array declaration\n", halfValueStr, lineNum, halfCount);
                                                            return 1;
                                                        }

                                                        // Store the half value
                                                        halfValues[halfCount++] = halfValue;

                                                        // Move to the next half value
                                                        halfValueStr = strtok(NULL, ",");
                                                    }

                                                    // Once all values extracted, if there are any:
                                                    if (halfCount > 0 && halfCount <= MAX_HALF_ARRAY_DECLR ) {                                                        

                                                        // Check if there is enough Memory Left for writing all the values
                                                        // Compare if available memory is smaller than what is attempted to be written
                                                        if (MAX_DATA_MEMORY - dataSection->bytesCount >= halfCount * 2){

                                                            // Hurray, we can finally write it to memory!

                                                            // proceed to write byte by byte, we are splitting values into two bytes (Little Endian)
                                                            for (int i = 0; i < halfCount; i++){

                                                                // Lower Byte
                                                                dataSection->bytes[dataSection->bytesCount++] = (uint8_t)(halfValues[i] & 0xFF);

                                                                // Upper Byte
                                                                dataSection->bytes[dataSection->bytesCount++] = (uint8_t)((halfValues[i] >> 8) & 0xFF);
                                                            }

                                                            // Create an entry for that label at the current address in the lookup table
                                                            insertNode(head, label, lineNum);
                                                            
                                                            return 0;

                                                        } 
                                                        // Otherwise, not enough memory left, throw an error:
                                                        else {
                                                            printf("⚠️  Not enough memory left for half declaration! Need %d, Have %d\n", halfCount*2, MAX_DATA_MEMORY - dataSection->bytesCount);
                                                            return 1;
                                                        }
                                                    } 
                                                    // Otherwise, if there are too many values
                                                    else if (halfCount > MAX_HALF_ARRAY_DECLR ){
                                                        printf("⚠️  Too many half values found in declaration (must be <= 256) (line %d)\n", lineNum);
                                                        return 1;

                                                    }
                                                    // Otherwise, if there are none, return error:
                                                    else {
                                                        printf("⚠️  No valid half values found (line %d)\n", lineNum);
                                                        return 1;
                                                    }
                                                }



                                            // ❑ .word Directive ❑
                                                if (strcmp(directiveName, "word") == 0) {
                                                    
                                                    // Create a new variable (for consistency and readability) for syntax chacking
                                                    // This pointer will start after the directive
                                                    char *valuesStart = directiveCheck+1;

                                                    // Skip whitespaces after the directive
                                                    while (*valuesStart && isspace((unsigned char)*valuesStart)) valuesStart++;

                                                    // tokenise the string for comma separated values
                                                    char *wordValueStr = strtok(valuesStart, ",");

                                                    // We can handle a maximum of 128 values
                                                    int wordValues[ MAX_WORD_ARRAY_DECLR ];

                                                    // Start the count at 0
                                                    int wordCount = 0;

                                                    // As long as there are values tokenised
                                                    while (wordValueStr) {

                                                        // Trim leading spaces for each value
                                                        while (isspace((unsigned char)*wordValueStr)) wordValueStr++;

                                                        // Trim trailing spaces going through the string and setting space chars to '\0'
                                                        char *trimmedWordValueStr = wordValueStr;
                                                        char *end = trimmedWordValueStr + strlen(trimmedWordValueStr) - 1;

                                                        // Keep doing it until we have reached a non space char
                                                        while(end > trimmedWordValueStr && isspace((unsigned char)*end)) {
                                                            *end = '\0';
                                                            end--;
                                                        }

                                                        // Initialise the future value
                                                        int wordValue;

                                                        // Check if it is in bounds and an integer
                                                        if (!isValidWordInt(trimmedWordValueStr, &wordValue)) {
                                                            printf("⚠️  Invalid word value '%s' (must be an integer within [-2,147,483,648, 4294967295]) (line %d), at position %d in array declaration\n", wordValueStr, lineNum, wordCount);
                                                            return 1;
                                                        }

                                                        // Store the half value
                                                        wordValues[wordCount++] = wordValue;

                                                        // Move to the next half value
                                                        wordValueStr = strtok(NULL, ",");
                                                    }

                                                    // Once all values extracted, if there are any:
                                                    if (wordCount > 0 && wordCount <= MAX_WORD_ARRAY_DECLR ) {

                                                        // Check if there is enough Memory Left for writing all the values
                                                        // Compare if available memory is smaller than what is attempted to be written
                                                        if (MAX_DATA_MEMORY - dataSection->bytesCount >= wordCount * 4){

                                                            // Hurray, we can finally write it to memory!

                                                            // proceed to write byte by byte, we are splitting values into four bytes (Little Endian)
                                                            for (int i = 0; i < wordCount; i++){

                                                                // Least Significant Byte
                                                                dataSection->bytes[dataSection->bytesCount++] = (uint8_t)(wordValues[i] & 0xFF);
                                                                dataSection->bytes[dataSection->bytesCount++] = (uint8_t)((wordValues[i] >> 8) & 0xFF);
                                                                dataSection->bytes[dataSection->bytesCount++] = (uint8_t)((wordValues[i] >> 16) & 0xFF);
                                                                // Most significant byte
                                                                dataSection->bytes[dataSection->bytesCount++] = (uint8_t)((wordValues[i] >> 24) & 0xFF);
                                                            }

                                                            // Create an entry for that label at the current address in the lookup table
                                                            insertNode(head, label, lineNum);
                                                            
                                                            return 0;

                                                        } 
                                                        // Otherwise, not enough memory left, throw an error:
                                                        else {
                                                            printf("⚠️  Not enough memory left for word declaration! Need %d, Have %d\n", wordCount*4, MAX_DATA_MEMORY - dataSection->bytesCount);
                                                            return 1;
                                                        }
                                                    } 
                                                    // Otherwise, if there are too many values
                                                    else if (wordCount > MAX_WORD_ARRAY_DECLR ){
                                                        printf("⚠️  Too many word values found in word declaration (must be <= 128) (line %d)\n", lineNum);
                                                        return 1;

                                                    }
                                                    // Otherwise, if there are none, return error:
                                                    else {
                                                        printf("⚠️  No valid word values found (line %d)\n", lineNum);
                                                        return 1;
                                                    }
                                                }


                                            // ❑ .alloc Directive ❑
                                                if (strcmp(directiveName, "alloc") == 0) {

                                                    // Point to the start of the number of bytes to allocate
                                                    char *numBytesStr = directiveCheck + 1; 

                                                    // Variable for the amount of bytes to allocate
                                                    int numBytesToAlloc;

                                                    // strtol converts string to long, it uses endPtr to indicate where the conversion of the number stopped
                                                    char *endPtr;
                                                    long allocSize = strtol(numBytesStr, &endPtr, 10);

                                                    // if no digits found, or not a valid number or negative number, or exceeds MAX_DATA_MEMORY,
                                                    if (numBytesStr == endPtr || *endPtr != '\0' || allocSize < 0 || allocSize > MAX_DATA_MEMORY) {

                                                        // Then fail
                                                        printf("⚠️  Invalid allocation size '%s' (must be a non-negative integer and < 2048) (line %d)\n", numBytesStr, lineNum);
                                                        return 1;
                                                    }

                                                    // Otherwise, get that value from the previous conversion
                                                    numBytesToAlloc = (int)allocSize;


                                                    // Check if there is enough memory left for allocation
                                                    if (MAX_DATA_MEMORY - dataSection->bytesCount >= numBytesToAlloc) {
                                                        
                                                        // Simply increment the 'current address' to effectively reserve the requested space
                                                        dataSection->bytesCount += numBytesToAlloc;

                                                        // Create an entry for that label at the current address in the lookup table
                                                        insertNode(head, label, lineNum);

                                                        return 0;
                                                    } 
                                                    // Otherwise, not enough memory left
                                                    else {
                                                        printf("⚠️  Not enough memory left for allocation! Requested %d bytes, but only %d bytes available.\n", numBytesToAlloc, MAX_DATA_MEMORY - dataSection->bytesCount);
                                                        return 1;
                                                    }
                                                }


                                            // ❑ .asciz Directive ❑
                                                if (strcmp(directiveName, "asciz") == 0) {

                                                    // Point to start of the string value
                                                    char *stringValueStart = directiveCheck + 1;

                                                    // Skip whitespaces to find the beginning quote of the string
                                                    while (*stringValueStart && isspace((unsigned char)*stringValueStart)) stringValueStart++;

                                                    // Check if string starts with a quote 
                                                    if (*stringValueStart != '"') {
                                                        printf("⚠️  String must start with a quote (line %d)\n", lineNum);
                                                        return 1;
                                                    }

                                                    // Move to next char
                                                    stringValueStart++;
                                                    
                                                    // Find the second quote
                                                    char *stringValueEnd = strchr(stringValueStart, '"');

                                                    // If none found, throw error
                                                    if (!stringValueEnd) {
                                                        printf("⚠️  String must end with a quote (line %d)\n", lineNum);
                                                        return 1;
                                                    }

                                                    // Otherwise, trim trailing whitespaces
                                                    char *lineEnd = stringValueEnd + 1; 
                                                    while (*lineEnd && isspace((unsigned char)*lineEnd)) lineEnd++;

                                                    // Ensure there are no extra characters after the last quote (except for whitespaces which are now trimmed)
                                                    if (*lineEnd != '\0') {
                                                        printf("⚠️  Extra characters found outside of string quotes (line %d)\n", lineNum);
                                                        return 1;
                                                    }

                                                    // Check if there's enough memory to store the string and the null terminator
                                                    int stringLength = stringValueEnd - stringValueStart;
                                                    if (MAX_DATA_MEMORY - dataSection->bytesCount < stringLength + 1) {
                                                        printf("⚠️  Not enough memory to store the string (line %d)\n", lineNum);
                                                        return 1;
                                                    }

                                                    // For each char in the string:
                                                    for (int i = 0; i < stringLength; i++) {

                                                        // Ensure that they are an ASCII character
                                                        if (!isascii(stringValueStart[i])) {

                                                            // If they aren't, fail
                                                            printf("⚠️  String contains non-ASCII characters (line %d)\n", lineNum);
                                                            return 1;
                                                        }

                                                        // If they are, write them.
                                                        dataSection->bytes[dataSection->bytesCount++] = stringValueStart[i];
                                                    }

                                                    // Append the null terminator to the string in memory
                                                    dataSection->bytes[dataSection->bytesCount++] = '\0';

                                                    // Create an entry for that label at the current address in the lookup table
                                                    insertNode(head, label, lineNum);

                                                    return 0;
                                                }
                                    }
                                    // If there is no match, return an error
                                    else {
                                        // Directive does not match any known directives
                                        printf("⚠️  Directive '%s' isn't recognised, line %d\n", directiveName, lineNum);
                                        return 1;
                                    }
                            } 
                            // Otherwise, the line is missing a dot
                            else {
                                printf("⚠️  Missing '.' for directive after label name (line %d)\n", lineNum);
                                return 1;
                            }
                        } 
                        // Otherwise, the label has already been declared
                        else {
                            printf("⚠️  Label name (%s) has already been declared in data section (line %d)\n", label, lineNum);
                            return 1;
                        }
                    } 
                    // Otherwise, the label exceeds the max length
                    else {
                        printf("⚠️  Label name exceeds 49 characters, please rename it to a shorter name (line %d)\n", lineNum);
                        return 1;
                    }
                }
                // Otherwise, declaration is missing the colon operator
                else {
                    printf("⚠️  Missing ':' after Label Declaration (line %d)\n", lineNum);
                    return 1;
                }
            } 
            // Otherwise, the label name doesn't start with a letter
            else {
                printf("⚠️  The label name must start with a letter (line %d)\n", lineNum);
                return 1;
            }        
            return 0;
    }




// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ PARSE CODE LINE⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // Function designed to the the first pass on the unresolved code section.
    int ParseLineCode (char *line, SymbolTableNode_t **head, SymbolTableNode_t **head2, UnresolvedInstructions_t *unresolvedInstructions){

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Discarding Comments⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            
            // Skip leading whitespace characters
            int i = 0, j = 0;
            while (line[i] == ' ' || line[i] == '\t') {
                i++;
            }

            // Shift text to the beginning of the line
            if (i > 0) {
                while (line[i]) {
                    line[j++] = line[i++];
                }
                line[j] = '\0'; // Null-terminate the shifted string
            }

            // Find the start of a comment, if present, and truncate it
            char *commentStart = strstr(line, "//");
            if (commentStart) {

                // Cut off the comment part
                *commentStart = '\0'; 
            }

            // Check if the line is empty after removing comments and trimming whitespace
            if (strlen(line) == 0) {

                // If the line is empty, skip the printing process and continue with next line
                return 0; 
            }        


        // Set address to current line number in array of unresolved (yet) instructions
        int currentAddress = unresolvedInstructions->count;

        // Check if the line starts with a letter
        if (isalpha(line[0])) {

            // Create a copy of the passed line, for deeper checks
            char lineCopy[MAX_CHARS_PER_LINE]; 
            strcpy(lineCopy, line);      

            // Variables for tokenisation
            char *token;
            char label[MAX_MNEMO_LENGTH];

            // If it does, check for the presence of a colon, in which case it is a label
            if (strchr(lineCopy, ':') != NULL) {

                // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Handling Labels⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
                    // IMRPOVEMENTS : Reduce the nesting of checks for improved readability
                    
                    // If there is one, extract the label up to the colon
                    token = strtok(line, ":");


                    // Take that label and check that it doesn't exceed max label length
                    if (token != NULL && strlen(token) <= MAX_MNEMO_LENGTH - 1) {

                        // Check each character of the label
                        for (int i = 0; i < (int)(strlen(token)); i++) {
                            char c = token[i];

                            // Check if use the characters allowed for labels
                            if (!(isalpha((unsigned char)c) || isdigit((unsigned char)c) || c == '_' || c == '-')) {

                                // If not, return error
                                printf(" ⚠️  Invalid character '%c' in label \"%s\" , line %d. Allowed characters (A-Z, a-z, 0-9 _ - )\n", c, token, currentAddress);
                                return 1;
                            }
                        }

                        // If it is of correct length and contains only valid characters, procees
                        strcpy(label, token);

                        // Check if it has already been declared in the symbol tables
                        if (!(isLabelExists(head2, label) || isLabelExists(head, label))) {

                            // If it hasn't, Add it to the code symbol table
                            insertNode(head2, label, currentAddress*4); // USED TO BE CURRENT ADDRESS *32

                            // Move on to the next line
                            return 0;


                        }

                        // Otherwise, the label has already been declared
                        else {
                            printf("⚠️  Label name (%s) has already been declared in a symbol table (line %d)\n", label, currentAddress);
                            return 1;
                        }
                    }

                    // Otherwise, the label exceeds the max length
                    else {
                        printf("⚠️  Label: %s exceeds 49 characters, please rename it to a shorter name (line %d)\n", token, currentAddress);
                        return 1;
                    }
            }


                // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Handling Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
                    // Otherwise, it is an instruction
                    else {
                        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Instruction Preparation⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○

                            // Instantiate an instruction
                            Instruction_t instruction;

                            // Init the structure with zeros
                            memset(&instruction, 0, sizeof(Instruction_t));


                            // +++++++++ DEBUG +++++++++
                            /*
                            if (DBG) {
                                printf("\n");
                                // // usleep(250000);
                                printf("%s\n", line);
                            }
                            */

                            // Make a copy of the line for further processing
                            char lineCopy[MAX_CHARS_PER_LINE];
                            strcpy(lineCopy, line); 

                            // tokenise the instruction
                            // Array to hold pointers to the tokens
                            char *tokens[MAX_TOKENS];
                            int tokenCount = 0;

                            // Use strtok to tokenise the string
                            char *token = strtok(lineCopy, " ,");

                            // Keep tokenising
                            while (token != NULL && tokenCount < MAX_TOKENS) {

                                // Store the Token,
                                tokens[tokenCount++] = token;

                                // Get the next one
                                token = strtok(NULL, " ,");
                            }

                        // Match First token to known instructions to see if it exists
                        InstructionName_t instructionName = findMnemonic(tokens[0]);

                        // If matching function returned ERR, it means instruction wasn't found, in which case, throw an error
                        if (instructionName == ERR){
                            printf(" ⚠️  Instruction (%s) isn't specified. \n", tokens[0]);
                            return 1;
                        }

                        // +++++++++ DEBUG +++++++++
                        // if (DBG) {
                        //     // // // usleep(250000);
                        //     for (int i = 0; i < tokenCount; i++) {
                        //         printf("    Token %d: %s\n", i, tokens[i]);
                        //     }
                        // }


                        int exception = 0;
                        int isInstructionNotValidated = 0;
                        int isInstructionNotBuilt = 0;
                        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Instruction Specific Logic⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○

                            switch(instructionName) {
                            // ❑ ADD ❑
                                case ADD: {
                                    
                                    // Check if the tokens match what we are supposed to have
                                    isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 0, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 0, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ ADDI ❑
                                case ADDI: {
                                    
                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 1, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 1, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ SUB ❑
                                case SUB: {

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 2, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 2, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ AND ❑
                                case AND: {
                                    // Handle AND

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 3, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 3, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ ANDI ❑
                                case ANDI: {
                                    // Handle ANDI

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 4, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 4, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ OR ❑
                                case OR: {
                                    // Handle OR

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 5, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 5, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;
                                    
                                    break;
                                }
                            // ❑ ORI ❑
                                case ORI: {
                                    // Handle ORI

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 6, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 6, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ XOR ❑
                                case XOR: {
                                    // Handle XOR

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 7, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 7, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;
                                    
                                    break;
                                }
                            // ❑ XORI ❑
                                case XORI: {
                                    // Handle XORI

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 8, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 8, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ SLL ❑
                                case SLL: {
                                    // Handle SLL

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 9, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 9, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ SLLI ❑
                                case SLLI: {
                                    // Handle SLLI

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 10, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 10, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ SRL ❑
                                case SRL: {
                                    // Handle SRL

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 11, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 11, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ SRLI ❑
                                case SRLI: {
                                    // Handle SRLI

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 12, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 12, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ SRA ❑
                                case SRA: {
                                    // Handle SRA

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 13, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 13, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ SRAI ❑
                                case SRAI: {
                                    // Handle SRAI

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 14, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 14, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ ILT ❑
                                case ILT: {
                                    // Handle ILT

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 15, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 15, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ ILTI ❑
                                case ILTI: {
                                    // Handle ILTI

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 16, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 16, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ ILTU ❑
                                case ILTU: {
                                    // Handle ILTU

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 17, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 17, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ ILTUI ❑
                                case ILTUI: {
                                    // Handle ILTUI

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 18, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 18, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ JIE ❑
                                case JIE: {
                                    // Handle JIE

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 19, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 19, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // printf("❗️🤖 - Needs Resolved: %s\n", unresolvedInstructions->instructions[currentAddress].needsResolve);

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ JINE ❑
                                case JINE: {
                                    // Handle JINE

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 20, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 20, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ JIGE ❑
                                case JIGE: {
                                    // Handle JIGE

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 21, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 21, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ JIGEU ❑
                                case JIGEU: {
                                    // Handle JIGEU

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 22, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 22, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ JILE ❑
                                case JILE: {
                                    // Handle JILE

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 23, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 23, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ JILEU ❑
                                case JILEU: {
                                    // Handle JILEU

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 24, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens,24, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ LUI ❑
                                case LUI: {
                                    // Handle LUI

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 25, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 25, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ AUIPC ❑
                                case AUIPC: {
                                    // Handle AUIPC

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 26, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 26, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ JAL ❑
                                case JAL: {
                                    // Handle JAL

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 27, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 27, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ JALR ❑
                                case JALR: {
                                    // Handle JALR

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 28, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 28, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ LB ❑
                                case LB: {
                                    // Handle LB

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 29, currentAddress);

                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 29, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;


                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ LH ❑
                                case LH: {
                                    // Handle LH

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 30, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 30, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ LW ❑
                                case LW: {
                                    // Handle LW

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 31, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 31, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ LBU ❑
                                case LBU: {
                                    // Handle LBU

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 32, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 32, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ LHU ❑
                                case LHU: {
                                    // Handle LHU

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 33, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 33, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ SB ❑
                                case SB: {
                                    // Handle SB

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 34, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 34, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ SH ❑
                                case SH: {
                                    // Handle SH

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 35, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 35, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ SW ❑
                                case SW: {
                                    // Handle SW

                                    // Check if the tokens match what we are supposed to have
                                    int isInstructionNotValidated = isValidInstruction(tokens, tokenCount, 36, currentAddress);

                                    // Break if exception caught or instruction invalid
                                    if (isInstructionNotValidated){
                                        exception = 1;
                                        break;
                                    }

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 36, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Otherwise, we can add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;

                                    break;
                                }
                            // ❑ SYSCALL ❑
                                case SYSCALL: {
                                    // Handle SYSCALL

                                    // If Instruction is valid, however, add it to the list of unresolved instructions
                                    isInstructionNotBuilt = buildInstructions(tokens, 37, currentAddress, &instruction);

                                    // Break if exception caught or instruction build failed
                                    if (isInstructionNotBuilt){
                                        exception = 1;
                                        break;
                                    }

                                    // Add it to the unresolved instructions list!
                                    unresolvedInstructions->instructions[currentAddress] = instruction;

                                    // Increment the count of instructions (and current address subsequently)
                                    unresolvedInstructions->count++;
                                }
                                default:
                                    // o.O?
                                    break;
                            }

                        // Halt execution if exception caught
                        if (exception){
                            return 1;
                        }

                        // If no error...
                        return 0;

                    }


            
            }
        // Otherwise, the Label/Instruction name doesn't start with a letter
        else {
            printf("⚠️  Label/Instruction name must start with a letter (line %d)\n", currentAddress);
            return 1;
        }     

        // So far so good...   
        return 0;
    }