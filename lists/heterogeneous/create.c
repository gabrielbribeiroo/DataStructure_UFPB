/**
 * @file create.c
 * @brief Implementation of the function to create a heterogeneous linked list.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2025-03-22
 */

#include "create.h" // include the header file with the function prototypes

/**
 * @brief Structure representing a generic node in a linked list.
 */
struct node {
    void *info;       // Pointer to generic data 
    int id;           // Identifier for the node
    struct node *next; // Pointer to the next node in the list
};

/**
 * @brief Structure representing an entity of type A.
 */
struct a {
    int x; // First integer value
    int y; // Second integer value
};

/**
 * @brief Structure representing an entity of type B.
 */
struct b {
    float c;   // Floating-point value
    int radius; // Integer radius value
};

/**
 * @brief Structure representing an entity of type C.
 */
struct c {
    int a1; // First integer value
    int a2; // Second integer value
    int a3; // Third integer value
};

/**
 * @brief Creates and initializes a structure of type A.
 * 
 * @param aa A double pointer to struct a, where the allocated memory will be stored.
 */
void create_a(struct a **aa) {
    *aa = (struct a*)malloc(sizeof(struct a));
    if (*aa) {
        (*aa)->x = 0;
        (*aa)->y = 0;
    }
}

/**
 * @brief Creates and initializes a structure of type B.
 * 
 * @param bb A double pointer to struct b, where the allocated memory will be stored.
 */
void create_b(struct b **bb) {
    *bb = (struct b*)malloc(sizeof(struct b));
    if (*bb) {
        (*bb)->c = 0.0f;
        (*bb)->radius = 0;
    }
}

/**
 * @brief Creates and initializes a structure of type C.
 * 
 * @param cc A double pointer to struct c, where the allocated memory will be stored.
 */
void create_c(struct c **cc) {
    *cc = (struct c*)malloc(sizeof(struct c));
    if (*cc) {
        (*cc)->a1 = 0;
        (*cc)->a2 = 0;
        (*cc)->a3 = 0;
    }
}

/**
 * @brief Checks if the list is empty
 * @param node A pointer to the head of the linked list.
 * @return int Returns 1 if the list is empty, 0 otherwise. 
 */
int is_empty(struct node *l) {
    return l == NULL;
}