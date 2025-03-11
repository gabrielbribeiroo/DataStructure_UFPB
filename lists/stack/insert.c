/**
 * @file insert.c
 * @brief This file implements the insertion functions for the stack.
 * 
 * @author Gabriel Ribeiro
 * @version 2.0
 * @date 2025-03-10
 */

#include "insert.h" // include the header file with the function prototypes

// list by vector
// inserts a new element at the end of the vector
void push_vector(struct vector *l) {
    if (vector_full(*l)) { // if the list is full
        printf("The list is full.\n"); // prints a message
        return; // returns
    }
    int data;
    printf("Data: ");
    scanf("%d", &data);
    l->data[l->ctr] = data; // inserts the data
    l->ctr++; // increments the size
}


// list by linked list
// inserts a new element at the beginning of the linked list
void push_linked_list(struct node **l) {
    int data;
    printf("Data: ");
    scanf("%d", &data);
    struct node *new_node = (struct node*)malloc(sizeof(struct node)); // Allocates memory for the new node
    new_node->data = data; // Inserts the data
    new_node->next = *l; // Points to the previous head (or NULL if the list is empty)
    *l = new_node; // Sets the head pointer to the new node
}