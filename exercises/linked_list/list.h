#ifndef LIST_H // checks if the header has already been included
#define LIST_H // if not, define the header

#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};

// Create a new linked list
void create(struct list **l) {}

// Insert a new node at the end of the list
void insert_end(struct list *l) {}

// Remove the last node from the list
void remove_end(struct list *l) {}

// Display the list
void display(struct list *l) {}

#endif // end of the header guard