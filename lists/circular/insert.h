#ifndef INSERT_H // checks if the header has already been included
#define INSERT_H // if not, define the header

#include "create.h" // for vector, linked list and double linked list

// circular list by vector
/**
 * @brief Inserts a new element at the beginning of the vector.
 * @param l A pointer to the vector.
 * @param data The data to be inserted.
 * @return void
 */
void insert_begin_vector(struct vector *l, int data);

/**
 * @brief Inserts a new element at the middle of the vector.
 * @param l A pointer to the vector.
 * @param data The data to be inserted.
 * @return void
 */
void insert_middle_vector(struct vector *l, int data);

/**
 * @brief Inserts a new element at the end of the vector.
 * @param l A pointer to the vector.
 * @param data The data to be inserted.
 * @return void
 */
void insert_end_vector(struct vector *l, int data);


// circular list by linked list
/**
 * @brief Inserts a new element at the beginning of the linked list.
 * @param l A pointer to the head of the linked list.
 * @param data The data to be inserted.
 * @return void
 */
void insert_begin_linked_list(struct node **l, int data);

/**
 * @brief Inserts a new element at the middle of the linked list.
 * @param l A pointer to the head of the linked list.
 * @param data The data to be inserted.
 * @return void
 */
void insert_middle_linked_list(struct node **l, int data);

/**
 * @brief Inserts a new element at the end of the linked list.
 * @param l A pointer to the head of the linked list.
 * @param data The data to be inserted.
 * @return void
 */
void insert_end_linked_list(struct node **l, int data);


// circular list by double linked list
/**
 * @brief Inserts a new element at the beginning of the double linked list.
 * @param l A pointer to the head of the double linked list.
 * @param data The data to be inserted.
 * @return void
 */
void insert_begin_double_linked_list(struct node **l, int data);

/**
 * @brief Inserts a new element at the middle of the double linked list.
 * @param l A pointer to the head of the double linked list.
 * @param data The data to be inserted.
 * @return void
 */
void insert_middle_double_linked_list(struct node **l, int data);

/**
 * @brief Inserts a new element at the end of the double linked list.
 * @param l A pointer to the head of the double linked list.
 * @param data The data to be inserted.
 * @return void
 */
void insert_end_double_linked_list(struct node **l, int data);

#endif // end of the header guard