// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ PRE-PROCESSING FUNCTIONS ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
// TODO: CHECK ALL COMMENTS
// ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Does File End with Empty Line?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
    // Check if file ends with an empty line
    int endsWithNonEmptyLine(FILE *file) {
        // Go to the end of the file
        if (fseek(file, 0, SEEK_END) != 0) {
            // If Seek fails
            perror(" ⚠️  Preprocessor: Failed to seek to end of file");
            return 1; // Indicate failure
        }

        // Get the size of the file in bytes
        long fileSize = ftell(file); 

        // In case getting the filesize fails
        if (fileSize == -1) {
            perror(" ⚠️  Preprocessor: Failed to tell file position");
            return 1; // Indicate failure
        }

        // Start from the end of the file and move backwards
        for (long i = fileSize - 1; i >= 0; i--) {

            // Point from the beginning of the file to byte i
            fseek(file, i, SEEK_SET);

            // Read the character at byte[i]
            int ch = fgetc(file);

            // Check for newline character
            if (ch == '\n') {

                
                if (i == fileSize - 1 || (i > 0 && (fseek(file, i - 1, SEEK_SET) == 0 && (ch = fgetc(file), ch == '\r' || ch == '\n')))) {
                    // The file ends with an empty line
                    return 0; // Indicate success
                } else {
                    // The newline is not at the end or not followed by another newline/carriage return
                    printf(" ⚠️  Preprocessor: The file does not end with an empty line.\nPlease add a line return after your last line of code to indicate the end of the program.\n\n");
                    return 1; // Indicate failure
                }
            } else if (ch != '\0') {
                // Found a non-null and non-newline character, so the file does not end with an empty line
                printf(" ⚠️  Preprocessor: The file does not end with an empty line.\nPlease add a line return after your last line of code to indicate the end of the program.\n\n");
                return 1; // Indicate failure
            }
            // If the character is '\0', continue looping to skip over any trailing null characters
        }
        printf(" ⚠️  Preprocessor: The file does not end with an empty line.\nPlease add a line return after your last line of code to indicate the end of the program.\n\n");
        return 1; // The file is either empty or does not end with an empty line, indicating failure
    }

// ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Check for .code⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
    // Check if the code directive is indeed present somewhere in the file
    int isCodeDirectiveNotPresent(FILE *file) {

        // Rewind the pointer that was at the end of the file
        rewind(file);

        // Create a buffer line that will.. Hold the line! 🎶 Love is not always on time! 🎶
        char line[MAX_CHAR_PER_LINE_AMNT];

        while (fgets(line, sizeof(line), file) != NULL) {
            // Create a pointer to start pointing to characters
            char* ptr = line;

            // Skip the trailing whitespaces
            while (*ptr && isspace((unsigned char)*ptr)) ptr++;

            // Check if the line starts with ".code"
            if (strncmp(ptr, ".code", 5) == 0){
                
                // Move the start pointer past it
                ptr += 5;

                // Check if the rest of the line contains only whitespaces or is a newline
                while (*ptr){
                    
                    // If a non-whitespace chararcter is found
                    if (!isspace((unsigned char)*ptr)){

                        // Return an error
                        printf(" ⚠️  Found a non-whitespace character: '%c' following the \".code\" declaration.\nPlease ensure this line contains nothing other than the \".code\" directive.\n", *ptr);
                        return 1;
                    }

                    // Otherwise, keep going
                    ptr++;

                }

                // If no return until now, we are good to go
                return 0;

            }

        }

        // If we are done scrolling through the file and that it still hasn't been found, then it doesn't exist
        printf(" ⚠️  Preprocessor: Couldn't find \".code\" section in your program.\nPlease ensure you have declared it.\n");
        return 1; 
    }

// ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Is there another .code declared in the file?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
    // Find whether ".code" has been declared more than once
    int isCodeDirectiveNotUnique(FILE *file) {

        // Create a buffer line
        char line[MAX_CHAR_PER_LINE_AMNT];

        // Create a line tracker
        int lineNumber = 0;

        // Number of times ".code" has been found
        int foundCode = 0; 

        // Rewind the file pointer
        rewind(file);

        // For each line
        while (fgets(line, sizeof(line), file) != NULL) {

            // Increment lineNumber to keep track of the lines
            lineNumber++;
            
            char* ptr = line;

            // Skip whitespaces
            while (*ptr && isspace((unsigned char)*ptr)) {++ptr;}

            // Check if trimmed line starts with ".code"
            if (strncmp(ptr, ".code", 5) == 0) {

                // If it has already been found at least once
                if (foundCode) {
                    
                    // Return an error
                    printf(" ⚠️  Preprocessor: Directive \".code\" declared more than once.\nFound an extra declaration at line %d\n", lineNumber);
                    return 1;
                }

                // Mark it as found once
                foundCode = 1;
            }
        }

        // If we reach the end of the file and foundCode is still 1, there was only one ".code"
        return foundCode ? 0 : 1;
    }