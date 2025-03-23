#ifndef INSERT_H // checks if the header has already been included
#define INSERT_H // if not, define the header

#include "create.h"

/**
 * @brief Inserts a new element at the beginning of the list
 * @param node A double pointer to the head of the linked list.
 * @return void
 */
void insert_start(struct node**);

/**
 * @brief Inserts a new node in the middle of a linked list.
 * @param node A double pointer to the head of the linked list.
 * @return void
 */
void insert_middle(struct node**);

/**
 * @brief Inserts a new element at the end of the list
 * @param node A double pointer to the head of the linked list.
 * @return void
 */
void insert_end(struct node**);

#endif // end of the header guard