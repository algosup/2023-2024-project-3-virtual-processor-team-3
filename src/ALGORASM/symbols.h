// ◊⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛: ⎩°⁍ SYMBOL TABLE ⁌°⎭ :⏛⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯=⎯⏛◊
    // Using a linked list to implement a simple symbol table
    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Create Node⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Function to initialise a new node
        SymbolTableNode_t *createNode(const char *label, int address) {
            SymbolTableNode_t *newNode = (SymbolTableNode_t *)malloc(sizeof(SymbolTableNode_t));
            if (newNode == NULL) {
                fprintf(stderr, "Unable to allocate memory for a new node\n");
                exit(EXIT_FAILURE);
            }
            strncpy(newNode->label, label, 49);
            newNode->label[49] = '\0'; // Ensure null-termination
            newNode->address = address;
            newNode->next = NULL;
            return newNode;
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Insert Node⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Function to insert a new node at the end of the list
        void insertNode(SymbolTableNode_t **head, const char *label, int address) {
            SymbolTableNode_t *newNode = createNode(label, address);
            if (*head == NULL) {
                *head = newNode;
            } else {
                SymbolTableNode_t *current = *head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Search Node⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        // Search a node given a label
        SymbolTableNode_t *searchNode(SymbolTableNode_t *head, const char *label) {
            SymbolTableNode_t *current = head;
            while (current != NULL) {
                if (strcmp(current->label, label) == 0) {
                    return current;
                }
                current = current->next;
            }
            return NULL; // Not found
        }


    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Freeing the table⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        void freeList(SymbolTableNode_t *head) {
            SymbolTableNode_t *current = head;
            SymbolTableNode_t *next;

            while (current != NULL) {
                next = current->next; // Save reference to next node
                free(current); // Free current node
                current = next; // Move to next node
            }
        }

    // ○⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎱Does Label Exist?⎰⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯○
        int isLabelExists(SymbolTableNode_t **head, char *label) {
                // Search the symbol table for the label
                SymbolTableNode_t *current = *head;
                while (current != NULL) {
                    if (strcmp(current->label, label) == 0) {
                        return 1; // Label exists
                    }
                    current = current->next;
                }
                return 0; // Label does not exist
            }


