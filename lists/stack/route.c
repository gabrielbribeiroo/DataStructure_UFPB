/**
 * @file route.c
 * @brief Stack route implementation
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2025-03-10
 */

#include "route.h" // for list

// list by vector
// clean the entire list
void clean_vector_list(struct vector *l) {
    l->ctr = 0; // sets the control to zero
}

// search for an element in the list
void search_vector_list(struct vector *l) {
    printf("Element of top of the stack: %d\n", l->data[l->ctr - 1]);
}

// print all elements in the list
void print_vector_list(struct vector *l) {
    if (!l->ctr) {
        printf("Empty list.\n");
        return;
    }
    else {
        print_vector_list(&l);
        printf(l->data[l->ctr - 1]);
    }
}


// list by linked list
// clean the stack
void clean_linked_list(struct node **l) {
    if (*l == NULL) {
        return;
    }
    else {
        clean_linked_list(&(*l)->next);
        free(*l);
        *l = NULL;
    }
}

// search for the top element of the stack
void search_linked_list(struct node **l) {
    if (*l == NULL || (*l)->next == *l) {
        printf("Empty list.\n");
        return;
    }
    else {
        printf("Element of top of the stack: %d\n", (*l)->data);
    }
}

// print all elements in the list from the beginning to the end
void print_linked_list(struct node **l) {
    if ((*l)->next == *l) {
        printf("Empty list.\n");
        return;
    }
    else {
        print_linked_list(&(*l)->next);
        printf("%d ", (*l)->data);
    }
}