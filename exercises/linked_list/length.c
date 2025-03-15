/*
Implement a function that returns the length of a linked list, that is, that calculates the number of nodes in a list. 
This function must conform to the following prototype:
int length(List* l);
*/

#include "list.h"

int length(struct list *l) {
    int count = 0;
    struct list *temp = l->next; // Skip the dummy node
    // Traverse the list
    while (temp != NULL) {
        count++; // Increment the count
        temp = temp->next; // Move to the next node
    }
    return count;
}

int main() {
    struct list *l;
    create(&l);

    int choice;
    while (1) {
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Display\n");
        printf("4. Length\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_end(l);
                break;
            case 2:
                remove_end(l);
                break;
            case 3:
                display(l);
                break;
            case 4:
                printf("Length: %d\n", length(l));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}