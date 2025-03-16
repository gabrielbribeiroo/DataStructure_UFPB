/*
Consider lists that store strings of characters and implement a function to test whether two lists passed as parameters are equal.
This function must obey the prototype:
int equals(List *l1, List *l2);
*/

#include "list.h"

typedef struct list List;

// Inserts a new node with the given value after the given node
// Inserts a new node at the end of the list
void insert(List **list, int value) {
    List *new_node = (List *)malloc(sizeof(List));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    // If the list is empty, initialize it with the new node
    if (*list == NULL) {
        *list = new_node;
        return;
    }

    // Traverse to the last node
    List *temp = *list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// function to calculate the size of the list
int size(List *l) {
    int size = 0; // size of the list
    List *aux = l; // auxiliary pointer to go through the list
    // go through the list counting the number of elements
    while (aux != NULL) {
        size++; // increment the size
        aux = aux->next; // go to the next element
    }
    return size; // return the size of the list
}

int equals(List *l1, List *l2) {
    if (size(l1) != size(l2)) {
        return 0; // if the sizes are different, the lists are different
    }

    List *aux1 = l1; // auxiliary pointer to go through the first list
    List *aux2 = l2; // auxiliary pointer to go through the second list

    // go through the lists comparing the elements
    while (aux1 != NULL) {
        if (aux1->data != aux2->data) {
            return 0; // if the elements are different, the lists are different
        }

        aux1 = aux1->next; // go to the next element of the first list
        aux2 = aux2->next; // go to the next element of the second list
    }

    return 1; // if the lists are the same, return 1
}

int main() {
    List *l1, *l2; // lists to be compared
    create(&l1); // create the first list
    create(&l2); // create the second list

    // insert elements in the first list
    insert(&l1, 1);
    insert(&l1, 2);
    insert(&l1, 3);

    // insert elements in the second list
    insert(&l2, 1);
    insert(&l2, 2);
    insert(&l2, 3);

    // test if the lists are equal
    if (equals(l1, l2)) {
        printf("Lists are equal\n");
    } 
    else {
        printf("Lists are different\n");
    }

    return 0;   
}