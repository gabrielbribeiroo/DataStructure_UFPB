#ifndef CREATE_H // checks if the header has already been included
#define CREATE_H // if not, define the header

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

// structures
struct node;
struct a;
struct b;
struct c;

void create_a(struct a**);
void create_b(struct b**);
void create_c(struct c**);

int is_empty(struct node*);

#endif // end of the header guard