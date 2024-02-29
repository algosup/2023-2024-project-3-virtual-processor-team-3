#ifndef GORASM_TYPES_H
#define GORASM_TYPES_H

// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ GLOBAL TYPES DEFINITIONS ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Instruction Mnemonics⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Basically, the list of all allowed instructions
        typedef enum {
            ADD,
            ADDI,
            SUB,
            AND,
            ANDI,
            OR,
            ORI,
            XOR,
            XORI,
            SLL,
            SLLI,
            SRL,
            SRLI,
            SRA,
            SRAI,
            ILT,
            ILTI,
            ILTU,
            ILTUI,
            JIE,
            JINE,
            JIGE,
            JIGEU,
            JILE,
            JILEU,
            LUI,
            AUIPC,
            JAL,
            JALR,
            LB,
            LH,
            LW,
            LBU,
            LHU,
            SB,
            SH,
            SW,
            SYSCALL,
            ERR
        }InstructionName_t;

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Registers⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Operand Struct⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // The struct representing the "arguments" and "values" of lines of assembly
        /*
        typedef struct {
            InstructionArgumentType_t operandType;
            
        } Operand_t;
        */

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Instruction Struct⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // The Tokenised lines of assembly, contain mnemonics (unique identifier) and operands 
        typedef struct {
            InstructionName_t name;
            long long int operands[MAX_OPRD_COUNT];
            int operandCount;
            char *needsResolve;
        } Instruction_t;

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Data Section Struct⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // A collection of contiguous bytes for storing all the variables, to be be assembled with the code section afterwards
        typedef struct {
            uint8_t bytes[MAX_DATA_MEMORY];
            int bytesCount;
        } DataSection_t;

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Memory Section⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // The struct holding the final memory bytes ready for outputting (this time, dynamically allocated)
        typedef struct {
            uint8_t* bytes;
            int bytesCount;   
        } MemorySection_t;


    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Unresolved Instructions Struct⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // A collection of all the found instructions, waiting to be resolved and encoded
        typedef struct {
            Instruction_t instructions[MAX_INSTR_COUNT];
            int count;
        } UnresolvedInstructions_t;

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Resolved Instructions Struct⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
         // The resolved instructions, ready for encoding
        typedef struct {
            Instruction_t *instructions[MAX_INSTR_COUNT];
            int count;
        } ResolvedInstructions_t;


    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Symbol Table Node Struct⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // A node of the symbol table, for address resolution
        typedef struct SymbolTableNode {
            char label[MAX_MNEMO_LENGTH];
            int address;
            struct SymbolTableNode *next;
        } SymbolTableNode_t;


    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Mnemonic Map Struct⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Map string mnemonics to their enum counterparts
        typedef struct {
            char *name;
            InstructionName_t value;
        } MnemonicMap_t;

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Mnemonic Mapping⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // This map ddefines the mapping of all mnemonic string to their enum counterparts
        MnemonicMap_t mnemonicMap[] = {
            // str,      enum
            {"add",     ADD},
            {"addi",    ADDI},
            {"sub",     SUB},
            {"and",     AND},
            {"andi",    ANDI},
            {"or",      OR},
            {"ori",     ORI},
            {"xor",     XOR},
            {"xori",    XORI},
            {"sll",     SLL},
            {"slli",    SLLI},
            {"srl",     SRL},
            {"srli",    SRLI},
            {"sra",     SRA},
            {"srai",    SRAI},
            {"ilt?",    ILT},
            {"ilti?",   ILTI},
            {"iltu?",   ILTU},
            {"iltui?",  ILTUI},
            {"jie",     JIE},
            {"jine",    JINE},
            {"jige",    JIGE},
            {"jigeu",   JIGEU},
            {"jile",    JILE},
            {"jileu",   JILEU},
            {"lui",     LUI},
            {"auipc",   AUIPC},
            {"jal",     JAL},
            {"jalr",    JALR},
            {"lb",      LB},
            {"lh",      LH},
            {"lw",      LW},
            {"lbu",     LBU},
            {"lhu",     LHU},
            {"sb",      SB},
            {"sh",      SH},
            {"sw",      SW},
            {"syscall",      SYSCALL}
        };

 
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Instruction Mapping Struct⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // This struct defines the format of an assembly instruction
        typedef struct {
            InstructionName_t instructionName;
            unsigned int opcode;
            char format;
            unsigned int funct3;
            unsigned int funct7;
        } InstructionMap_t;

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱ISA Mapping⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○  
        // This map defines the encoding constants for all instruction types
        InstructionMap_t instructionMap[] = {  
            // Name,    Opcode,    Format,    Funct3,     Funct7
            { ADD,    0b110011,   'R',        0b000,      0b0000000},
            { ADDI,   0b10011,    'I',        0b000,      0},
            { SUB,    0b110011,   'R',        0b000,      0b0100000},
            { AND,    0b110011,   'R',        0b111,      0b0000000},
            { ANDI,   0b10011,    'I',        0b111,      0},
            { OR,     0b110011,   'R',        0b110,      0b0000000},
            { ORI,    0b10011,    'I',        0b110,      0},
            { XOR,    0b110011,   'R',        0b100,      0b0000000},
            { XORI,   0b10011,    'I',        0b100,      0},
            { SLL,    0b110011,   'R',        0b001,      0b0000000},
            { SLLI,   0b10011,    'I',        0b001,      0},
            { SRL,    0b110011,   'R',        0b101,      0b0000000},
            { SRLI,   0b10011,    'I',        0b101,      0},
            { SRA,    0b110011,   'R',        0b101,      0b0100000},
            { SRAI,   0b10011,    'I',        0b101,      0},
            { ILT,    0b110011,   'R',        0b010,      0},
            { ILTI,   0b10011,    'I',        0b010,      0},
            { ILTU,   0b110011,   'R',        0b11,       0},
            { ILTUI,  0b10011,    'I',        0b11,       0},
            { JIE,    0b1100011,  'B',        0b1,        0},
            { JINE,   0b1100011,  'B',        0b101,      0},
            { JIGE,   0b1100011,  'B',        0b11, 	  0},
            { JIGEU,  0b1100011,  'B',        0b111,      0},
            { JILE,   0b1100011,  'B',        0b10,       0},
            { JILEU,  0b1100011,  'B',        0b110,      0},
            { LUI,    0b110111,   'U',        0,          0},
            { AUIPC,  0b10111,    'U',        0,          0},
            { JAL,    0b1101111,  'J',        0,          0},
            { JALR,   0b1100111,  'I',        0,          0},
            { LB,     0b11,       'I',        0b001,      0},
            { LH,     0b11,       'I',        0b010,      0},
            { LW,     0b11,       'I',        0b011,      0},
            { LBU,    0b11,       'I',        0b100,      0},
            { LHU,    0b11,       'I',        0b101,      0},
            { SB,     0b100011,   'S',        0b001,      0},
            { SH,     0b100011,   'S',        0b010,      0},
            { SW,     0b100011,   'S',        0b011,      0},
            { SYSCALL,0b1110011,  'I',        0    ,      0},
        };

// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ SYNTAX TABLES ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Instruction Argument Types⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // This enum defines the types of operands that can be required for syntax checking
        typedef enum {
            REG,
            IMM,
            LBL,
            ADR
        }InstructionArgumentType_t;

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Instruction Arguments⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // This struct is used to check the intgrity of the statements by checking if input matches instruction requirements
        typedef struct {
            InstructionName_t instrName; 
            InstructionArgumentType_t types[MAX_OPRD_COUNT]; 
            int instructionArgumentsCount;

        }InstructionArguments_t;

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Instruction Operands Check⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // This table is used to check if the right number and types of operands are provided when summoning an instruction
        InstructionArguments_t const instructionCheckTable[] = {
        //  Instr.       Operand(s)    Count
            {ADD,    {REG, REG, REG},    3 },
            {ADDI,   {REG, REG, IMM},    3 },
            {SUB,    {REG, REG, REG},    3 },
            {AND,    {REG, REG, REG},    3 },
            {ANDI,   {REG, REG, IMM},    3 },
            {OR,     {REG, REG, REG},    3 },
            {ORI,    {REG, REG, IMM},    3 },
            {XOR,    {REG, REG, REG},    3 },
            {XORI,   {REG, REG, IMM},    3 },
            {SLL,    {REG, REG, REG},    3 },
            {SLLI,   {REG, REG, IMM},    3 },
            {SRL,    {REG, REG, REG},    3 },
            {SRLI,   {REG, REG, IMM},    3 },
            {SRA,    {REG, REG, REG},    3 },
            {SRAI,   {REG, REG, IMM},    3 },
            {ILT,    {REG, REG, REG},    3 },
            {ILTI,   {REG, REG, IMM},    3 },
            {ILTU,   {REG, REG, REG},    3 },
            {ILTUI,  {REG, REG, IMM},    3 },
            {JIE,    {REG, REG, LBL},    3 },
            {JINE,   {REG, REG, LBL},    3 },
            {JIGE,   {REG, REG, LBL},    3 },
            {JIGEU,  {REG, REG, LBL},    3 },
            {JILE,   {REG, REG, LBL},    3 },
            {JILEU,  {REG, REG, LBL},    3 },
            {LUI,    {REG, IMM},         2 },
            {AUIPC,  {REG, IMM},         2 },
            {JAL,    {REG, LBL},         2 },
            {JALR,   {REG, REG, IMM},    3 },
            {LB,     {REG, ADR},         2 },
            {LH,     {REG, ADR},         2 },
            {LW,     {REG, ADR},         2 },
            {LBU,    {REG, ADR},         2 },
            {LHU,    {REG, ADR},         2 },
            {SB,     {REG, ADR},         2 },
            {SH,     {REG, ADR},         2 },
            {SW,     {REG, ADR},         2 },
            {SYSCALL,{},                 0 },
        };
#endif