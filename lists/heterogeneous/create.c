/**
 * @file create.c
 * @brief Implementation of the function to create a heterogeneous linked list.
 * 
 * @author Gabriel Ribeiro
 * @version 2.0
 * @date 2025-03-23
 */

#include "create.h" // include the header file with the function prototypes

// constants
#define R 0
#define T 1
#define C 2

// structures
struct node {
    int id;           // Identifier for the node
    void *info;       // Pointer to generic data 
    struct node *next; // Pointer to the next node in the list
};

// Structure representing a rectangle
struct rectangle {
    float b; // Base of the rectangle
    float h; // Height of the rectangle
};

// Structure representing a triangle
struct triangle {
    float b; // Base of the triangle
    float h; // Height of the triangle
};

// Structure representing a circle
struct circle {
    float r; // Radius of the circle
};

// create functions
void create_a(struct node **n) {
    struct rectangle *r = (struct rectangle*) malloc(sizeof(struct rectangle));
    if (!r) {
        printf("Memory allocation failed for rectangle.\n");
        return;
    }
    r->b = 0;
    r->h = 0;

    struct node *new = (struct node*) malloc(sizeof(struct node));
    if (!new) {
        printf("Memory allocation failed for node.\n");
        free(r);
        return;
    }

    new->id = R;
    new->info = r;
    new->next = *n; // Insert at the beginning
    *n = new;
}

void create_b(struct node **n) {
    struct triangle *t = (struct triangle*) malloc(sizeof(struct triangle));
    if (!t) {
        printf("Memory allocation failed for triangle.\n");
        return;
    }
    t->b = 0;
    t->h = 0;

    struct node *new = (struct node*) malloc(sizeof(struct node));
    if (!new) {
        printf("Memory allocation failed for node.\n");
        free(t);
        return;
    }

    new->id = T;
    new->info = t;
    new->next = *n; // Insert at the beginning
    *n = new;
}

void create_c(struct node **n) {
    struct circle *c = (struct circle*) malloc(sizeof(struct circle));
    if (!c) {
        printf("Memory allocation failed for circle.\n");
        return;
    }
    c->r = 0;

    struct node *new = (struct node*) malloc(sizeof(struct node));
    if (!new) {
        printf("Memory allocation failed for node.\n");
        free(c);
        return;
    }

    new->id = C;
    new->info = c;
    new->next = *n; // Insert at the beginning
    *n = new;
}

// Checks if the list is empty
int is_empty(struct node *l) {
    return l == NULL;
}