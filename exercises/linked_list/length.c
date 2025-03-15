/*
Implement a function that returns the length of a linked list, that is, that calculates the number of nodes in a list. 
This function must conform to the following prototype:
int length(List* l);
*/

#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};

// Create a new linked list
void create(struct list **l) {
    *l = (struct list *)malloc(sizeof(struct list));
    if (*l == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    (*l)->next = NULL;
}

// Insert a new node at the end of the list
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

// Remove the last node from the list
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

// Display the list
void display(struct list *l) {
    if (l->next == NULL) {
        printf("List is empty\n");
        return;
    }
    struct list *temp = l->next; // Skip the dummy node
    printf("List: ");
    // Traverse the list
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int length(struct list *l) {
    int count = 0;
    struct list *temp = l->next; // Skip the dummy node
    // Traverse the list
    while (temp != NULL) {
        count++; // Increment the count
        temp = temp->next; // Move to the next node
    }
    return count;
}

int main() {
    struct list *l;
    create(&l);

    int choice;
    while (1) {
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Display\n");
        printf("4. Length\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_end(l);
                break;
            case 2:
                remove_end(l);
                break;
            case 3:
                display(l);
                break;
            case 4:
                printf("Length: %d\n", length(l));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}