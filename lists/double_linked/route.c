/**
 * @file route.c
 * @brief Implementation of the functions to route elements in a linked list.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2025-02-25
 */

#include "route.h" // include the header file with the function prototypes

// clean the entire list
void clean(struct list **l) {
    struct node *aux;
    aux = (*l)->begin; // start from the beginning of the list

    while (aux != NULL) {
        (*l)->begin = aux->next; // update the head of the list
        free(aux); // free the memory allocated for the node
        aux = (*l)->begin; // move to the next node
    }

    (*l)->end = NULL; // update the end pointer
}

// search for an element in the list
void search(struct list **l) {
    struct node *aux;
    aux = (*l)->begin; // start from the beginning of the list

    int n, pos = 0;
    printf("Enter the value to search: ");
    scanf("%d", &n); // read the value to search

    while (aux != NULL) {
        if (aux->data == n) {
            printf("Element found at position %d.\n", pos);
            return;
        }
        aux = aux->next; // move to the next node
        pos++;
    }

    printf("Element not found.\n");
}

// print all elements in the list from the beginning to the end
void print1(struct list **l) {
    struct node *aux;
    aux = (*l)->begin; // start from the beginning of the list

    while (aux != NULL) {
        printf("%d ", aux->data); // print the data in the node
        aux = aux->next; // move to the next node
    }

    printf("\n");
}

// print all elements in the list from the end to the beginning
void print2(struct list **l) {
    struct node *aux;
    aux = (*l)->end; // start from the end of the list

    while (aux != NULL) {
        printf("%d ", aux->data); // print the data in the node
        aux = aux->prev; // move to the previous node
    }

    printf("\n");
}