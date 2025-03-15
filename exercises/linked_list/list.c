/**
 * @file list.c
 * @brief Implements the functions defined in list.h
 * 
 * @author Gabriel Ribeiro
 * @date 2025-03-15
 * @version 1.0
 */

#include "list.h"

// Initializes the linked list to be empty
void create(struct list **l) {
    *l = (struct list *)malloc(sizeof(struct list));
    if (*l == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    (*l)->next = NULL;
}

// Checks if the list is empty
int is_empty(struct list *l) {
    return l->next == NULL;
}

// Inserts a node at the end of the list
void insert_end(struct list *l) {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    struct list *new_node = (struct list *)malloc(sizeof(struct list));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    // Initialize the new node
    new_node->data = data;
    new_node->next = NULL;

    // Traverse to the last node
    struct list *temp = l;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node; // Insert the new node at the end
}

// Removes a node from the end of the list
void remove_end(struct list *l) {
    if (l->next == NULL) {
        printf("List is empty\n");
        return;
    }
    struct list *temp = l;
    // Traverse to the second last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next); // Free the last node
    temp->next = NULL; // Set the next of second last node to NULL
}

// Displays the list
void display(struct list *l) {
    if (l->next == NULL) {
        printf("List is empty\n");
        return;
    }
    struct list *temp = l->next;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}