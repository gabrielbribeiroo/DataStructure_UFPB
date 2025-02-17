/*
Create, insert, delete, clean, and print a linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct knot {
    int data;
    struct knot *next;
} *l;

// functions prototypes
void create(struct knot**);
void insert(struct knot**);
void delete(struct knot**);
void clean(struct knot**);
void print(struct knot*);
int menu();

int main() {
    struct knot *l;
    int num, opt;

    create(&l);

    do {
        opt = menu();

        switch (opt) {
            case 1:
                insert(&l);
                break;
            case 2:
                delete(&l);
                break;
            case 3: 
                clean(&l);    
                break;
            case 4:
                print(l);
                break;
            case 5:
                break;
            default:
                printf("Invalid option\n");
        }
    } while (opt != 5);

    return 0;
}

void create(struct knot **l) {
    *l = NULL;
}

void insert(struct knot **l) {
    struct knot *new;
    new = (struct knot *)malloc(sizeof(struct knot)); // allocate memory
    // check if memory was allocated
    if (new == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    int n;
    scanf("%d", &n);
    
    // insert data
    new->data = n;
    new->next = *l;

    // update list
    *l = new;    
}

void delete(struct knot **l) {
    struct knot *aux, *prev;
    aux = *l;
    prev = NULL;

    int n;
    scanf("%d", &n);

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

    // check if the element is the first
    if (prev == NULL) {
        *l = aux->next;
    } 
    else {
        prev->next = aux->next;
    }

    // free memory
    free(aux);
}

void clean(struct knot **l) {
    struct knot *aux;
    while (*l) {
        aux = *l;
        *l = (*l)->next;
        free(aux);
    }
}

void print(struct knot *l) {
    struct knot *aux = l;
    printf("\nList: ");
    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

int menu() {
    int opt;

    printf("\n1 - Insert");
    printf("\n2 - Remove");
    printf("\n3 - Clean");
    printf("\n4 - Print");
    printf("\n5 - Exit");
    printf("\nOption: ");
    scanf("%d", &opt);

    return opt;
}