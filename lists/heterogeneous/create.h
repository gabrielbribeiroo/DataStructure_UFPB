#ifndef CREATE_H // checks if the header has already been included
#define CREATE_H // if not, define the header

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

/**
 * @brief Structure representing a generic node in a linked list.
 * @param info Pointer to generic data
 * @param id Identifier for the node
 * @param prox Pointer to the next node in the list
 */
struct node;

/**
 * @brief Structure representing an entity of type A.
 * @param x First integer value
 * @param y Second integer value
 */
struct a;

/**
 * @brief Structure representing an entity of type B.
 * @param c Floating-point value
 * @param radius Integer radius value
 */
struct b;

/**
 * @brief Structure representing an entity of type C.
 * @param a1 First integer value
 * @param a2 Second integer value
 * @param a3 Third integer value
 */
struct c;

/**
 * @brief Creates and initializes a structure of type A.
 * @param aa A double pointer to struct a, where the allocated memory will be stored.
 */
void create_a(struct a**);

/**
 * @brief Creates and initializes a structure of type B.
 * @param bb A double pointer to struct b, where the allocated memory will be stored.
 */
void create_b(struct b**);

/**
 * @brief Creates and initializes a structure of type C.
 * @param cc A double pointer to struct c, where the allocated memory will be stored.
 */
void create_c(struct c**);

/**
 * @brief Checks if the list is empty
 * @param node A pointer to the head of the linked list.
 * @return int Returns 1 if the list is empty, 0 otherwise. 
 */
int is_empty(struct node*);

#endif // end of the header guard