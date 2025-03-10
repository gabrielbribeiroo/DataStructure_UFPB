/**
 * @file insert.c
 * @brief This file implements the insertion functions for the stack.
 * 
 * @author Gabriel Ribeiro
 * @version 1.1
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
    struct node *new_node; // creates a new node
    new_node = (struct node*)malloc(sizeof(struct node)); // allocates memory for the new node
    new_node->data = data; // inserts the data
    if (linked_list_empty(*l)) { // if the list is empty
        new_node->next = new_node; // points to itself
        *l = new_node; // sets the head pointer to the new node
    } 
    else { // if the list is not empty
        struct node *last = *l; // creates a pointer to the last node
        while (last->next != *l) { // iterates over the list
            last = last->next; // moves to the next node
        }
        new_node->next = *l; // points to the head
        last->next = new_node; // inserts the new node
        *l = new_node; // sets the head pointer to the new node
    }
}