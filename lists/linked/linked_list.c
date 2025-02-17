/*
Create, insert, delete, clean, and print a linked list.
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
void insert(struct knot**);
void delete(struct knot**);
void clean(struct knot**);
void print(struct knot*);
int menu();

int main() {
    struct knot *l; // pointer to the head of the list
    int num, opt;

    create(&l); // initialize the list

    do {
        opt = menu(); // display menu and get user option

        switch (opt) {
            case 1:
                insert(&l); // dnsert a new element
                break;
            case 2:
                delete(&l); // delete an element
                break;
            case 3: 
                clean(&l); // clean the list
                break;
            case 4:
                print(l); // print the list
                break;
            case 5:
                break; // exit the program
            default:
                printf("Invalid option\n"); // handle invalid options
        }
    } while (opt != 5); // continue until the user chooses to exit

    return 0;
}

// initialize the list to be empty
void create(struct knot **l) {
    *l = NULL;
}

// insert a new element at the beginning of the list
void insert(struct knot **l) {
    struct knot *new;
    new = (struct knot *)malloc(sizeof(struct knot)); // allocate memory for the new node
    // check if memory was allocated
    if (new == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    int n;
    scanf("%d", &n); // read the data to be inserted
    
    // insert data into the new node
    new->data = n;
    new->next = *l;

    // update the head of the list
    *l = new;    
}

// delete an element from the list
void delete(struct knot **l) {
    struct knot *aux, *prev;
    aux = *l;
    prev = NULL;

    int n;
    scanf("%d", &n); // read the data to be deleted

    // search for the element
    while (aux != NULL && aux->data != n) {
        prev = aux;
        aux = aux->next;
    }

    // check if the element was found
    if (aux == NULL) {
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
    while (*l) {
        aux = *l;
        *l = (*l)->next;
        free(aux); // free memory of each node
    }
}

// print all elements in the list
void print(struct knot *l) {
    struct knot *aux = l;
    printf("\nList: ");
    while (aux != NULL) {
        printf("%d ", aux->data); // print data of each node
        aux = aux->next;
    }
    printf("\n");
}

// display menu and get user option
int menu() {
    int opt;

    printf("\n1 - Insert");
    printf("\n2 - Remove");
    printf("\n3 - Clean");
    printf("\n4 - Print");
    printf("\n5 - Exit");
    printf("\nOption: ");
    scanf("%d", &opt); // read user option

    return opt;
}