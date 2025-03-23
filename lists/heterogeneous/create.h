#ifndef CREATE_H // checks if the header has already been included
#define CREATE_H // if not, define the header

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

/**
 * @brief Structure representing a generic node in a linked list.
 * @param id Identifier for the node
 * @param info Pointer to generic data
 * @param prox Pointer to the next node in the list
 */
struct node;

/**
 * @brief Structure representing a rectangle of type 0.
 * @param b Base of the rectangle
 * @param h Height of the rectangle
 */
struct rectangle;

/**
 * @brief Structure representing a triangle of type 1.
 * @param b Base of the triangle
 * @param h Height of the triangle
 */
struct triangle;

/**
 * @brief Structure representing a circle of type 2.
 * @param r Radius of the circle
 */
struct circle;

/**
 * @brief Creates and initializes a rectangle.
 * @param rect A double pointer to struct rectangle, where the allocated memory will be stored.
 */
void create_a(struct rectangle**);

/**
 * @brief Creates and initializes a triangle.
 * @param tri A double pointer to struct triangle, where the allocated memory will be stored.
 */
void create_b(struct triangle**);

/**
 * @brief Creates and initializes a circle.
 * @param circ A double pointer to struct circle, where the allocated memory will be stored.
 */
void create_c(struct circle**);

/**
 * @brief Checks if the list is empty
 * @param node A pointer to the head of the linked list.
 * @return int Returns 1 if the list is empty, 0 otherwise. 
 */
int is_empty(struct node*);

#endif // end of the header guard