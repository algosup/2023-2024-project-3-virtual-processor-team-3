#ifndef bruh
// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ Code Line Parser Utilities ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Tokenize instruction⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Function to tokenize the instruction
        char** tokenizeInstruction(char* instruction) {
            static char* tokens[MAX_OPRD_COUNT + 1]; // +1 for the mnemonic
            int i = 0;
            char* token = strtok(instruction, " ,");
            while (token != NULL && i < MAX_OPRD_COUNT + 1) {
                tokens[i++] = token;
                token = strtok(NULL, " ,");
            }
            return tokens;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Match Mnemonic string to Mnemonic Enum⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Function to find the enum value for the mnemonic
        InstructionName_t getInstructionMnemonic(char* mnemonic) {
            int numEntries = sizeof(mnemonicMap) / sizeof(MnemonicMap_t);
            for (int i = 0; i < numEntries; i++) {
                if (strcmp(mnemonicMap[i].name, mnemonic) == 0) {
                    return mnemonicMap[i].value;
                }
            }
            return -1; // Indicate not found/error
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Validate Register Operand⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Function to validate a register operand
        bool validateRegOperand(char* operand) {
            if (operand[0] != 'r') return false;
            int regNum = atoi(&operand[1]);
            return regNum >= 0 && regNum <= 31;
        }


    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Other Operand validations...⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
    

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Validate Instruction Line⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Main validation function for an instruction line
        bool validateInstructionLine(char* instructionLine) {
            char instructionCopy[100]; // Assuming instructionLine won't exceed 100 characters
            strcpy(instructionCopy, instructionLine); // Work on a copy to avoid modifying the original

            char** tokens = tokenizeInstruction(instructionCopy);
            InstructionName_t mnemonicValue = getInstructionMnemonic(tokens[0]);

            if (mnemonicValue == -1) {
                printf("Invalid mnemonic: %s\n", tokens[0]);
                return false;
            }

            // Find the instruction format in the instructionCheckTable
            for (int i = 0; i < sizeof(instructionCheckTable) / sizeof(InstructionArguments_t); i++) {
                if (instructionCheckTable[i].instrName == mnemonicValue) {
                    if (instructionCheckTable[i].InstructionArgumentsCount != token_count - 1) { // token_count needs to be calculated
                        printf("Invalid number of operands for %s\n", tokens[0]);
                        return false;
                    }

                    // Validate each operand
                    for (int j = 0; j < instructionCheckTable[i].InstructionArgumentsCount; j++) {
                        switch (instructionCheckTable[i].types[j]) {
                            case REG:
                                if (!validateRegOcperand(tokens[j + 1])) { // +1 to skip mnemonic
                                    printf("Invalid register operand: %s\n", tokens[j + 1]);
                                    return false;
                                }
                                break;
                            // Implement other cases (IMM, LBL, etc.) here
                            default:
                                // Placeholder for other types
                                break;
                        }
                    }

                    return true; // All operands are valid
                }
            }

            printf("Instruction format not found for mnemonic: %s\n", tokens[0]);
            return false; // Instruction format not found
        }

#endif