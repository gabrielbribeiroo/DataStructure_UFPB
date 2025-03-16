/*
Consider lists that store strings of characters and implement a function to create a copy of a linked list. 
This function must obey the following prototype:
List *copy(List *l);
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of the structure of a list node
typedef struct lst {
    char data;
    struct lst *next;
} List;

// Function to create an empty list
void create_list(List **list) {
    *list = NULL;
}

