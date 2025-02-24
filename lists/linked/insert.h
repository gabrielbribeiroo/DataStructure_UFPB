#ifndef INSERT_H // checks if the header has already been included
#define INSERT_H // if not, define the header

#include "create.h"

/**
 * @brief Inserts a new element at the beginning of the list
 * @param knot A double pointer to the head of the linked list.
 * @return void
 */
void insert_start(struct knot**);

/**
 * @brief Inserts a new node in the middle of a linked list.
 * @param knot A double pointer to the head of the linked list.
 * @return void
 */
void insert_middle(struct knot**);

/**
 * @brief Inserts a new element at the end of the list
 * @param knot A double pointer to the head of the linked list.
 * @return void
 */
void insert_end(struct knot**);

/**
 * @brief Checks if the list is empty
 * @param knot A pointer to the head of the linked list.
 * @return int Returns 1 if the list is empty, 0 otherwise. * 
 */
int is_empty(struct knot*);

#endif // end of the header guard