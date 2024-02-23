// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ Line Parser Utilities ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
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
        int isValidHalfInt(char *str, int *value) {
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
        int isValidWordInt(char *str, int *value) {
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