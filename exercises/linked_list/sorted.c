#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    int data;          // Stores the integer data
    struct node *prev; // Pointer to the previous node
    struct node *next; // Pointer to the next node
};

// Definition of the doubly linked list structure
struct list {
    struct node *begin; // Pointer to the first node in the list
    struct node *end;   // Pointer to the last node in the list
};

// Function to create an empty list
void create_list(struct list **l) {
    *l = (struct list *)malloc(sizeof(struct list)); // Allocates memory for the list
    if (*l == NULL) { // Checks if memory allocation was successful
        printf("Memory allocation error.\n");
        return;
    }
    (*l)->begin = NULL; // Initializes the list as empty
    (*l)->end = NULL;
}

// Function to create a new node
void create_node(struct node **n) {
    *n = (struct node *)malloc(sizeof(struct node)); // Allocates memory for the node
    if (*n == NULL) { // Checks if memory allocation was successful
        printf("Memory allocation error.\n");
        return;
    }
    (*n)->prev = NULL; // Initializes pointers to NULL
    (*n)->next = NULL;
}

// Function to insert a node at the beginning of the list
void insert_begin(struct list *l, int data) {
    struct node *new_node;
    create_node(&new_node); // Creates a new node
    if (new_node == NULL) return;

    new_node->data = data; // Assigns the data

    if (l->begin == NULL) { // If the list is empty
        l->begin = new_node;
        l->end = new_node;
    } else {
        new_node->next = l->begin;
        l->begin->prev = new_node;
        l->begin = new_node;
    }
}

// Function to insert a node at the end of the list
void insert_end(struct list *l, int data) {
    struct node *new_node;
    create_node(&new_node); // Creates a new node
    if (new_node == NULL) return;

    new_node->data = data;

    if (l->end == NULL) { // If the list is empty
        l->begin = new_node;
        l->end = new_node;
    } else {
        new_node->prev = l->end;
        l->end->next = new_node;
        l->end = new_node;
    }
}

// Function to sort the list using Bubble Sort
void sort_list(struct list *l) {
    if (l->begin == NULL) return; // If the list is empty, do nothing

    int swapped;
    struct node *ptr;
    struct node *last = NULL; // Marks the last sorted element

    do {
        swapped = 0;
        ptr = l->begin;

        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) { // Swap adjacent nodes if needed
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr; // Updates the last sorted element
    } while (swapped);
}

// Function to print the list
void print_list(struct list *l) {
    struct node *ptr = l->begin;
    printf("List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Main function to test the implementation
int main() {
    struct list *l;
    create_list(&l); // Creates an empty list

    // Inserting elements at the beginning
    insert_begin(l, 5);
    insert_begin(l, 3);
    insert_begin(l, 9);

    printf("List before sorting:\n");
    print_list(l);

    // Inserting elements at the end
    insert_end(l, 1);
    insert_end(l, 8);
    
    printf("List after inserting at the end:\n");
    print_list(l);

    // Sorting the list
    sort_list(l);

    printf("List after sorting:\n");
    print_list(l);

    return 0;
}