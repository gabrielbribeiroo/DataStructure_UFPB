/*
Implement a function that receives two linked lists of real values ​​and returns the list resulting from the concatenation of the two lists received as parameters, that is, after concatenation, the last element of the first list must point to the first element of the second list, as illustrated below:
This function must follow the prototype:
List concatenates(List* l1, List* l2);
*/

#include "list.h"

struct list *concatenates(struct list *l1, struct list *l2) {
    struct list *aux = l1->next; // creates an auxiliary pointer to the first list
    while (aux->next != l1) {
        aux = aux->next; // goes to the last node of the first list
    }
    aux->next = l2->next; // connects the last node of the first list to the first node of the second list
    l2->next = l1; // connects the last node of the second list to the first node of the first list
    return l1; // returns the concatenated list
}

int main() {
    struct list *l;
    create(&l);

    int choice;
    while (1) {
        printf("\n1. Insert\n");
        printf("2. Remove\n");
        printf("3. Display\n");
        printf("4. Concatenates\n");
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
            case 4: {
                struct list *l2;
                create(&l2);
                insert_end(l2);
                insert_end(l2);
                concatenates(l, l2);
                display(l);
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