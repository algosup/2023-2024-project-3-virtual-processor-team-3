// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ Debug Utilities ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print Byte in Binary for printing Memory⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Helper function to print a byte in binary
        void printByteInBinary(uint8_t byte) {
            for (int i = 7; i >= 0; i--) {
                putchar((byte & (1 << i)) ? '1' : '0');
            }
        }


// ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Print the data section⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
    void printDataSection(const DataSection_t *dataSection) {
        printf("🤖 - Entering printDataSection... bytesCount = %d\n", dataSection->bytesCount); // Debugging line
        for (int i = 0; i < dataSection->bytesCount; i++) {
            printf("🤖 - Printing byte %d: ", i);
            printByteInBinary(dataSection->bytes[i]);
            printf("\n");
        }
    }

