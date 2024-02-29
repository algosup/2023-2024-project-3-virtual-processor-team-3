// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ ENCODING INSTRUCTIONS ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode R-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        uint32_t encode_R_Type(unsigned int funct7, unsigned int rs2, unsigned int rs1, unsigned int funct3, unsigned int rd, unsigned int opcode) {
            return (funct7 << 25) | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode I-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Assuming imm is already processed to fit the format
        uint32_t encode_I_Type(int imm, unsigned int rs1, unsigned int funct3, unsigned int rd, unsigned int opcode) {
            uint32_t imm12 = imm & 0xFFF; // Extract 12-bit immediate
            return (imm12 << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode S-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        uint32_t encode_S_Type(unsigned int imm, unsigned int rs2, unsigned int rs1, unsigned int funct3, unsigned int opcode) {
            unsigned int imm11_5 = (imm >> 5) & 0x7F;
            unsigned int imm4_0 = imm & 0x1F;
            return (imm11_5 << 25) | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | (imm4_0 << 7) | opcode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode B-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        uint32_t encode_B_Type(unsigned int imm, unsigned int rs2, unsigned int rs1, unsigned int funct3, unsigned int opcode) {

            // Use AND with Ox1 to mask all but the least significant bit of the number
            unsigned int imm12 = (imm >> 12) & 0x1;

            // Use AND with 0x1 to mask all but the least significant bit of the number
            unsigned int imm11 = (imm >> 11) & 0x1;

            // 
            unsigned int imm10_5 = (imm >> 5) & 0x3F;
            unsigned int imm4_1 = (imm >> 1) & 0xF;
            return (imm12 << 31) | (imm10_5 << 25) | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | (imm11 << 7) | (imm4_1 << 8) | opcode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode U-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        uint32_t encode_U_Type(unsigned int imm, unsigned int rd, unsigned int opcode) {
            return (imm << 12) | (rd << 7) | opcode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Encode J-Type Instructions⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        uint32_t encode_J_Type(unsigned int imm, unsigned int rd, unsigned int opcode) {
            unsigned int imm20 = (imm >> 20) & 0x1;
            unsigned int imm10_1 = (imm >> 1) & 0x3FF;
            unsigned int imm11 = (imm >> 11) & 0x1;
            unsigned int imm19_12 = (imm >> 12) & 0xFF;
            return (imm20 << 31) | (imm19_12 << 12) | (imm11 << 20) | (imm10_1 << 21) | (rd << 7) | opcode;
        }