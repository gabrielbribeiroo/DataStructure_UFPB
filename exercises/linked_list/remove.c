/*
Consider lists of integer values ​​and implement a function that receives as parameters a linked list and an integer value n, removes from the list all occurrences of n and returns the resulting list. 
This function must obey the prototype:
list remove_n (List* l, int n);
*/

#include "list.h"

struct list *remove_n(struct list *l, int n) {
    if (l == NULL) return NULL; // If the list is empty, return immediately

    struct list *aux = l;  // Pointer to traverse the list
    struct list *prev = NULL;  // Pointer to the previous node

    while (aux != NULL) {
        if (aux->data == n) {
            struct list *temp = aux; // Store the node to be deleted

            if (prev == NULL) { // If the node to be removed is the first node
                l = aux->next; // Move the head forward
            } else {
                prev->next = aux->next; // Link previous node to next node
            }

            aux = aux->next; // Move aux forward
            free(temp); // Free memory
        } else {
            prev = aux; // Move prev forward only when not deleting
            aux = aux->next;
        }
    }

    return l; // Return the modified list
}

int main() {
    struct list *l;
    create(&l);

    int choice;
    while (1) {
        printf("\n1. Insert\n");
        printf("2. Remove Last\n");
        printf("3. Display\n");
        printf("4. Remove N\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_end(&l);
                break;
            case 2:
                remove_end(&l);
                break;
            case 3:
                display(l);
                break;
            case 4: {
                int n;
                printf("Enter the element to be removed: ");
                scanf("%d", &n);
                l = remove_n(l, n);
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;    
}