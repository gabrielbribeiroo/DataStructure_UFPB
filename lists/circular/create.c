/**
 * @file create.c
 * @brief Implementation of the function to create a circular list.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2025-02-26
 */

#include "create.h" // include the header file with the function prototypes

// circular list by vector
// initializes the list to be empty
void create_vector_list(struct vector *l) {
    l->head = 0; // sets the head to 0
    l->tail = 0; // sets the tail to 0
    l->size = 0; // sets the size to 0
}

// checks if the list is full
char vector_full(struct vector l) {
    return (l.size == SIZE); // returns 1 if the size is equal to SIZE
}

// checks if the list is empty
char vector_empty(struct vector l) {
    return (l.size == 0); // returns 1 if the size is 0
}


// circular list by linked list
// initializes the linked list to be empty
void create_linked_list(struct node **l) {
    *l = NULL; // sets the head pointer to NULL
}

// checks if the linked list is empty
char linked_list_empty(struct node *l) {
    return (l == NULL); // returns 1 if the head pointer is NULL
}


// circular list by double linked list
// initializes the list to be empty
void create_double_linked_list(struct list **l) {
    *l = (struct list*)malloc(sizeof(struct list)); // allocates memory for the list
    (*l)->begin = NULL; // sets the begin pointer to NULL
    (*l)->end = NULL; // sets the end pointer to NULL
}

// creates a new node in the linked list
void create_double_linked_node(struct dnode **n) {
    *n = (struct dnode*)malloc(sizeof(struct dnode)); // allocates memory for the node
    (*n)->prev = NULL; // sets the prev pointer to NULL
    (*n)->next = NULL; // sets the next pointer to NULL
}

// checks if the list is empty
char double_linked_list_empty(struct list **l) {
    return ((*l)->begin == NULL && (*l)->end == NULL); // returns 1 if the begin and end pointers are NULL
}