/**
 * @file create.c
 * @brief Implementation of the function to create a linked list.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2025-02-24
 */

#include "create.h" // include the header file with the function prototypes

// initializes the linked list to be empty
void create_list(struct list **l) {
    *l = (struct list*)malloc(sizeof(struct list)); // allocates memory for the list
    (*l)->begin = NULL; // sets the begin pointer to NULL
    (*l)->end = NULL; // sets the end pointer to NULL
}

// creates a new node in the linked list
void create_node(struct node **n) {
    *n = (struct node*)malloc(sizeof(struct node)); // allocates memory for the node
    (*n)->prev = NULL; // sets the prev pointer to NULL
    (*n)->next = NULL; // sets the next pointer to NULL
}

// checks if the list is empty
int is_empty(struct list **l) {
    return ((*l)->begin == NULL && (*l)->end == NULL);
}