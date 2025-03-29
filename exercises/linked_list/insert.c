#include <stdio.h>
#include <stdlib.h>

// Definition of the structure for a linked list node
struct node {
    int data;          // Stores the integer data
    struct node *next; // Pointer to the next node in the list
};

// Function to create an empty linked list
void create(struct node **n) {
    *n = NULL; // Initializes the list as empty
}

// Function to insert a new node at the beginning of the linked list
void insert(struct node **n) {
    struct node *aux = (struct node*)malloc(sizeof(struct node)); // Allocates memory for the new node
    if (aux == NULL) { // Checks if memory allocation was successful
        printf("Memory allocation failed.\n");
        return;
    }   

    printf("Enter the value to insert: ");
    scanf("%d", &aux->data); // Reads the value to be inserted

    aux->next = *n;   // Points the new node to the current head of the list
    *n = aux;         // Updates the head of the list to the new node
}

// Function to insert a new node at the end of the linked list
void insert_end(struct node **n, int d) {
    struct node *new = (struct node*)malloc(sizeof(struct node)); // Allocates memory for the new node
    if (new == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    new->data = d;    // Sets the data value
    new->next = NULL; // The new node is the last one, so next is NULL

    if (*n == NULL) { // If the list is empty, the new node becomes the head
        *n = new;
    }
    else {
        struct node *aux = *n;
        while (aux->next != NULL) { // Traverse the list to find the last node
            aux = aux->next;
        }
        aux->next = new; // Attach the new node at the end
    }
}

// Function to insert a value in an ordered manner
void ordered(struct node **n) {
    struct node *new_list = NULL; // Creates a new list to store sorted elements

    printf("Enter the value to insert: ");
    int data;
    scanf("%d", &data);

    struct node *aux = *n; // Pointer to traverse the existing list

    while (aux != NULL) {
        if (aux->data < data) {
            insert_end(&new_list, aux->data); // Inserts elements smaller than data
        }
        else {
            insert_end(&new_list, data); // Inserts the new element before larger ones
            data = 9999999; // Ensures data is only inserted once
        }
        aux = aux->next;
    }

    if (data != 9999999) { // If data wasn't inserted, add it at the end
        insert_end(&new_list, data);
    }

    *n = new_list; // Update the original list with the sorted one
}

// Function to remove the first element from the linked list
void remove_start(struct node **n) {
    if (*n == NULL) { // Checks if the list is empty
        printf("The list is already empty.\n");
        return;
    }

    struct node *temp = *n; // Temporary pointer to store the first node
    *n = (*n)->next; // Update the head to the next node
    free(temp); // Free the memory of the removed node
    printf("First element removed successfully.\n");
}

// Function to print the linked list
void print_list(struct node *n) {
    printf("List elements: ");
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct node *l; // Pointer to the head of the linked list
    create(&l); // Initializes the list

    insert(&l); // Inserts elements into the list
    insert(&l);
    insert(&l);

    print_list(l); // Print the list before ordering

    ordered(&l); // Insert and maintain sorted order
    print_list(l); // Print the sorted list

    remove_start(&l); // Remove the first element
    print_list(l); // Print the list after removal

    return 0;
}