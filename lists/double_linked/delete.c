/**
 * @file delete.c
 * @brief Implementation of the functions to delete elements in a linked list.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2025-02-25
 */

#include "delete.h" // include the header file with the function prototypes

// delete the first element of the list
void delete_start(struct list **l) {
    struct node *aux;
    aux = (*l)->begin; // get the first element of the list

    if (!(is_empty(*l))) {
        // if the list has only one element
        if ((*l)->begin == (*l)->end) {
            (*l)->begin = NULL;
            (*l)->end = NULL;
        }
        else {
            // update the head of the list
            (*l)->begin = aux->next;
            (*l)->begin->prev = NULL;
        }
        free(aux); // free the memory allocated for the node
    }
}

// delete a node in the middle of the list
void delete_middle(struct list **l) {
    struct node *aux;
    aux = (*l)->begin; // get the first element of the list

    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos); // read the position to delete the data

    int i = 0;
    while (i < pos) {
        aux = aux->next;
        i++;
    }

    if (!(is_empty(*l))) {
        // if the node to be deleted is the first element
        if (aux == (*l)->begin) {
            delete_start(l);
        }
        // if the node to be deleted is the last element
        else if (aux == (*l)->end) {
            delete_end(l);
        }
        else {
            // update the pointers of the previous and next nodes
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux); // free the memory allocated for the node
        }
    }
}

// delete the last element of the list
void delete_end(struct list **l) {
    struct node *aux;
    aux = (*l)->end; // get the last element of the list

    if (!(is_empty(*l))) {
        // if the list has only one element
        if ((*l)->begin == (*l)->end) {
            (*l)->begin = NULL;
            (*l)->end = NULL;
        }
        else {
            // update the end of the list
            (*l)->end = aux->prev;
            (*l)->end->next = NULL;
        }
        free(aux); // free the memory allocated for the node
    }
}