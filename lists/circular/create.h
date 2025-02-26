#ifndef CREATE_H // checks if the header has already been included
#define CREATE_H // if not, define the header

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

#define SIZE 9 // size of the vector

// circular list by vector
/**
 * @brief Defines the structure for a vector in a circular list.
 * 
 * @param data The data stored in the vector.
 * @param head The index of the head element.
 * @param tail The index of the tail element.
 * @param size The current size of the vector. * 
 */
struct vector {
    int data[SIZE]; // data
    int head, tail, size; // control variables
};

/**
 * @brief Initializes the list to be empty.
 * 
 * @param l A pointer to the head of the vector.
 * @return void
 */
void create_list(struct vector *);

/**
 * @brief Checks if the list is full.
 * 
 * @param l The vector.
 * @return char 1 if the list is full, 0 otherwise.
 */
char full(struct vector);

/**
 * @brief Checks if the list is empty.
 * 
 * @param l The vector.
 * @return char 1 if the list is empty, 0 otherwise.
 */
char empty(struct vector);


// circular list by linked list
/**
 * @brief Defines the structure for a node in the linked list.
 * 
 * @param data The data stored in the node.
 * @param next A pointer to the next node.
 */
struct node {
    int data;
    struct node *next;
};

/**
 * @brief Initializes the linked list to be empty.
 * 
 * @param l A double pointer to the head of the linked list.
 * @return void
 */
void create_list(struct node**);

/**
 * @brief Checks if the linked list is empty.
 * 
 * @param l A ointer to the head of the linked list.
 * @return int 1 if the list is empty, 0 otherwise.
 */
char empty(struct node*);


// circular list by double linked list
/**
 * @brief Defines the structure for a node in the linked list.
 * 
 * @param prev A pointer to the previous node.
 * @param data The data stored in the node.
 * @param next A pointer to the next node.
 */
struct dnode {
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
 * @param l A double pointer to the head of the linked list.
 * @return char 1 if the list is empty, 0 otherwise.
 */
char empty(struct list**);

#endif // end of the header guard