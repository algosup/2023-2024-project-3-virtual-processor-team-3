// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ FILE FORMAT ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Aren't lines too long?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Check if the lines aren't longer than MAX_CHARS_PER_LINE
        int isLineTooLong(FILE *file) {
            // Rewind the file to ensure we start from the beginning
            rewind(file);

            // Buffer to hold each line (+ null terminator and EOF)
            char line[MAX_CHARS_PER_LINE + 2];

            // Variable to track line numbers
            int lineNumber = 0;

            // Variable to track whether an error was found
            int errorFound = 0;

            while (fgets(line, sizeof(line), file) != NULL) {
                lineNumber++; // Increment the line number

                // Check if the line is potentially longer than allowed
                if (strlen(line) > 0 && line[strlen(line) - 1] != '\n') {
                    int charCount = 0; // Counter for extra characters
                    int c;

                    // Continue reading the line to count extra characters
                    while ((c = fgetc(file)) != EOF && c != '\n') {

                        // Increment for each extra character
                        charCount++;
                    }

                    // Report the exact number of extra characters
                    printf(" ⚠️  Line %d exceeds the %d character per-line limit by %d character(s).\nPlease split it into multiple declarations.\n", lineNumber, MAX_CHARS_PER_LINE, charCount+1);
                    errorFound = 1; // Mark that an error was found
                }
            }

            // Return 1 if no error was found, 0 otherwise
            return !errorFound;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Does File End with Empty Line?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Check if file ends with an empty line
        int endsWithEmptyLine(FILE *file) {
            // Go to the end of the file
            if (fseek(file, 0, SEEK_END) != 0) {
                // If Seek fails
                perror(" ⚠️  Preprocessor: Failed to seek to end of file");
                return 0; // Indicate failure
            }

            // Get the size of the file in bytes
            long fileSize = ftell(file); 

            // In case getting the filesize fails
            if (fileSize == -1) {
                perror(" ⚠️  Preprocessor: Failed to tell file position");
                return 0; // Indicate failure
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
                        return 1; // Indicate success
                    } else {
                        // The newline is not at the end or not followed by another newline/carriage return
                        printf(" ⚠️  Preprocessor: The file does not end with an empty line.\nPlease add a line return after your last line of code to indicate the end of the program.\n\n");
                        return 0; // Indicate failure
                    }
                } else if (ch != '\0') {
                    // Found a non-null and non-newline character, so the file does not end with an empty line
                    printf(" ⚠️  Preprocessor: The file does not end with an empty line.\nPlease add a line return after your last line of code to indicate the end of the program.\n\n");
                    return 0; // Indicate failure
                }
                // If the character is '\0', continue looping to skip over any trailing null characters
            }
            printf(" ⚠️  Preprocessor: The file does not end with an empty line.\nPlease add a line return after your last line of code to indicate the end of the program.\n\n");
            return 0; // The file is either empty or does not end with an empty line, indicating failure
        }
// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ CODE DIRECTIVE ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Check for .code⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Check if the code directive is indeed present somewhere in the file and returns its position
        int isCodeDirectivePresent(FILE *file) {

            // Rewind the pointer that was at the end of the file
            rewind(file);

            // Create a buffer line that will.. Hold the line! 🎶 Love is not always on time! 🎶
            char line[MAX_CHARS_PER_LINE];

            // Create a line tracker
            int lineNumber = 0;

            while (fgets(line, sizeof(line), file) != NULL) {

                // Create a pointer to start pointing to characters
                char* ptr = line;

                // Increment the line number
                lineNumber++;

                // Skip the trailing whitespaces
                while (*ptr && isspace((unsigned char)*ptr)) ptr++;

                // Check if the line starts with ".code" 
                if (strncmp(ptr, ".code", 5) == 0){
                    
                    // Move the start pointer past it
                    ptr += 5;

                    // Skip whitespaces
                    while (*ptr && isspace((unsigned char)*ptr)) ptr++;

                    // Check if what follows is a comment
                    if (strncmp(ptr, "//", 2) == 0 || *ptr == '\0') {

                        // If it's a comment or the end of the line, the directive is valid
                        return lineNumber;
                    } 
                    
                    // Otherwise, there is an invalid character
                    else {
                        printf(" ⚠️  Preprocessor: Invalid character '%c' after \".code\" directive, line: %d.\nOnly comments starting with \"//\" are allowed on the same line as a section declaration.\n", *ptr, lineNumber);
                        return 0;
                    }
                }
            }

            // If we are done scrolling through the file and that it still hasn't been found, then it doesn't exist
            printf(" ⚠️  Preprocessor: Couldn't find \".code\" section in your program.\nPlease ensure you have declared it.\n");
            return 0; 
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Is there another .code declared in the file?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Find whether ".code" has been declared more than once
        int isCodeDirectiveUnique(FILE *file) {

            // Create a buffer line
            char line[MAX_CHARS_PER_LINE];

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
                        printf(" ⚠️  Preprocessor: Directive \".code\" declared more than once.\nFound a duplicate declaration at line %d\n", lineNumber);
                        return 0;
                    }

                    // Mark it as found once
                    foundCode = 1;
                }
            }

            // If we reach the end of the file and foundCode is still 1, there was only one ".code"
            return foundCode ? 1 : 0;
        }
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Find end of code section⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // This function finds the end of code section depending on two scenarios
        int findCodeSectionEnd(int mode, FILE *file) {

            // Rewind the file pointer
            rewind(file);

            // Create a line buffer
            char line[MAX_CHARS_PER_LINE];

            // Init line number
            int lineNumber = 0;

            // Init codeSectionEnd
            int codeSectionEnd = 0;

            // Scenario 1: Code section ends where Data section begins
            if (mode == 1) {

                // For each line:
                while (fgets(line, sizeof(line), file) != NULL) {

                    lineNumber++;

                    // Find the occurrence of .code 
                    if (strstr(line, ".data") != NULL) {

                        // Found the .data directive, so the previous line is the end of the code section
                        codeSectionEnd = lineNumber - 1;

                        // Exit the loop
                        break;
                    }
                }  
            } 
            
            // Scenario 2: Code section ends at end of the file
            else if (mode == 2) {

                // Simply count the lines...
                while (fgets(line, sizeof(line), file) != NULL) { lineNumber++; }

                // ...until there are no more to count, in which case, we have found the last line
                codeSectionEnd = lineNumber;
            }

            // Return the line number where the data section ends
            return codeSectionEnd;
        }
        
// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ DATA DIRECTIVE ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Check for .data directive⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Check if the data directive is indeed present somewhere in the file and returns its position if it exists
        int isDataDirectivePresent(FILE *file) {

            // Rewind the pointer that was at the end of the file
            rewind(file);

            // Create a buffer line that will.. Hold the line! 🎶 Love is not always on time! 🎶
            char line[MAX_CHARS_PER_LINE];

            // Create a line tracker
            int lineNumber = 0;

            while (fgets(line, sizeof(line), file) != NULL) {

                // Create a pointer to start pointing to characters
                char* ptr = line;

                // Increment the line number
                lineNumber++;

                // Skip the trailing whitespaces
                while (*ptr && isspace((unsigned char)*ptr)) ptr++;

                // Check if the line starts with ".data" 
                if (strncmp(ptr, ".data", 5) == 0){
                    
                    // Move the start pointer past it
                    ptr += 5;

                    // Skip whitespaces
                    while (*ptr && isspace((unsigned char)*ptr)) ptr++;

                    // Check if what follows is a comment
                    if (strncmp(ptr, "//", 2) == 0 || *ptr == '\0') {

                        // If it's a comment or the end of the line, the directive is valid
                        return lineNumber;
                    } 
                    
                    // Otherwise, there is an invalid character
                    else {
                        printf(" ⚠️  Preprocessor: Invalid character '%c' after \".data\" directive, line: %d.\nOnly comments starting with \"//\" are allowed on the same line as a section declaration.\n", *ptr, lineNumber);
                        return 0;
                    }
                }
            }

            // If we are done scrolling through the file and that it still hasn't been found, then it doesn't exist
            printf(" 🤖  Info: You didn't declare a data section.");
            return 0; 
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Is there another .data declared in the file?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Find whether ".data" has been declared more than once
        int isDataDirectiveUnique(FILE *file) {

            // Create a buffer line
            char line[MAX_CHARS_PER_LINE];

            // Create a line tracker
            int lineNumber = 0;

            // Number of times ".data" has been found
            int foundData = 0; 

            // Rewind the file pointer
            rewind(file);

            // For each line
            while (fgets(line, sizeof(line), file) != NULL) {

                // Increment lineNumber to keep track of the lines
                lineNumber++;
                
                char* ptr = line;

                // Skip whitespaces
                while (*ptr && isspace((unsigned char)*ptr)) {++ptr;}

                // Check if trimmed line starts with ".data"
                if (strncmp(ptr, ".data", 5) == 0) {

                    // If it has already been found at least once
                    if (foundData) {
                        
                        // Return an error
                        printf(" ⚠️  Preprocessor: Directive \".data\" declared more than once.\nFound a duplicate declaration at line %d\n", lineNumber);
                        return 0;
                    }

                    // Mark it as found once
                    foundData = 1;
                }
            }

            // If we reach the end of the file and foundData is still 1, there was only one ".data"
            return foundData ? 1 : 0;
        }
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Find end of data section⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // This function finds the end of data section depending on two scenarios
        int findDataSectionEnd(int mode, FILE *file) {

            // Rewind the file pointer
            rewind(file);

            // Create a line buffer
            char line[MAX_CHARS_PER_LINE];

            // Init line number
            int lineNumber = 0;

            // Init dataSectionEnd
            int dataSectionEnd = 0;

            // Scenario 1: Data section ends where Code section begins
            if (mode == 1) {

                // For each line:
                while (fgets(line, sizeof(line), file) != NULL) {

                    lineNumber++;

                    // Find the occurrence of .code 
                    if (strstr(line, ".code") != NULL) {

                        // Found the .code directive, so the previous line is the end of the data section
                        dataSectionEnd = lineNumber - 1;

                        // Exit the loop
                        break;
                    }
                }  
            } 
            
            // Scenario 2: Data section ends at end of the file
            else if (mode == 2) {

                // Simply count the lines...
                while (fgets(line, sizeof(line), file) != NULL) { lineNumber++; }

                // ...until there are no more to count, in which case, we have found the last line
                dataSectionEnd = lineNumber;
            }

            // Return the line number where the data section ends
            return dataSectionEnd;
        }
