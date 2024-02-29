// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ Data Line Parser Utilities ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Validate Byte input⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Check if the string is a valid "byte" integer within bounds
        int isValidByteInt(char *str, int *value) {
            char *end;
            long num = strtol(str, &end, 10);

            // Check for empty string and characters left after conversion
            if (end == str || *end != '\0') return 0;

            // Number is out of bounds
            if (num < -128 || num > 255) return 0; 

            // Otherwise, number is valud
            *value = (int)num;
            return 1;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Validate Half Input⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Check if the string is a valid "half" integer within bounds
        int isValidHalfInt(const char *str, int *value) {
            char *end;
            long num = strtol(str, &end, 10);

            // Check for empty string and characters left after conversion
            if (end == str || *end != '\0') return 0;

            // Number is out of bounds
            if (num < -32768 || num > 65535) return 0;

            // Otherwise, number is valid
            *value = (int)num;
            return 1; 
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Validate Word Input⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Utility function to check if the string is a valid "word" integer within bounds
        int isValidWordInt(const char *str, int *value) {
            char *end;
            long num = strtol(str, &end, 10);

            // Check for empty string and characters left after conversion
            if (end == str || *end != '\0') return 0;

            // Number is out of bounds
            if (num < -2147483648 || num > 4294967295) return 0;

            // Otherwise, number is valid
            *value = (int)num;
            return 1; 
        }




// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ Code Line Parser Utilities ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Find Mnemonic from String⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Function to find a mnemonic in the map
        InstructionName_t findMnemonic(const char* str) {
            int mnemonicMapSize = sizeof(mnemonicMap) / sizeof(mnemonicMap[0]);

            // For each mnemonic in the map, get its string and compare it to the 
            for (int i = 0; i < mnemonicMapSize; i++) {
                if (strcmp(mnemonicMap[i].name, str) == 0) {
                    return mnemonicMap[i].value;
                }
            }

            // If not found return special ERR type
            return ERR;
            
        }
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Find String for Mnemonic⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Does the opposite of the find mnemonic function
        const char* findMnemonicReverse(InstructionName_t mnemonic) {
            int mnemonicMapSize = sizeof(mnemonicMap) / sizeof(mnemonicMap[0]);

            for (int i = 0; i < mnemonicMapSize; i++) {
                if (mnemonicMap[i].value == mnemonic) {
                    return mnemonicMap[i].name;
                }
            }

            // If not found return a special string or NULL
            return "ERR"; // or NULL, depending on how you want to handle errors
        }


    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Validate Tokenised Lines⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Sub-Functions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Is operand a valid register?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
                // Checks if Operands are matching their respective types
                int isValidRegister(char *token, const int currentIndex, const int instructionID, const int currentAddress){

                    // If the first character is not 'r', we already have a problem
                    if (token[0] != 'r') {

                        // Throw an error if it is the case
                        printf(" ⚠️  Found %c instead of 'r' character in argument %d of %s instruction, line %d\n", token[0],  currentIndex, mnemonicMap[instructionID].name, currentAddress);
                        return 1;
                    }

                    // Check if the rest of the string is a number between 0 and 31
                    char *end;

                    // Convert string to long int
                    long int regNumber = strtol(token + 1, &end, 10);

                    // Check if conversion was successful and no extra characters were found (problems with strtol)
                    if (*end != '\0') {

                        // Throw an error
                        printf(" ⚠️  Register number interpretation failed in argument %d of %s instruction, line %u\n", currentIndex, mnemonicMap[instructionID].name, currentAddress);
                        return 1;
                    }

                    // Check if the number is within the valid range
                    if (regNumber < 0 || regNumber > 31) {

                        // Throw an error if out of bounds
                        printf(" ⚠️  Register number: %ld is not a valid register number (must be 0-31), argument %d of %s instruction, line %u\n",regNumber, currentIndex, mnemonicMap[instructionID].name, currentAddress);
                        return 1;
                    }

                    // Return 0 if no problem found
                    return 0;
                }

            // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Is operand a valid immediate?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
                // Checks if operands are valid immediates
                int isValidImmediate(char *token, const int currentIndex, const int instructionID, const int currentAddress) {

                    char *end;

                    // To detect overflow or underflow
                    errno = 0; 

                    // Convert string to uint32_t to check for 32-bit overflow/underflow
                    long long value = strtoll(token, &end, 10);


                    // Check conversion was successful and no extra characters were found
                    if (end == token || *end != '\0' || errno == ERANGE) {

                        // Throw an error if overflow or error
                        printf(" ⚠️  Immediate value interpretation of \"%s\" failed in argument %d of %s instruction, line %u\n", token, currentIndex, mnemonicMap[instructionID].name, currentAddress);
                        return 1;
                    }

                    // Check if the value fits in a 32-bit integer
                    if (value < -2147483648 || value > 4294967295) {

                        // Throw an error if out of bounds
                        printf(" ⚠️  Immediate number: %lld is not a valid number (must be < -2147483648 and > 4294967295), argument %d of %s instruction, line %u\n",value ,currentIndex, mnemonicMap[instructionID].name, currentAddress);
                        return 1;
                    }

                    // No problem found
                    return 0;
                }

            

            // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Is operand a valid address?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
                // Checks if operands are valid addresses (for load & store instructions)
                int isValidAddress(char *token, const int currentIndex, const int instructionID, const int currentAddress) {
                    // This code is for indirect addressing, which has not yet been implemented in the processor
                        // Check for presence of opening parenthesis
                        if (token[0] != '(') {
                            printf(" ⚠️  Found %c instead of '(' character in argument %d, of the '%s' instruction, line %d\n", token[0], currentIndex, mnemonicMap[instructionID].name, currentAddress);
                            return 1;
                        }

                        // Check for closing parenthesis at the end
                        int len = strlen(token);
                        if (token[len - 1] != ')') {
                            printf(" ⚠️  Missing closing ')' in argument %d, of the '%s' instruction, line %d\n", currentIndex, mnemonicMap[instructionID].name, currentAddress);
                            return 1;
                        }

                        // Create a new token without parentheses
                        char tokenCopy[len - 1];
                        strncpy(tokenCopy, token + 1, len - 2); 

                        // Null-terminate the string
                        tokenCopy[len - 2] = '\0'; 

                        // Check if the register is valid by calling isValidRegister
                        if (isValidRegister(tokenCopy, currentIndex, instructionID, currentAddress)) {
                            printf(" ⚠️  Invalid register %s in argument %d of line %d\n", tokenCopy, currentIndex, currentAddress);
                            return 1;
                        }

                        // No problem found
                        return 0;

                    /*
                    // This code is exactly the same as immediates
                    char *end;

                    // To detect overflow or underflow
                    errno = 0; 

                    // Convert string to uint32_t to check for 32-bit overflow/underflow
                    long long value = strtoll(token, &end, 10);


                    // Check conversion was successful and no extra characters were found
                    if (end == token || *end != '\0' || errno == ERANGE) {

                        // Throw an error if overflow or error
                        printf(" ⚠️  Immediate value interpretation of \"%s\" failed in argument %d of %s instruction, line %u\n", token, currentIndex, mnemonicMap[instructionID].name, currentAddress);
                        return 1;
                    }

                    // Check if the value fits in a 32-bit integer
                    if (value < -2147483648 || value > 4294967295) {

                        // Throw an error if out of bounds
                        printf(" ⚠️  Immediate number: %lld is not a valid number (must be < -2147483648 and > 4294967295), argument %d of %s instruction, line %u\n",value ,currentIndex, mnemonicMap[instructionID].name, currentAddress);
                        return 1;
                    }

                    // No problem found
                    return 0;
                    */
                    
                }




            // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Is operand a valid label?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
                // Check if operands are valid labels
                int isValidLabel(char *token, const int currentIndex, const int instructionID, const int currentAddress){

                    int length = strlen(token);

                    // Check if the label length exceeds 50 characters including the null terminator
                    if (length >= 50) {

                        // If not the case, return an error
                        printf(" ⚠️  Label: \"%s\" exceeds maximum length of 49 characters in argument %d, of instruction %s, line %d\n", token, currentIndex, mnemonicMap[instructionID].name, currentAddress);
                        return 1; 
                    }

                    // Check if the first character is an ASCII letter
                    if (!isalpha((unsigned char)token[0]) && token[0] != '.') {

                        // If not the case, return an error
                        printf(" ⚠️  Label: \"%s\" must start with an ASCII letter (A-Z, a-z) in argument %d ofinstruction %s, line %d\n", token, currentIndex, mnemonicMap[instructionID].name, currentAddress);
                        return 1; 
                    }

                    // Check each character of the label
                    for (int i = 0; i < length; i++) {
                        char c = token[i];

                        // Check if use the characters allowed for labels
                        if (!(isalpha((unsigned char)c) || isdigit((unsigned char)c) || c == '_' || c == '-' || c == '.')) {
                            printf(" ⚠️  Invalid character '%c' in label argument %d of instruction %s, line %d. Allowed characters (A-Z, a-z, 0-9 . _ - )\n", c, currentIndex, mnemonicMap[instructionID].name, currentAddress);
                            return 1;
                        }
                    }

                    // No problem found
                    return 0;
                }




            




        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Main Function⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // Function to validate Instruction formats, their operands and their types
            int isValidInstruction(char *tokens[], const int tokenCount, const int instructionID, const int currentAddress){

                // Do we have the right amount of operands?
                if (tokenCount - 1 != instructionCheckTable[instructionID].instructionArgumentsCount){
                    printf(" ⚠️  Invalid number of arguments provided for %s at line %d. Expected: %d, but got: %d\n", mnemonicMap[instructionID].name, currentAddress, instructionCheckTable[instructionID].instructionArgumentsCount, tokenCount - 1);

                    // return 1 for error
                    return 1;
                }

                // Do we have the right types at the right place?
                int result;

                // We'll see. For each token:
                for (int i=1; i < instructionCheckTable[instructionID].instructionArgumentsCount + 1; i++){

                    // If we are expecting a register
                    if (instructionCheckTable[instructionID].types[i-1] == REG){

                        // Call the appropriate checking functio
                        result = isValidRegister(tokens[i], i, instructionID, currentAddress);

                    }

                    // Or if we are expecting an immediate
                    else if (instructionCheckTable[instructionID].types[i-1] == IMM){

                        // Call the appropriate checking function
                        result = isValidImmediate(tokens[i], i, instructionID, currentAddress);

                    }

                    // Or if we are expecting an address
                    else if (instructionCheckTable[instructionID].types[i-1] == ADR){

                        // Call the appropriate checking function
                        result = isValidAddress(tokens[i], i, instructionID, currentAddress);

                    }

                    // Or if we are expecting a label
                    else {

                        // Since addresses are not all resolved yet, all we can really do is check if they are effectively strings composed of ASCII-characters
                        // Call the appropriate checking function
                        result = isValidLabel(tokens[i], i, instructionID, currentAddress);

                    }

                    // Break the loop if error found
                    if (result){
                        break;
                    }

                }

                // If the result is 1, halt the program
                if (result){
                    return 1;
                } 

                // Otherwise, return 0 for success
                return 0;

            }
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Build Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // The following helper functions are designed to build each instruction into the unresolvedInstructions array
        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Main Function⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            int buildInstructions(char *tokens[], int instructionID, int currentAddress , Instruction_t *instruction){

                // Set the name of the instruction accordingly
                instruction->name = mnemonicMap[instructionID].value;

                // Set its operand count accordingly (operand overflow has already been checked)
                instruction->operandCount = instructionCheckTable[instructionID].instructionArgumentsCount;

                int reg;
                int exception = 0;
                
                // Filling the operands. For each operand,
                for (int i=1; i < instructionCheckTable[instructionID].instructionArgumentsCount + 1; i++){
                    
                    // ❑ REGISTER OPERANDS ❑
                        if (instructionCheckTable[instructionID].types[i-1] == REG){

                            // Use sscanf to read the number after 'r'
                            if(sscanf(tokens[i], "r%d", &reg) == 1) {

                                // If conversion succeeded, set the instructions apropriate operand to the register number
                                instruction->operands[i-1] = reg;
                            } 

                            // Otherwise.. fail
                            else {
                                printf(" ⚠️  Unexpected string conversion failure of \"%s\" into a valid register number, for instruction %s, operand %d, line %d \n", tokens[i], mnemonicMap[instructionID].name, i, currentAddress);
                                exception = 1;
                            }
                        }

                    // ❑ LABEL OPERANDS ❑
                        else if (instructionCheckTable[instructionID].types[i-1] == LBL) {

                            // If it is a label, set needsResolve to the label name for later resolution

                            instruction->needsResolve = strdup(tokens[i]);
                            if (instruction->needsResolve == NULL) {
                                printf(" ⚠️  Failed to allocate memory when copying string \"%s\" into its label form, for instruction %s, operand %d, line %d\n", tokens[i], mnemonicMap[instructionID].name, i, currentAddress);
                                exception = 1;
                            }
                            
                            // A default value (0) has already been written to the operand during init and will be updated  later during resolution

                        }

                    // ❑ ADDRESS OPERANDS ❑
                        else if (instructionCheckTable[instructionID].types[i-1] == ADR) {
                            // This code is for indirect addressing, which has not yet been implemented in the processor
                                // Check if sscanf successfully read one item
                                if (sscanf(tokens[i], "(r%d)", &reg)) {
                                    
                                    // Write register number as an int
                                    instruction->operands[i-1] = reg;
                                }
                                
                                // Otherwise, throw an error
                                else {
                                    printf(" ⚠️  Unexpected string conversion failure of \"%s\" into a valid address, for instruction %s, operand %d, line %d \n", tokens[i], mnemonicMap[instructionID].name, i, currentAddress);
                                    exception = 1;
                                }

                                return 0;

                            /*
                            // This code is exactly the same as immediates
                            char *endPtr;
                            long long value = strtoll(tokens[i], &endPtr, 10);

                            // If conversion works
                            if (endPtr != tokens[i]) {

                                // Save the immediate or address to the current instruction
                                instruction->operands[i-1] = value;
                            }

                            // Otherwise, if it fails
                            else {
                                printf(" ⚠️  Unexpected string conversion failure of \"%s\" into a valid address, for instruction %s, operand %d, line %d \n", tokens[i], mnemonicMap[instructionID].name, i, currentAddress);
                                exception = 1;
                            }
                            */

                        }

                    // ❑ IMMEDIATE OPERANDS ❑
                        else {

                            char *endPtr;
                            long long value = strtoll(tokens[i], &endPtr, 10);

                            // If conversion works
                            if (endPtr != tokens[i]) {

                                // Save the immediate or address to the current instruction
                                instruction->operands[i-1] = value;
                            }

                            // Otherwise, if it fails
                            else {
                                printf(" ⚠️  Unexpected string conversion failure of \"%s\" into a valid immediate/address, for instruction %s, operand %d, line %d \n", tokens[i], mnemonicMap[instructionID].name, i, currentAddress);
                                exception = 1;
                            }
                        }

                    // If problem found, Halt executions
                    if (exception){
                        return 1;
                    }
                }

                // No problem found
                return 0;
            }





