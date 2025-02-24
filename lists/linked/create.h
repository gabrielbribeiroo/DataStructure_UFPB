#ifndef CREATE_H // checks if the header has already been included
#define CREATE_H // if not, define the header

#include <stdlib.h> // for malloc

/**
 * @brief Defines the structure for a node in the linked list.
 * 
 * @param data The data stored in the node.
 * @param next A pointer to the next node.
 */
struct knot {
    int data;
    struct knot *next;
};

/**
 * @brief Initializes the linked list to be empty. 
 * 
 * @param l A double pointer to the head of the linked list.
 * @return void
 */
// initialize the list to be empty
void create(struct knot**);

#endif // end of the header guard