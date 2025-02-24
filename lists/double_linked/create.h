#ifndef CREATE_H // checks if the header has already been included
#define CREATE_H // if not, define the header

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

/**
 * @brief Defines the structure for a node in the linked list.
 * 
 * @param prev A pointer to the previous node.
 * @param data The data stored in the node.
 * @param next A pointer to the next node.
 */
struct node {
    struct node *prev;
    int data;
    struct node *next;
};

/**
 * @brief Defines the structure for a list with two pointers in the linked list.
 * 
 * @param begin A pointer to the first node.
 * @param end A pointer to the last node.
 */
struct list {
    struct node *begin;
    struct node *end;
};

/**
 * @brief Initializes the linked list to be empty.
 * 
 * @param l A double pointer to the head of the linked list.
 * @return void
 */
void create_list(struct list**);

/**
 * @brief Creates a new node in the linked list.
 * 
 * @param n A double pointer to the node to be created.
 * @return void
 */
void create_node(struct node**);

/**
 * @brief Checks if the linked list is empty.
 * 
 * @param l A pointer to the head of the linked list.
 * @return int 1 if the list is empty, 0 otherwise.
 */
int is_empty(struct list*);

#endif // end of the header guard