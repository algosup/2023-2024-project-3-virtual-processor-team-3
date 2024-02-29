#ifndef ASSEMBLER_H
#define ASSEMBLER_H
// DEBUG VARS
// Various debugging info
#define DBG 1
// Print Memory Bytes
#define DBG_PRINT_MEMORY_BYTES 0
#define DBG_PRINT_MEMORY_WORDS 0

#include "gorasm.h"

// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ MAIN ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    int assembling(char *file, int debugFlag) {
        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱File Management⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // File handlers for the data and code files
            FILE *fileData;
            FILE *fileCode;

            // Section_t codeSection;
            DataSection_t dataSection = {0};
            UnresolvedInstructions_t unresolvedInstructions = {0};


            // Open the data file
            fileData = fopen("./data.gras", "r");
            if (!fileData) {
                perror("Error opening the data file (data.gras)");
                return EXIT_FAILURE;
            }

            // Open the code file
            fileCode = fopen("./code.gras", "r");
            if (!fileCode) {
                perror("Error opening the code file (data.code)");
                return EXIT_FAILURE;
            }

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Variables⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // Buffer for reading lines from the file
            char lineData[MAX_CHAR_PER_LINE_AMNT]; 
            char lineCode[MAX_CHAR_PER_LINE_AMNT]; 

            // SymbolTableInit
            SymbolTableNode_t *head = NULL;
            SymbolTableNode_t *head2 = NULL;


        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Data Section⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            //PRINT_WELCOME_DBG
            // For each line in the file:
            while (fgets(lineData, sizeof(lineData), fileData)) {


                // Start by removing newline character if present
                lineData[strcspn(lineData, "\n")] = 0;

                // Parse the line into the final memory block, by giving it the line, 
                // the memory section and the current symbol head
                int result = ParseLineData(lineData, &dataSection, &head);

                // Handle error 😢
                if (result != 0) {
                    printf("🛑 Program Halted\n");


                    // Clean up file
                    fclose(fileData); 

                    // Clean up code section too
                    fclose(fileCode);

                    // Clear dangling pointer
                    head = NULL;
                    head2 = NULL;

                    // #freeTheTables
                    freeList(head);
                    freeList(head2);

                    // Free the label resolutions
                    for (int i = 0; i < unresolvedInstructions.count; ++i) {
                        free(unresolvedInstructions.instructions[i].needsResolve);
                        unresolvedInstructions.instructions[i].needsResolve = NULL; // Avoid dangling pointer
                    }

                    // pretty self-explanatory
                    return EXIT_FAILURE;
                }
            }

            

            // ++++++++++++ DEBUG ++++++++++++++
                if (DBG_PRINT_MEMORY_BYTES){

                    // Print The binary output of the memory
                    printDataSection(&dataSection);
                }
                if (DBG){
                    // usleep(900000);
                    printf("✅ 🤖 < Data Section has been fully Parsed! Here are the labels I found !)\n\n");
                    // usleep(900000);

                    SymbolTableNode_t *dbgNode = head;
                    while (dbgNode != NULL) {
                        // usleep(200000);
                        printf("    Label:\"%s\" is at relative Address: %d\n", dbgNode->label, dbgNode->address);
                        dbgNode = dbgNode->next; // Move to the next node
                    }
                }

                if (DBG){
                    printf("Data Section Bytes Count: %d\n", dataSection.bytesCount);
                    printf("Data section fully parsed!\n");
                    printf("====================================\n");
                }
            

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Code Section⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // The first pass will parse instructions into usable data, syntax check it, build a new symbol table with labels
            // For each line in the file:
            while (fgets(lineCode, sizeof(lineCode), fileCode)) {

                // Start by removing newline character if present
                lineCode[strcspn(lineCode, "\n")] = 0;

                // Parse the line into the final memory block, by giving it the line, 
                // the memory section and the current symbol head
                int result2 = ParseLineCode(lineCode, &head, &head2, &unresolvedInstructions);

                // Handle error 😢
                if (result2 != 0) {
                    printf(" 🛑 Program Halted\n");


                    // Clean up file
                    fclose(fileData); 

                    // Clean up code section too
                    fclose(fileCode);

                    // Clear dangling pointer
                    head = NULL;
                    head2 = NULL;

                    // #freeTheTables
                    freeList(head);
                    freeList(head2);

                    // Free the label resolutions
                    for (int i = 0; i < unresolvedInstructions.count; ++i) {
                        free(unresolvedInstructions.instructions[i].needsResolve);
                        unresolvedInstructions.instructions[i].needsResolve = NULL; // Avoid dangling pointer
                    }

                    // pretty self-explanatory
                    return EXIT_FAILURE;
                }
            }


            // +++++++++++ DEBUG +++++++++++++
                if (DBG) {
                    printf("Unresolved Instructions Count: %d\n", unresolvedInstructions.count);
                    for (int i = 0; i < unresolvedInstructions.count; ++i) {
                        Instruction_t *instr = &unresolvedInstructions.instructions[i];
                        printf("Instruction %d: %s\n", i + 1, findMnemonicReverse(instr->name));
                        printf("\tOperand Count: %d\n", instr->operandCount);
                        printf("\tOperands: ");

                        for (int j = 0; j < instr->operandCount; ++j) {
                            printf("%lld ", instr->operands[j]);
                        }

                        printf("\n");
                        printf("\tNeeds Resolve: %s\n", instr->needsResolve);
                    }
                }

                if (DBG){
                    SymbolTableNode_t *dbgNode2 = head2;
                    while (dbgNode2 != NULL) {
                        printf("🤖 - SYMTABLE2: Label: %s, Address: %d\n", dbgNode2->label, dbgNode2->address);
                        dbgNode2 = dbgNode2->next; // Move to the next node
                    }
                }

                if (DBG){
                    printf("Code section fully parsed!\n");
                    printf("====================================\n");
                }

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Program Assembly: Address resolution⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // Combine code and data sections to get final layout
            mergeTables(head, &head2, unresolvedInstructions.count);

            SymbolTableNode_t *dbgNode = head2;
            while (dbgNode != NULL) {
                // usleep(200000);
                printf("    Label:\"%s\" is at absolute Address: %d\n", dbgNode->label, dbgNode->address);
                dbgNode = dbgNode->next; // Move to the next node
            }

            // Initialise the resolved instructions list
            ResolvedInstructions_t resolvedInstructions = {0};
            int exception = 0;

            // Resolve addresses from there. For each unresolved instruction, do:
            for (int i = 0; i < unresolvedInstructions.count; i++){

                // Init a new instruction
                resolvedInstructions.instructions[i] = calloc(1, sizeof(Instruction_t));

                // In case of an allocation failure:
                if (!resolvedInstructions.instructions[i]) {
                    
                    exception = 1;
                    break;
                }

                // ❑ No resolution ❑
                    // If doesn't need resolution, just copy it over
                    if (unresolvedInstructions.instructions[i].needsResolve == NULL){

                        // Set the value of the new instruction to the value of the old one
                        *(resolvedInstructions.instructions[i]) = unresolvedInstructions.instructions[i];

                        // Increment the count
                        resolvedInstructions.count++;
                    }

                // ❑ Address to resolve ❑
                    // If there is indeed a label to resolve:
                    else if (unresolvedInstructions.instructions[i].needsResolve != NULL) {
                        
                        // Copy the instruction first
                        *(resolvedInstructions.instructions[i]) = unresolvedInstructions.instructions[i];

                        // Fetch the instruction name for easier checks
                        InstructionName_t currentInstructionName = resolvedInstructions.instructions[i]->name;

                        // Find its address from the lookup table
                        int address = resolveAddress(head2, unresolvedInstructions.instructions[i].needsResolve);
                        if (address != -1){

                            // Iterate over all operands to find the ones that are supposed to be labels
                            for (int j = 0; j < resolvedInstructions.instructions[i]->operandCount; j++){

                                // Fetch its rules, if we find the label:
                                if (instructionCheckTable[currentInstructionName].types[j] == LBL){

                                    // Set the current operand being checked to the new address
                                    resolvedInstructions.instructions[i]->operands[j] = address;
                                }
                            }

                            // Increment the count
                            resolvedInstructions.count++;

                        }

                        // The famous '.' operator
                        else if (strcmp(unresolvedInstructions.instructions[i].needsResolve, ".") == 0) {

                            address = i * 32;

                            // Iterate over all operands to find the ones that are supposed to be labels
                            for (int j = 0; j < resolvedInstructions.instructions[i]->operandCount; j++){

                                // Fetch its rules, if we find the label:
                                if (instructionCheckTable[currentInstructionName].types[j] == LBL){

                                    // Set the current operand being checked to the new address
                                    resolvedInstructions.instructions[i]->operands[j] = address;
                                }
                            }

                            // Increment the count
                            resolvedInstructions.count++;

                        }

                        // Otherwise address resolution failed
                        else {
                            printf(" ⚠️  Address resolution error, could not find label \"%s\" in instruction \"%s\", line ????\n", unresolvedInstructions.instructions[i].needsResolve, findMnemonicReverse(unresolvedInstructions.instructions[i].name));
                            exception = 1;
                            break;
                        }
                    }

                // Otherwise fail address resolution
                else {
                    exception = 1;
                    break;
                }
            }

            // ++++++++++++ DEBUG +++++++++++++++
                if (DBG) {
                    for (int k = 0; k < resolvedInstructions.count; k++){
                        printf("==========================\n");
                        printf("ResolvedInstructions: %s\n", findMnemonicReverse(resolvedInstructions.instructions[k]->name));
                        printf("\tOperand Count: %d\n", resolvedInstructions.instructions[k]->operandCount);
                        printf("\tOperands: ");

                        for (int l = 0; l < resolvedInstructions.instructions[k]->operandCount; ++l) {
                            printf("%lld ", resolvedInstructions.instructions[k]->operands[l]);
                        }

                        printf("\nk: %d\n", k);
                    }
                }

            // Halt the program if error
            if (exception){
                printf(" 🛑 Program Halted\n");

                // Clean up file
                fclose(fileData); 

                // Clean up code section too
                fclose(fileCode);

                // Clear dangling pointer
                head = NULL;
                head2 = NULL;

                // #freeTheTables
                freeList(head);
                freeList(head2);

                // Free the label resolutions
                for (int i = 0; i < unresolvedInstructions.count; ++i) {
                    free(unresolvedInstructions.instructions[i].needsResolve);
                    unresolvedInstructions.instructions[i].needsResolve = NULL; // Avoid dangling pointer
                }

                // Free the resolved instructions
                for (int i = 0; i < resolvedInstructions.count; i++) {
                    free(resolvedInstructions.instructions[i]); // Free each allocated Instruction_t
                }

                // pretty self-explanatory
                return EXIT_FAILURE;
            }

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Program Assembly: Encoding⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○

            // Init the final memory section
            MemorySection_t memorySection;
            size_t totalByteSize = resolvedInstructions.count*4 + dataSection.bytesCount;
            int memInit = initMemorySection(&memorySection, totalByteSize);

           
            /*
            typedef struct {
                uint8_t bytes[MAX_DATA_MEMORY];
                int bytesCount;
             } DataSection_t;
            */

            int code2memResult = populateMemoryWithCode(&memorySection, totalByteSize, &resolvedInstructions);
            
            // appendData(&memorySection, &dataSection);
            
            
            // Iterate over bytes 
            if (DBG_PRINT_MEMORY_BYTES){
                printMemorySection(&memorySection);
            }
            // printf("size of memory section: %lu", sizeof(*memorySection));





            if (memInit || code2memResult){
                printf(" 🛑 Program Halted\n");

                // Clean up file
                fclose(fileData); 

                // Clean up code section too
                fclose(fileCode);

                // Clear dangling pointer
                head = NULL;
                head2 = NULL;

                // #freeTheTables
                freeList(head);
                freeList(head2);

                // Free the label resolutions
                for (int i = 0; i < unresolvedInstructions.count; ++i) {
                    free(unresolvedInstructions.instructions[i].needsResolve);
                    unresolvedInstructions.instructions[i].needsResolve = NULL; // Avoid dangling pointer
                }

                // Free the resolved instructions
                for (int i = 0; i < resolvedInstructions.count; i++) {
                    free(resolvedInstructions.instructions[i]); // Free each allocated Instruction_t
                }

                // pretty self-explanatory
                return EXIT_FAILURE;
            }


        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Closing Sequence⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // Freeing the symbol table
            freeList(head2);

            // Free the label resolutions
            for (int i = 0; i < unresolvedInstructions.count; ++i) {
                free(unresolvedInstructions.instructions[i].needsResolve);
                unresolvedInstructions.instructions[i].needsResolve = NULL;
            }

            // Free the resolved instructions
            for (int i = 0; i < resolvedInstructions.count; i++) {
                free(resolvedInstructions.instructions[i]);
            }

            // Clear dangling pointer
            head = NULL;
            head2 = NULL;


            // Close the fileData
            fclose(fileData);

            // Close the fileCode
            fclose(fileCode);

            printf("✅ ALGORASM Executed Succesfully!\n");
            return EXIT_SUCCESS;
}
#endif