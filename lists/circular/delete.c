/**
 * @file delete.c
 * @brief This file implements the deletion functions for the circular list.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2025-03-01
 */

#include "delete.h" // include the header file with the function prototypes

// circular list by vector
// deletes the first element of the vector
void delete_begin_vector(struct vector *l) {
    if (vector_empty(l)) { // if the list is empty
        printf("The list is empty.\n"); // prints a message
        return; // returns
    }
    l->head = (l->head + 1) % SIZE; // increments the head
    l->size--; // decrements the size
}