/**
 * @file create.c
 * @brief Implementation of the function to create a queue.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2025-03-17
 */

#include "create.h" // include the header file with the function prototypes

// queue by vector
// initializes the list to be empty
void create_vector_list(struct vector *l) {
    l = (struct vector *) malloc(sizeof(struct vector)); // allocates memory for the vector
    l->n = 0; // sets the number of elements to 0
    l->start = 0; // sets the index of the first element to 0
}

// checks if the list is empty
int vector_empty(struct vector l) {
    return (l.n == 0); // returns 1 if the number of elements is 0
}


// queue by linked list
// initializes the linked list to be empty 
void create_linked_list(struct queue **l) {
    *l = (struct queue *) malloc(sizeof(struct queue)); // allocates memory for the queue
    (*l)->head = NULL; // sets the head pointer to NULL
    (*l)->tail = NULL; // sets the tail pointer to NULL
}

// checks if the linked list is empty
int linked_list_empty(struct queue *l) {
    return (l->head == NULL); // returns 1 if the head pointer is NULL
}


// queue by doubly linked list
// initializes the doubly linked list to be empty
void create_doubly_linked_list(struct dqueue **l) {
    *l = (struct dqueue *) malloc(sizeof(struct dqueue)); // allocates memory for the doubly linked list
    (*l)->head = NULL; // sets the head pointer to NULL
    (*l)->tail = NULL; // sets the tail pointer to NULL
}

// checks if the doubly linked list is empty
int doubly_linked_list_empty(struct dqueue *l) {
    return (l->head == NULL); // returns 1 if the head pointer is NULL
}