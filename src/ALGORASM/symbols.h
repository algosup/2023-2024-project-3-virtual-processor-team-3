#ifndef SYMBOLS_H
#define SYMBOLS_H
// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ SYMBOL TABLE ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // Using a linked list to implement a simple symbol table
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Create Node⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Function to initialise a new node
        SymbolTableNode_t *createNode(const char *label, int address) {

            // Allocate memory for a new node
            SymbolTableNode_t *newNode = (SymbolTableNode_t *)malloc(sizeof(SymbolTableNode_t));

            // Handle allocation error
            if (newNode == NULL) {
                fprintf(stderr, "Unable to allocate memory for a new node\n");
                exit(EXIT_FAILURE);
            }

            // Copy the provided name into the node's name
            strncpy(newNode->label, label, 49);

            // Force null-termination
            newNode->label[49] = '\0';

            // Set its address to the provided address
            newNode->address = address;

            // Point to the next node (null)
            newNode->next = NULL;

            // Return the pointer to the node
            return newNode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Insert Node⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Function to insert a new node at the end of the list
        void insertNode(SymbolTableNode_t **head, const char *label, int address) {

            // Instantiate a new node by calling the create node function
            SymbolTableNode_t *newNode = createNode(label, address);

            // Check if the list is empty by checking if head points to NULL
            if (*head == NULL) {

                // In which case, point to the new and only node
                *head = newNode;
            } 

            // Otherwise set the current node to the provided one
            else {
                SymbolTableNode_t *current = *head;

                // Traverse the nodes until we find the one that points to NULL (the last one)
                while (current->next != NULL) {

                    // Follow where the link goes
                    current = current->next;
                }

                // Once last one has been reached, set its pointer to the newly created node
                current->next = newNode;
            }
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Search Node⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Search a node given a label
        SymbolTableNode_t *searchNode(SymbolTableNode_t *head, const char *label) {

            // Set the current node to the one provided
            SymbolTableNode_t *current = head;

            // Until we have reached the end of the list
            while (current != NULL) {

                // Check if label name matches
                if (strcmp(current->label, label) == 0) {

                    // Return the matching node
                    return current;
                }

                // Otherwise, go to the next node
                current = current->next;
            }

            // Symbol not found
            return NULL;
        }


    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Freeing the table⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        void freeList(SymbolTableNode_t *head) {

            // Set the current as the provided head
            SymbolTableNode_t *current = head;
            SymbolTableNode_t *next;

            // Traverse all the nodes
            while (current != NULL) {

                // Save reference to next node
                next = current->next; 

                // Free current node
                free(current);

                // Move to next node
                current = next; 
            }
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Does Label Exist?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // NOTE: This is redundant with search node
        int isLabelExists(SymbolTableNode_t **head, char *label) {

                // Search the symbol table for the label
                SymbolTableNode_t *current = *head;
                while (current != NULL) {
                    if (strcmp(current->label, label) == 0) {

                        // Label exists
                        return 1;
                    }
                    current = current->next;
                }

                // Otherwise, label does not exist
                return 0; 
            }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Merge Tables⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // This function is used for merging the code and data sections by shifting all the addresses in the data section and appending it to the code section
        void mergeTables(SymbolTableNode_t *head, SymbolTableNode_t **head2, int shift) {
            
            // Calculate the increment value
            int increment = shift * 32; // CHANGED FROM 32

            // Find the last node of head2
            SymbolTableNode_t *current = *head2;
            if (current != NULL) {
                while (current->next != NULL) {
                    current = current->next;
                }
            }

            // Iterate over head, increment address, and append to head2
            while (head != NULL) {

                // Increment the address
                head->address += increment;

                // If head2 is empty, make the current head node the new head2
                if (*head2 == NULL) {
                    *head2 = head;
                    current = *head2;
                } 
                
                // Append the current node of head to the last node of head2
                else {
                    current->next = head;
                    current = current->next;
                }

                // Move to the next node in head
                head = head->next;
            }
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Resolve Address⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // This function will resolve the address of a given label
        int resolveAddress(SymbolTableNode_t *head, const char *label) {
            SymbolTableNode_t *foundNode = searchNode(head, label);
            if (foundNode != NULL) {

                // If the node is found, return its address
                return foundNode->address;
            } 
            
            else {

                // If the node is not found
                return -1;
            }
        }



#endif