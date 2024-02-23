// DEBUG VARS
// Various debugging info
#define DBG 0
// Print Memory Bytes
#define DBG_PRINT_MEMORY 0

#include "gorasm.h"

// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ MAIN ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    int main(void) {
        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱File Management⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // File handlers for the data and code files
            FILE *fileData;
            // FILE *fileCode;

            // Section_t codeSection;
            DataSection_t dataSection = {0};


            // Open the data file
            fileData = fopen("basicTest/data.gras", "r");
            if (!fileData) {
                perror("Error opening the data file (data.gras)");
                return EXIT_FAILURE;
            }

            // Open the code file

        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Variables⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // Buffer for reading lines from the file
            char lineData[MAX_CHAR_PER_LINE_AMNT]; 
            // char lineCode[256]; 

            // SymbolTableInit
            SymbolTableNode_t *head = NULL;


        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Data Section⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // For each line in the file:

            while (fgets(lineData, sizeof(lineData), fileData)) {

                // Start by removing newline character if present
                lineData[strcspn(lineData, "\n")] = 0;

                // Parse the line into the final memory block, by giving it the line, 
                // the memory section and the current symbol head
                int result = ParseLineData(lineData, &dataSection, &head);

                // Handle error 😢
                if (result != 0) {
                    printf("Program Halted 🛑\n");


                    // Clean up file
                    fclose(fileData); 

                    // TODO: Clean up code section too

                    // Clear dangling pointer
                    head = NULL;

                    // #freeTheTables
                    freeList(head);

                    // pretty self-explanatory
                    return EXIT_FAILURE;
                }
            }

            if (DBG_PRINT_MEMORY == 1){
                // Print The binary output of the memory
                printDataSection(&dataSection);
            }

            /*
            if (DBG == 1){
                SymbolTableNode_t *found = searchNode(head, "str");
                if (found != NULL) {
                    printf("🤖 - SYMTABLE: Found: %s at address %d\n", found->label, found->address);
                } else {
                    printf("🤖 - SYMTABLE: Label not found.\n");
                }
            }
            */
            
            SymbolTableNode_t *currentNode = head;
            while (currentNode != NULL) {
                printf("🤖 - SYMTABLE: Label: %s, Address: %d\n", currentNode->label, currentNode->address);
                currentNode = currentNode->next; // Move to the next node
            }




        // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Closing Sequence⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
            // Freeing the symbol table
            freeList(head);

            // Clear dangling pointer
            head = NULL;


            // Close the fileData
            fclose(fileData);
            // Close the fileCode

            printf("✅ ALGORASM Executed Succesfully!\n");
            return EXIT_SUCCESS;
}