/*
Create, insert, delete, clean, search, and print a linked list.
*/

#include <stdio.h>
#include <stdlib.h>

// define the structure for a node in the linked list
struct knot {
    int data; // data stored in the node
    struct knot *next; // pointer to the next node
} *l;

// function prototypes
void create(struct knot**);
void insert_start(struct knot**);
void insert_end(struct knot**);
int is_empty(struct knot*);
void delete(struct knot**);
void clean(struct knot**);
void search(struct knot*);
void print(struct knot*);
void display_menu(struct knot**);

int main() {
    struct knot *l; // pointer to the head of the list

    create(&l); // initialize the list
    display_menu(&l); // display menu and handle user options

    return 0;
}

// initialize the list to be empty
void create(struct knot **l) {
    *l = NULL;
}

// insert a new element at the beginning of the list
void insert_start(struct knot **l) {
    struct knot *new;
    new = (struct knot *)malloc(sizeof(struct knot)); // allocate memory for the new node
    // check if memory was allocated
    if (new == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    int n;
    printf("Enter the value to insert: ");
    scanf("%d", &n); // read the data to be inserted
    
    // insert data into the new node
    new->data = n;
    new->next = *l;

    // update the head of the list
    *l = new;    
}

void insert_end(struct knot **l) {
    struct knot *new, *aux;
    new = (struct knot *)malloc(sizeof(struct knot)); // allocate memory for the new node
    // check if memory was allocated
    if (new == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    int n;
    printf("Enter the value to insert: ");
    scanf("%d", &n); // read the data to be inserted

    // insert data into the new node
    new->data = n;
    new->next = NULL;

    // if the list is empty, the new node becomes the head
    if (is_empty(*l)) {
        *l = new;
    } 
    else {
        // traverse to the end of the list
        aux = *l;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        // insert the new node at the end
        aux->next = new;
    }
}

int is_empty(struct knot *l) {
    return l == NULL;
}

// delete an element from the list
void delete(struct knot **l) {
    struct knot *aux, *prev;
    aux = *l;
    prev = NULL;

    int n;
    printf("Enter the value to delete: ");
    scanf("%d", &n); // read the data to be deleted

    // search for the element
    while (!is_empty(aux) && aux->data != n) {
        prev = aux;
        aux = aux->next;
    }

    // check if the element was found
    if (is_empty(aux)) {
        printf("Element not found\n");
        return;
    }

    // check if the element is the first in the list
    if (prev == NULL) {
        *l = aux->next;
    } 
    else {
        prev->next = aux->next;
    }

    // free memory of the deleted node
    free(aux);
}

// clean the entire list
void clean(struct knot **l) {
    struct knot *aux;
    while (!is_empty(*l)) {
        aux = *l;
        *l = (*l)->next;
        free(aux); // free memory of each node
    }
}

// search for an element in the list
void search(struct knot *l) {
    struct knot *aux = l;
    int n;
    printf("Enter the value to search: ");
    scanf("%d", &n); // read the data to be searched

    // search for the element
    while (!is_empty(aux) && aux->data != n) {
        aux = aux->next;
    }

    // check if the element was found
    if (is_empty(aux)) {
        printf("Element not found\n");
    } 
    else {
        printf("Element found\n");
    }
}

// print all elements in the list
void print(struct knot *l) {
    struct knot *aux = l;
    printf("\nList: ");
    while (!is_empty(aux)) {
        printf("%d ", aux->data); // print data of each node
        aux = aux->next;
    }
    printf("\n");
}

// display menu and handle user options
void display_menu(struct knot **l) {
    int opt;
    do {
        printf("\n1 - Insert start");
        printf("\n2 - Insert end");
        printf("\n3 - Remove");
        printf("\n4 - Clean");
        printf("\n5 - Print");
        printf("\n6 - Search");
        printf("\n7 - Exit");
        printf("\nOption: ");
        scanf("%d", &opt); // read user option

        switch (opt) {
            case 1:
                insert_start(l); // insert a new element at the beginning of the list
                break;
            case 2:
                insert_end(l); // insert a new element at the end of the list
                break;
            case 3:
                delete(l); // delete an element
                break;
            case 4: 
                clean(l); // clean the list
                break;
            case 5:
                print(*l); // print the list
                break;
            case 6:
                search(*l); // search for an element
                break;
            case 7:
                free(*l); // free memory of the list
                break; // exit the program
            default:
                printf("Invalid option\n"); // handle invalid options
        }
    } while (opt != 7); // continue until the user chooses to exit
}