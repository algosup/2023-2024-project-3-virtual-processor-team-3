// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ PREPARING IMMEDIATES ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Sign Extension⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Sign-extends a value to 32 bits from a specified bit width
        static int32_t signExtend(uint32_t value, int bitWidth) {

            // Shift left to clear out all but the sign-extended bits, then shift right to sign-extend
            int shiftAmount = 32 - bitWidth;
            return (int32_t)(value << shiftAmount) >> shiftAmount;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode I-type immediates⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Encodes a 12-bit immediate for I-type instructions, ensuring sign extension
        uint32_t encodeITypeImmediate(int32_t imm) {

            // Sign-extend the immediate to 32 bits, then mask to 12 bits
            return (uint32_t)signExtend(imm, 12) & 0xFFF;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode S-type immediates⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Encodes an S-type immediate, splitting it for opcode fields
        uint32_t encodeSTypeImmediate(int32_t imm) {

            // Sign extend the immediate
            uint32_t extendedImm = (uint32_t)signExtend(imm, 12);

            // Split the immediate
            uint32_t imm11_5 = (extendedImm & 0xFE0) >> 5;
            uint32_t imm4_0 = extendedImm & 0x1F;

            // Combine the split immediate parts into their correct positions without overwriting
            return (imm11_5 << 25) | (imm4_0 << 7);
        }
        
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode B-type immediates⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Encodes an B-type immediate (same as S-Type for now, since no relative addressing), splitting it for opcode fields
        uint32_t encodeBTypeImmediate(int32_t imm) {

            // Sign extend the immediate to 32 bits
            uint32_t extendedImm = (uint32_t)signExtend(imm, 12);

            // Split and reposition the immediate parts
            // Extract bit 12
            uint32_t imm12 = (extendedImm >> 12) & 0x1; 

            // Extract bits 10:5
            uint32_t imm10_5 = (extendedImm >> 5) & 0x3F;

            // Extract bits 4:1
            uint32_t imm4_1 = (extendedImm >> 1) & 0xF;

            // Extract bit 11
            uint32_t imm11 = (extendedImm >> 11) & 0x1;

            // Combine the split immediate parts into their correct positions
            return (imm12 << 31) | (imm10_5 << 25) | (imm4_1 << 8) | (imm11 << 7);
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode U-type immediates⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Encodes a U-type immediate, masking the upper 20 bits
        uint32_t encodeUTypeImmediate(int32_t imm) {

            // Mask and return the upper 20 bits of the immediate
            return (uint32_t)imm & 0xFFFFF000;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode J-type immediates⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Encodes a J-type immediate for jump instructions
        uint32_t encodeJTypeImmediate(int32_t imm) {
            // Sign-extend the immediate to 32 bits to handle negative values correctly
            imm = signExtend(imm, 20);
            
            // Extract and shift the bits to their correct positions
            uint32_t imm20 = (imm >> 20) & 1;        // Extract bit 20
            uint32_t imm10_1 = (imm >> 1) & 0x3FF;   // Extract bits 10:1
            uint32_t imm11 = (imm >> 11) & 1;        // Extract bit 11
            uint32_t imm19_12 = (imm >> 12) & 0xFF;  // Extract bits 19:12

            // Reassemble the immediate in the instruction format
            return (imm20 << 31) | (imm19_12 << 12) | (imm11 << 20) | (imm10_1 << 21);
        }




// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ ENCODING INSTRUCTIONS ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode R-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        uint32_t encodeRType(unsigned int funct7, unsigned int rs2, unsigned int rs1, unsigned int funct3, unsigned int rd, unsigned int opcode) {
            return (funct7 << 25) | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode I-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        uint32_t encodeIType(int imm, unsigned int rs1, unsigned int funct3, unsigned int rd, unsigned int opcode) {
            uint32_t imm12 = encodeITypeImmediate(imm);
            return (imm12 << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode S-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        uint32_t encodeSType(unsigned int imm, unsigned int rs2, unsigned int rs1, unsigned int funct3, unsigned int opcode) {

            // Pass the immediate to immediate encoding
            uint32_t encodedImm = encodeSTypeImmediate(imm);

            // Combine the immediate with the rest of the instruction fields
            return encodedImm | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | opcode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode B-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        uint32_t encodeBType(int32_t imm, unsigned int rs2, unsigned int rs1, unsigned int funct3, unsigned int opcode) {
            // Encode the immediate for B-type instructions
            uint32_t encodedImm = encodeBTypeImmediate(imm);

            // Combine the immediate with the rest of the instruction fields
            return encodedImm | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | opcode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode U-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        uint32_t encodeUType(unsigned int imm, unsigned int rd, unsigned int opcode) {
            uint32_t encodedImm = encodeUTypeImmediate(imm);
            return encodedImm | (rd << 7) | opcode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode J-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        uint32_t encodeJType(unsigned int imm, unsigned int rd, unsigned int opcode) {

            // Get the immediate
            uint32_t encodedImm = encodeJTypeImmediate(imm);

            // Return the encoded instruction 
            return encodedImm | (rd << 7) | opcode;
        }
// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ MEMORY SECTION ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Mem⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        int initMemorySection(MemorySection_t* memSection, int initialSize) {
            memSection->bytes = (uint8_t*)malloc(initialSize * sizeof(uint8_t));

            // If alloc failed
            if (memSection->bytes == NULL) {

                // Handle error
                printf(" ⚠️  Failed to allocate memory for our memory block");
                return 1;
            }

            // Set initial byte count to 0
            memSection->bytesCount = 0; 

            // If no failure
            return 0; 
        }

        // Function to resize the memory section
        void resizeMemorySection(MemorySection_t* memSection, int newSize) {
            uint8_t* temp = (uint8_t*)realloc(memSection->bytes, newSize * sizeof(uint8_t));
            if (temp == NULL) {
                // Handle memory allocation failure
            } else {
                memSection->bytes = temp;
            }
        }

        // Function to free the dynamically allocated memory
        void freeMemorySection(MemorySection_t* memSection) {
            free(memSection->bytes);
            memSection->bytes = NULL;
            memSection->bytesCount = 0;
        }

        void appendData(MemorySection_t* memSection, const DataSection_t* dataSection) {
            if (!memSection || !dataSection) return; // Check for NULL pointers

            // Calculate new size
            int newSize = memSection->bytesCount + dataSection->bytesCount;

            // Reallocate memory for the combined size of code and data sections
            uint8_t* newMemory = realloc(memSection->bytes, newSize * sizeof(uint8_t));
            if (newMemory == NULL) {
                // Handle memory allocation failure
                printf(" ⚠️  Failed to allocate additional memory for data section");
                return;
            }
            memSection->bytes = newMemory;

            // Copy data from DataSection_t to the end of MemorySection_t
            memcpy(memSection->bytes + memSection->bytesCount, dataSection->bytes, dataSection->bytesCount);

            // Update bytesCount to reflect the new size
            memSection->bytesCount = newSize;
        }



        void appendInstructionToMemory(MemorySection_t* memorySection, uint32_t encodedInstruction) {
            if (memorySection == NULL) {
                // Handle null pointer
                return;
            }

            // Reallocate the memory section to accommodate the new instruction
            int newBytesCount = memorySection->bytesCount + 4; // Increase the count to accommodate the new 32-bit instruction
            uint8_t* newBytes = (uint8_t*)realloc(memorySection->bytes, newBytesCount);
            
            if (newBytes == NULL) {
                // Handle memory allocation failure
                return;
            }

            // Update the memory section
            memorySection->bytes = newBytes;
            int offset = memorySection->bytesCount; // Offset where new data should be written
            memorySection->bytesCount = newBytesCount;

            // Store the new instruction at the correct offset
            memorySection->bytes[offset] = (encodedInstruction >> 24) & 0xFF;
            memorySection->bytes[offset + 1] = (encodedInstruction >> 16) & 0xFF;
            memorySection->bytes[offset + 2] = (encodedInstruction >> 8) & 0xFF;
            memorySection->bytes[offset + 3] = encodedInstruction & 0xFF;
        }

        // Populates the output bytes with the resolved instructions
        int populateMemoryWithCode(MemorySection_t* memorySection, int totalByteSize, ResolvedInstructions_t *resolvedInstructions) {
            if (memorySection == NULL || totalByteSize <= 0) return 1;

            // Allocate or reallocate memory as necessary
            uint8_t* newMemory = realloc(memorySection->bytes, totalByteSize * 4 * sizeof(uint8_t));
            if (newMemory == NULL) {

                // Handle memory allocation failure
                printf("Failed to allocate memory\n");
                return 1;
            }

            memorySection->bytes = newMemory;
            memorySection->bytesCount = totalByteSize;

            // Initialise the instruction parameters
            int32_t opcode = 0;
            int32_t rd = 0;
            int32_t funct3 = 0;
            int32_t rs1 = 0;
            int32_t rs2 = 0;
            int32_t funct7 = 0;
            int32_t imm = 0;


            // Iterate over the resolved Instructions and encode them using their specific encoding functions
            int exception = 0;
            for (int i = 0; i < resolvedInstructions->count  ;i++){
                
                // Get the instruction's format:
                char instructionFormat = instructionMap[resolvedInstructions->instructions[i]->name].format;

                // If format is R:
                if (instructionFormat == 'R'){

                    // Fetch the required data for encoding
                    opcode = instructionMap[resolvedInstructions->instructions[i]->name].opcode;
                    rd = resolvedInstructions->instructions[i]->operands[0];
                    funct3 = instructionMap[resolvedInstructions->instructions[i]->name].funct3;
                    rs1 = resolvedInstructions->instructions[i]->operands[1];
                    rs2 = resolvedInstructions->instructions[i]->operands[2]; 
                    funct7 = instructionMap[resolvedInstructions->instructions[i]->name].funct7;

                    // Encode it
                    uint32_t encodedInstruction = encodeRType(funct7, rs2, rs1, funct3, rd, opcode);
                    
                    if (DBG){
                        printf("Encoded R-type instruction \"%s\":", findMnemonicReverse(resolvedInstructions->instructions[i]->name));
                        printEncodedRType(encodedInstruction);
                        printf("\n");
                    }

                    // TEMP CODE TO ADD IT TO MEMORY SECTION
                    // Calculate the starting byte position for this instruction in the memory section
                    int bytePos = i * 4;  // Assuming each instruction is 4 bytes

                    // Extract and store each byte of the instruction
                    // For little-endian order
                    memorySection->bytes[bytePos] = encodedInstruction & 0xFF; // Least significant byte
                    memorySection->bytes[bytePos + 1] = (encodedInstruction >> 8) & 0xFF;
                    memorySection->bytes[bytePos + 2] = (encodedInstruction >> 16) & 0xFF;
                    memorySection->bytes[bytePos + 3] = (encodedInstruction >> 24) & 0xFF; // Most significant byte
                    memorySection->bytesCount += 4;

                }

                // If the format is I:
                else if (instructionFormat == 'I'){

                    // Fetch the required data for encoding
                    opcode = instructionMap[resolvedInstructions->instructions[i]->name].opcode;
                    rd = resolvedInstructions->instructions[i]->operands[0];
                    funct3 = instructionMap[resolvedInstructions->instructions[i]->name].funct3;
                    rs1 = resolvedInstructions->instructions[i]->operands[1];
                    imm = resolvedInstructions->instructions[i]->operands[2];

                    // Encode it
                    uint32_t encodedInstruction = encodeIType(imm, rs1, funct3, rd, opcode);

                    if (DBG){
                        printf("Encoded I-type instruction \"%s\":", findMnemonicReverse(resolvedInstructions->instructions[i]->name));
                        printEncodedIType(encodedInstruction);
                        printf("\n");
                        // usleep(200000);
                    }

                    // TEMP CODE TO ADD IT TO MEMORY SECTION
                    // Calculate the starting byte position for this instruction in the memory section
                    int bytePos = i * 4;  // Assuming each instruction is 4 bytes

                    // Ensure there's enough space in the memory section
                    if (bytePos + 4 > memorySection->bytesCount) {
                        printf("Error: Not enough space in the memory section for the instruction\n");
                        exception = 1;
                        break;  // Exit the loop if there's an error
                    }

                    // Extract and store each byte of the instruction
                    // For little-endian order
                    memorySection->bytes[bytePos] = encodedInstruction & 0xFF; // Least significant byte
                    memorySection->bytes[bytePos + 1] = (encodedInstruction >> 8) & 0xFF;
                    memorySection->bytes[bytePos + 2] = (encodedInstruction >> 16) & 0xFF;
                    memorySection->bytes[bytePos + 3] = (encodedInstruction >> 24) & 0xFF; // Most significant byte
                    memorySection->bytesCount += 4;
                }
                
                // If the format is S:
                else if (instructionFormat == 'S'){ 

                    // Fetch the required data for encoding
                    opcode = instructionMap[resolvedInstructions->instructions[i]->name].opcode;
                    funct3 = instructionMap[resolvedInstructions->instructions[i]->name].funct3;
                    rs1 = resolvedInstructions->instructions[i]->operands[0];
                    // No indirect addressing so no need for rs2 for now
                    rs2 = resolvedInstructions->instructions[i]->operands[1];
                    imm = 0;

                    // Encode it
                    uint32_t encodedInstruction = encodeSType(imm, rs2, rs1, funct3, opcode);

                    if (DBG) {
                        printf("Encoded S-type instruction \"%s\":", findMnemonicReverse(resolvedInstructions->instructions[i]->name));
                        printEncodedSType(encodedInstruction);
                        printf("\n");
                        // usleep(200000);
                    }

                    // TEMP CODE TO ADD IT TO MEMORY SECTION
                    // Calculate the starting byte position for this instruction in the memory section
                    int bytePos = i * 4;  // Assuming each instruction is 4 bytes

                    // Ensure there's enough space in the memory section
                    if (bytePos + 4 > memorySection->bytesCount) {
                        printf("Error: Not enough space in the memory section for the instruction\n");
                        exception = 1;
                        break;  // Exit the loop if there's an error
                    }

                    // Extract and store each byte of the instruction
                    // For little-endian order
                    memorySection->bytes[bytePos] = encodedInstruction & 0xFF; // Least significant byte
                    memorySection->bytes[bytePos + 1] = (encodedInstruction >> 8) & 0xFF;
                    memorySection->bytes[bytePos + 2] = (encodedInstruction >> 16) & 0xFF;
                    memorySection->bytes[bytePos + 3] = (encodedInstruction >> 24) & 0xFF; // Most significant byte
                    memorySection->bytesCount += 4;
                }
                
                // If the format is B:
                else if (instructionFormat == 'B'){

                    // Fetch the required data for encoding
                    opcode = instructionMap[resolvedInstructions->instructions[i]->name].opcode;
                    funct3 = instructionMap[resolvedInstructions->instructions[i]->name].funct3;
                    rs1 = resolvedInstructions->instructions[i]->operands[0];
                    rs2 = resolvedInstructions->instructions[i]->operands[1];
                    imm = resolvedInstructions->instructions[i]->operands[2];

                    // Encode it
                    uint32_t encodedInstruction = encodeBType(imm, rs2, rs1, funct3, opcode);

                    if (DBG){
                        printf("Encoded B-type instruction \"%s\":", findMnemonicReverse(resolvedInstructions->instructions[i]->name));
                        printEncodedBType(encodedInstruction);
                        printf("\n");
                        // usleep(200000);
                    }

                    // TEMP CODE TO ADD IT TO MEMORY SECTION
                    // Calculate the starting byte position for this instruction in the memory section
                    int bytePos = i * 4;  // Assuming each instruction is 4 bytes

                    // Ensure there's enough space in the memory section
                    if (bytePos + 4 > memorySection->bytesCount) {
                        printf("Error: Not enough space in the memory section for the instruction\n");
                        exception = 1;
                        break;  // Exit the loop if there's an error
                    }

                    // Extract and store each byte of the instruction
                    // For little-endian order
                    memorySection->bytes[bytePos] = encodedInstruction & 0xFF; // Least significant byte
                    memorySection->bytes[bytePos + 1] = (encodedInstruction >> 8) & 0xFF;
                    memorySection->bytes[bytePos + 2] = (encodedInstruction >> 16) & 0xFF;
                    memorySection->bytes[bytePos + 3] = (encodedInstruction >> 24) & 0xFF; // Most significant byte
                    memorySection->bytesCount += 4;
                }
                
                // If the format is U:
                else if (instructionFormat == 'U'){

                    // Fetch the required data for encoding
                    opcode = instructionMap[resolvedInstructions->instructions[i]->name].opcode;
                    rd = resolvedInstructions->instructions[i]->operands[0];
                    imm = resolvedInstructions->instructions[i]->operands[1];

                    // Encode it
                    uint32_t encodedInstruction = encodeUType(imm, rd, opcode);

                    if (DBG){
                        printf("Encoded U-type instruction \"%s\":", findMnemonicReverse(resolvedInstructions->instructions[i]->name));
                        printEncodedUType(encodedInstruction);
                        printf("\n");
                        // usleep(200000); 
                    }

                    // TEMP CODE TO ADD IT TO MEMORY SECTION
                    // Calculate the starting byte position for this instruction in the memory section
                    int bytePos = i * 4;  // Assuming each instruction is 4 bytes

                    // Ensure there's enough space in the memory section
                    if (bytePos + 4 > memorySection->bytesCount) {
                        printf("Error: Not enough space in the memory section for the instruction\n");
                        exception = 1;
                        break;  // Exit the loop if there's an error
                    }

                    // Extract and store each byte of the instruction
                    // For little-endian order
                    memorySection->bytes[bytePos] = encodedInstruction & 0xFF; // Least significant byte
                    memorySection->bytes[bytePos + 1] = (encodedInstruction >> 8) & 0xFF;
                    memorySection->bytes[bytePos + 2] = (encodedInstruction >> 16) & 0xFF;
                    memorySection->bytes[bytePos + 3] = (encodedInstruction >> 24) & 0xFF; // Most significant byte
                    memorySection->bytesCount += 4;
                }
                
                // If the format is J:
                else if (instructionFormat == 'J'){

                    // Fetch the required data for encoding
                    opcode = instructionMap[resolvedInstructions->instructions[i]->name].opcode;
                    rd = resolvedInstructions->instructions[i]->operands[0];
                    imm = resolvedInstructions->instructions[i]->operands[1];

                    // Encode it
                    uint32_t encodedInstruction = encodeJType(imm, rd, opcode);

                    // printf("TEST: \n");
                    // printBinary(encodedInstruction, 32);
                    // printf("EOT: \n");

                    if (DBG){
                        printf("Encoded J-type instruction \"%s\":", findMnemonicReverse(resolvedInstructions->instructions[i]->name));
                        printEncodedJType(encodedInstruction);
                        printf("\n");
                        // usleep(200000);
                    }

                    // TEMP CODE TO ADD IT TO MEMORY SECTION
                    // Calculate the starting byte position for this instruction in the memory section
                    int bytePos = i * 4;  // Assuming each instruction is 4 bytes

                    // Ensure there's enough space in the memory section
                    if (bytePos + 4 > memorySection->bytesCount) {
                        printf("Error: Not enough space in the memory section for the instruction\n");
                        exception = 1;
                        break;  // Exit the loop if there's an error
                    }

                    // Extract and store each byte of the instruction
                    // For little-endian order
                    memorySection->bytes[bytePos] = encodedInstruction & 0xFF; // Least significant byte
                    memorySection->bytes[bytePos + 1] = (encodedInstruction >> 8) & 0xFF;
                    memorySection->bytes[bytePos + 2] = (encodedInstruction >> 16) & 0xFF;
                    memorySection->bytes[bytePos + 3] = (encodedInstruction >> 24) & 0xFF; // Most significant byte
                    memorySection->bytesCount += 4;
                   
                }

                // Otherwise, fail
                else {
                    printf("Unexpected error finding instruction type %c when encoding instruction [INSERT INSTRUCTION NAME]", instructionFormat);
                    exception = 1;
                    break;
                }
            }

            // Fail if Exception found
            if (exception){return 1;}
            // Otherwise, succeed
            return 0;
        }
