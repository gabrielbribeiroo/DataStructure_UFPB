/*
Implement a function that receives a linked list as a parameter and reverses the chaining of its nodes, returning the resulting list. 
After executing this function, each node in the list will point to the node that was originally its predecessor, and the last node in the list will become the first node in the reversed list, as illustrated below:
This function must follow the prototype:
List *reverse(List *l);
*/

#include "list.h"

typedef struct list List;

List *reverse(List *l) {
    List *prev = NULL; // previous node
    List *current = l; // current node
    List *next = NULL; // next node

    // iterate through the list
    while (current != NULL) {
        next = current->next; // save next node
        current->next = prev; // reverse the link
        prev = current; // move pointers one position ahead
        current = next; // move pointers one position ahead
    }

    return prev; // return the new head of the list
}

int main() {
    List *l;
    create(&l);

    int choice;
    while (1) {
        printf("\n1. Insert\n");
        printf("2. Remove\n");
        printf("3. Display\n");
        printf("4. Reverse\n");
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
            case 4:
                l = reverse(l); // reverse the list
                display(l);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}