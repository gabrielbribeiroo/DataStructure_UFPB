/**
 * @file route.c
 * @brief Stack route implementation
 * 
 * @author Gabriel Ribeiro
 * @version 1.2
 * @date 2025-03-11
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
    printf("\nList: ");
    for (int i = 0; i <= l->ctr; i++) {
		printf("%d ", l->data[i]);
	} 
	printf("\n");
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

// Print all elements in the linked list from the beginning to the end
void print_linked_list(struct node *l) {
    struct node *aux = l;
    printf("\nList: ");
    while (linked_list_empty(aux) == '1') {
        printf("%d ", aux->data); // print data of each node
        aux = aux->next;
    }
    printf("\n");
}