#include <stdio.h>
#include <stdlib.h>

// Definition of the structure for a linked list node
struct node {
    int data;          // Stores the integer data
    struct node *next; // Pointer to the next node in the list
};

// Function to create an empty linked list
void create(struct node **n) {
    n = (struct node **)malloc(sizeof(struct node *)); // Allocates memory for the list pointer
    if (n == NULL) { // Checks if memory allocation was successful
        printf("Memory allocation failed.\n");
        return;
    }
    *n = NULL; // Initializes the list as empty
}

// Function to insert a new node at the beginning of the linked list
void insert(struct node **n) {
    struct node *aux; // Temporary pointer for the new node
    aux = (struct node*)malloc(sizeof(struct node)); // Allocates memory for the new node
    if (aux == NULL) { // Checks if memory allocation was successful
        printf("Memory allocation failed.\n");
        return;
    }   

    int data;
    printf("Enter the value to insert: ");
    scanf("%d", &data); // Reads the value to be inserted

    aux->data = data; // Assigns the value to the new node
    aux->next = *n;   // Points the new node to the current head of the list
    *n = aux;         // Updates the head of the list to the new node

    free(aux); // ERROR: This incorrectly frees the newly inserted node
}

// Main function
int main() {
    struct node *l; // Pointer to the head of the linked list
    create(&l); // Initializes the list

    insert(&l); // Inserts elements into the list
    insert(&l);
    insert(&l);

    return 0;
}