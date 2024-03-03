// DEBUG VARS
// Various debugging info
#define DBG 1
// Print Memory Bytes
#define DBG_PRINT_MEMORY_BYTES 1
#define DBG_PRINT_MEMORY_WORDS 0

#include "gorasm.h"

// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ MAIN ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    int main(void) {
        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱File Management⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // File handlers for the data and code files
            FILE *file;

            /* MERGING CODE AND DATA FILES
                FILE *fileCode;
            */

            // Section_t codeSection;
            // DataSection_t dataSection = {0};
            // UnresolvedInstructions_t unresolvedInstructions = {0};


            // Open the data file
            file = fopen("basicTest/newtest.gras", "r");
            if (!file) {
                perror("Error opening the file (newtest.gras)");
                return EXIT_FAILURE;
            }

            /* MERGING CODE AND DATA FILES
                // Open the code file
                fileCode = fopen("basicTest/newtest.gras", "r");
                if (!fileCode) {
                    perror("Error opening the code file (data.code)");
                    return EXIT_FAILURE;
                }
            */

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Variables⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // Buffer for reading lines from the file
            // char lineData[MAX_CHARS_PER_LINE]; 

            /* MERGING CODE AND DATA FILES
                char lineCode[MAX_CHARS_PER_LINE]; 
                
            */


            // ++++++++++++++ BEGIN WORK IN PROGRESS +++++++++++++++++
        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Pre-Process⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            //PRINT_WELCOME_DBG

            // EXCEPTION: All the tests in the preprocessor will use zero as a failure value. (This is the opposite of what I do in the rest of the program)
            // IMPROVEMENT: Minor modifications could lead to less duplicate code in preprocessor functions

            // Check if a line exceeds the hard MAX_CHARS_PER_LINE limit (until I do something more dynamic)
            int lineLengthCheck = isLineTooLong(file);

            // Check if the file ends with an empty line (0 = failure)
            int emptyLineCheck = endsWithEmptyLine(file);

            // Check if the file contains the mandatory ".code" directive (0 = failure, > 0 = line number it was found at)
            int foundCodeDirective = isCodeDirectivePresent(file);

            // Check if it has only one ".code" declaration
            int duplicateCodeDirective = isCodeDirectiveUnique(file);

            // Check if the program has the (non mandatory) ".data" directive (0 = none, > 0 = line number it was found at)
            int foundDataDirective = isDataDirectivePresent(file);

            // Prepare for next check
            int duplicateDataDirective = 1;

            // This indicates at which line the sections end
            int endOfDataSection = 0;
            int endOfCodeSection = 0;

            // If a data section has been found
            if (foundDataDirective){

                // Check for duplicate declaration (0 = failure)
                duplicateDataDirective = isDataDirectiveUnique(file);

                // If data section has been declared before code section:
                if (foundDataDirective < foundCodeDirective){

                    // The data section spans from ".data" until the ".code" declaration
                    endOfDataSection = findDataSectionEnd(1, file);

                    // The code section spans from ".code" until the end of the file
                    endOfCodeSection = findCodeSectionEnd(2, file);

                }

                // Otherwise, data section has been declared after the code section
                else {

                    // In which case, it spans from data until the end of the file
                    endOfDataSection = findDataSectionEnd(2, file);

                    // The code section spans from ".code" until the ".data" declaration
                    endOfCodeSection = findCodeSectionEnd(1, file);

                }
            }

            // Otherwise, if no data section has been found
            else {
                endOfCodeSection = findCodeSectionEnd(2, file);
            }

            // Init end of code section

            printf("Data found line: %d\n", foundDataDirective);
            printf("Data end line: %d\n", endOfDataSection);
            printf("Code found line: %d\n", foundCodeDirective);
            printf("Code end line: %d\n", endOfCodeSection);


            

            // TODO: Once this is checked, check the file for a .code
                // If .code is found, make sure it is followed by nothing else other than whitespaces, tabs or line returns
                // If followed by nothing else than.... check if there aren't any other .code declarations elsewhere
                // If there aren't any, proceed.
                    // Try to find the data section. Make sure there aren't multiple .data declaration
                        // If there is a data section && it's before code, return the lines that are between .data and .code
                        // If there is a data section && its after code, return the lines that are between .data and the end of the file
                    // If there is no data section, close the data section and move on
                // If code is not found abort everything.
                // If data section != NULL, start ParseLineData
                // If code section != NULL, start ParseLineCode

                // I think how I'm going to return the line numbers is by indicating to parseLineData and parseLineCode the line they're gonna start and at which line to stop at and they're going to increment even when there's comments.


            // If any of the tests reported anything other than > 0, halt execution.
            if (!emptyLineCheck || !foundCodeDirective || !duplicateCodeDirective || !duplicateDataDirective || !lineLengthCheck) {
                printf("🛑 Program Halted\n");

                fclose(file);
                return EXIT_FAILURE;

            }


            // ++++++++++++++ END WORK IN PROGRESS +++++++++++++++++

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Data Section⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        /* MERGING CODE AND DATA FILES
            // SymbolTableInit
            SymbolTableNode_t *head = NULL; // TODO: Move this in Data Section

            // For each line in the file:
            while (fgets(lineData, sizeof(lineData), file)) {


                // Start by removing newline character if present
                lineData[strcspn(lineData, "\n")] = 0;

                // Parse the line into the final memory block, by giving it the line, 
                // the memory section and the current symbol head
                int result = ParseLineData(lineData, &dataSection, &head);

                // Handle error 😢
                if (result != 0) {
                    printf("🛑 Program Halted\n");


                    // Clean up file
                    fclose(file); 

                    // Clean up code section too
                    fclose(fileCode);
                        

                    // Clear dangling pointer
                    head = NULL;
                    // head2 = NULL;

                    // #freeTheTables
                    freeList(head);
                    // freeList(head2);

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
                    // printDataSection(&dataSection);
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
                    // usleep(900000);
                    printf("\nData Section Bytes Count: %d\n\n", dataSection.bytesCount);
                    // usleep(200000);
                    printf("====================================\n");
                }
            
        */
            

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Code Section⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // The first pass will parse instructions into usable data, syntax check it, build a new symbol table with labels
            // For each line in the file:
            /* MERGING CODE AND DATA FILES

            // Symbol Table Init
            SymbolTableNode_t *head2 = NULL; // TODO: Move this in Code Section

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
                    fclose(file); 

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
            */


            // +++++++++++ DEBUG +++++++++++++
                /*
                if (DBG) {
                    // usleep(900000);
                    printf("✅ 🤖 < Code section fully parsed!)\n");
                    printf("\n");
                    printf("Unresolved Instructions Count: %d\n\n\n", unresolvedInstructions.count);
                    // usleep(900000);
                    for (int i = 0; i < unresolvedInstructions.count; ++i) {
                        Instruction_t *instr = &unresolvedInstructions.instructions[i];
                        printf("\nInstruction %d: %s\n", i + 1, findMnemonicReverse(instr->name));
                        printf("\tOperand Count: %d\n", instr->operandCount);
                        printf("\tOperands: ");

                        for (int j = 0; j < instr->operandCount; ++j) {
                            printf("%lld ", instr->operands[j]);
                        }

                        printf("\n");
                        printf("\tNeeds Resolve: %s\n", instr->needsResolve);
                        // usleep(200000);
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
                    // usleep(200000);
                    printf("\n\n");
                    printf("====================================\n");
                    // usleep(900000);
                    printf("✅ 🤖 < Instructions all resolved!)\n\n");
                }
                */

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Program Assembly: Address resolution⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            /* MERGING CODE AND DATA FILES
                // Combine code and data sections to get final layout
                mergeTables(head, &head2, unresolvedInstructions.count);

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
                            // usleep(200000);
                            printf("\nResolved Instructions: %s\n", findMnemonicReverse(resolvedInstructions.instructions[k]->name));
                            printf("\tOperand Count: %d\n", resolvedInstructions.instructions[k]->operandCount);
                            printf("\tOperands: ");

                            for (int l = 0; l < resolvedInstructions.instructions[k]->operandCount; ++l) {
                                printf("%lld ", resolvedInstructions.instructions[k]->operands[l]);
                            }
                            printf("\n");
                        }
                        // usleep(200000);
                        printf("\n\n");
                        printf("====================================\n");
                        // usleep(900000);
                        printf("✅ 🤖 < Instructions are being encoded!)\n\n");
                    }

                // Halt the program if error
                if (exception){
                    printf(" 🛑 Program Halted\n");

                    // Clean up file
                    fclose(file); 

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
            */

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Program Assembly: Encoding⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            /* MERGING CODE AND DATA FILES
                // Init the final memory section
                MemorySection_t memorySection;
                size_t totalByteSize = resolvedInstructions.count*4 + dataSection.bytesCount;
                int memInit = initMemorySection(&memorySection, totalByteSize);

                // Add Code to memory
                int code2memResult = populateMemoryWithCode(&memorySection, totalByteSize, &resolvedInstructions);
                
                // Add Data section to the end of it
                appendData(&memorySection, &dataSection);
                
                
                // Iterate over bytes 
                if (DBG_PRINT_MEMORY_BYTES){
                    printMemorySection(&memorySection);
                }

                // Catch error
                if (memInit || code2memResult){
                    printf(" 🛑 Program Halted\n");

                    // Clean up file
                    fclose(file); 

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


                if (DBG){
                    // printDataSection(&dataSection);
                }
            */

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Closing Sequence⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // Freeing the symbol table
            // freeList(head2);

            //Temporary free
            // freeList(head);

            /* MERGING CODE AND DATA FILES
            // Free the label resolutions
            for (int i = 0; i < unresolvedInstructions.count; ++i) {
                free(unresolvedInstructions.instructions[i].needsResolve);
                unresolvedInstructions.instructions[i].needsResolve = NULL;
            }

            // Free the resolved instructions
            for (int i = 0; i < resolvedInstructions.count; i++) {
                free(resolvedInstructions.instructions[i]);
            }
            */

            // Clear dangling pointer
            // head = NULL;
            // head2 = NULL;


            // Close the file
            fclose(file);

            /* MERGING CODE AND DATA FILES
                // Close the fileCode
                fclose(fileCode);
                
            */

            // usleep(900000);
            printf("\n\n");
            printf("✅ ALGORASM Executed Succesfully!\n");
            return EXIT_SUCCESS;
}