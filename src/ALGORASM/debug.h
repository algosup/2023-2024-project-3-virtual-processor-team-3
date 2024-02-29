// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ Debug Utilities ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print Binary⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Helper function to print the binary representation of a number
        void printBinary(unsigned int value, int bits) {
            for (int i = bits - 1; i >= 0; i--) {
                putchar((value & (1 << i)) ? '1' : '0');
            }
        }

    
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print Byte in Binary for printing Memory⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Helper function to print a byte in binary
        void printByteInBinary(uint8_t byte) {
            for (int i = 7; i >= 0; i--) {
                putchar((byte & (1 << i)) ? '1' : '0');
            }
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print word in binary⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Helper function to print a byte in binary
        void printWordInBinary(uint32_t number) {
            for (int i = 31; i >= 0; i--) {
                printf("%u", (number >> i) & 1);
                if (i % 4 == 0) { // Optional: Add a space every 4 bits for readability
                    printf(" ");
                }
            }
            printf("\n"); // New line at the end
        }


// ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print the data section⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
    void printDataSection(const DataSection_t *dataSection) {
        printf("🤖 - Entering printDataSection... bytesCount = %d\n", dataSection->bytesCount);
        for (int i = 0; i < dataSection->bytesCount; i++) {
            printf("    byte %d: ", i);
            printByteInBinary(dataSection->bytes[i]);
            printf("\n");
        }
    }

// ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print the memory section⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
    void printMemorySection(const MemorySection_t *memorySection) {
        printf("🤖 - Entering printMemorySection... bytesCount = %d\n", memorySection->bytesCount);
        for (int i = 0; i < memorySection->bytesCount; i++) {
            printf("    byte %d: ", i);
            printByteInBinary(memorySection->bytes[i]);
            printf("\n");
        }
    }

// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ PRINT ENCODED TYPES ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print R-type⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        void printEncodedRType(uint32_t encodedValue) {
            // Extract each segment using bitwise operations
            unsigned int funct7 = (encodedValue >> 25) & 0x7F; // Extract bits 25-31
            unsigned int rs2 = (encodedValue >> 20) & 0x1F;    // Extract bits 20-24
            unsigned int rs1 = (encodedValue >> 15) & 0x1F;    // Extract bits 15-19
            unsigned int funct3 = (encodedValue >> 12) & 0x07; // Extract bits 12-14
            unsigned int rd = (encodedValue >> 7) & 0x1F;      // Extract bits 7-11
            unsigned int opcode = encodedValue & 0x7F;         // Extract bits 0-6

            // Print each segment in binary, separated by spaces
            printBinary(funct7, 7);
            putchar(' ');
            printBinary(rs2, 5);
            putchar(' ');
            printBinary(rs1, 5);
            putchar(' ');
            printBinary(funct3, 3);
            putchar(' ');
            printBinary(rd, 5);
            putchar(' ');
            printBinary(opcode, 7);
            putchar('\n');
        }
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print I-type⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        void printEncodedIType(uint32_t encodedValue) {
            // Extract each segment using bitwise operations
            uint32_t imm12 = (encodedValue >> 20) & 0xFFF; // Extract bits 20-31 (12 bits)
            unsigned int rs1 = (encodedValue >> 15) & 0x1F;    // Extract bits 15-19
            unsigned int funct3 = (encodedValue >> 12) & 0x07; // Extract bits 12-14
            unsigned int rd = (encodedValue >> 7) & 0x1F;      // Extract bits 7-11
            unsigned int opcode = encodedValue & 0x7F;         // Extract bits 0-6

            // Print each segment in binary, separated by spaces
            printBinary(imm12, 12);
            putchar(' ');
            printBinary(rs1, 5);
            putchar(' ');
            printBinary(funct3, 3);
            putchar(' ');
            printBinary(rd, 5);
            putchar(' ');
            printBinary(opcode, 7);
            putchar('\n');
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print S-type⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        void printEncodedSType(uint32_t encodedValue) {

            // Extract bits 25-31 (7 bits of immediate
            uint32_t imm12_high = (encodedValue >> 25) & 0x7F; 

            // Extract bits 0-4 (5 bits of immediate)
            uint32_t imm12_low = (encodedValue >> 7) & 0x1F;

            // Extract bits 20-24
            unsigned int rs2 = (encodedValue >> 20) & 0x1F;   

            // Extract bits 15-19 
            unsigned int rs1 = (encodedValue >> 15) & 0x1F;    

            // Extract bits 12-14
            unsigned int funct3 = (encodedValue >> 12) & 0x07; 

            // Extract bits 0-6
            unsigned int opcode = encodedValue & 0x7F;

            // Print each segment in binary, separated by spaces
            printBinary(imm12_high, 7);
            putchar(' ');
            printBinary(rs2, 5);
            putchar(' ');
            printBinary(rs1, 5);
            putchar(' ');
            printBinary(funct3, 3);
            putchar(' ');
            printBinary(imm12_low, 5);
            putchar(' ');
            printBinary(opcode, 7);
            putchar('\n');
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print B-type⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // For now, the same as B-type (no relative addressing)
        void printEncodedBType(uint32_t encodedValue) {
            // Extract bits 31 (imm[12]) and 25-30 (imm[10:5])
            uint32_t imm12_10_5 = (encodedValue >> 25) & 0x7F;

            // Extract bits 7-11 (imm[11] and imm[4:1])
            uint32_t imm4_1_11 = (encodedValue >> 7) & 0x1F;

            // Extract bits 20-24
            unsigned int rs2 = (encodedValue >> 20) & 0x1F;

            // Extract bits 15-19 
            unsigned int rs1 = (encodedValue >> 15) & 0x1F;

            // Extract bits 12-14
            unsigned int funct3 = (encodedValue >> 12) & 0x07;

            // Extract bits 0-6
            unsigned int opcode = encodedValue & 0x7F;

            // Print each segment in binary, separated by spaces
            printBinary(imm12_10_5, 7);
            putchar(' ');
            printBinary(rs2, 5);
            putchar(' ');
            printBinary(rs1, 5);
            putchar(' ');
            printBinary(funct3, 3);
            putchar(' ');
            printBinary(imm4_1_11, 5);
            putchar(' ');
            printBinary(opcode, 7);
            putchar('\n');
        }
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print U-type⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // For now, the same as U-type (no relative addressing)
        void printEncodedUType(uint32_t encodedValue) {
            // Extract bits 12-31 for the immediate value
            uint32_t imm31_12 = (encodedValue >> 12) & 0xFFFFF; // 20 bits

            // Extract bits 7-11 for rd
            unsigned int rd = (encodedValue >> 7) & 0x1F; // 5 bits

            // Extract bits 0-6 for the opcode
            unsigned int opcode = encodedValue & 0x7F; // 7 bits

            // Print each segment in binary, separated by spaces
            printBinary(imm31_12, 20);
            putchar(' ');
            printBinary(rd, 5);
            putchar(' ');
            printBinary(opcode, 7);
            putchar('\n');
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print J-type⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // For now, the same as J-type (no relative addressing)
        void printEncodedJType(uint32_t encodedValue) {
            // Extract the immediate parts according to J-type encoding
            uint32_t imm20 = (encodedValue >> 31) & 0x1;       // Bit 20
            uint32_t imm19_12 = (encodedValue >> 12) & 0xFF;   // Bits 19:12
            uint32_t imm11 = (encodedValue >> 20) & 0x1;       // Bit 11
            uint32_t imm10_1 = (encodedValue >> 21) & 0x3FF;   // Bits 10:1

            // Extract rd and opcode fields
            unsigned int rd = (encodedValue >> 7) & 0x1F;
            unsigned int opcode = encodedValue & 0x7F;

            // Print the encoded instruction components as they are laid out in the instruction
            printBinary(imm20, 1);
            putchar(' ');
            printBinary(imm10_1, 10);
            putchar(' ');
            printBinary(imm11, 1);
            putchar(' ');
            printBinary(imm19_12, 8);
            putchar(' ');
            printBinary(rd, 5);
            putchar(' ');
            printBinary(opcode, 7);
            putchar('\n');
        }


