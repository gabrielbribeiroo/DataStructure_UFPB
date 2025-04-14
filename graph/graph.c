/*

*/

#include <stdio.h>
#include <stdlib.h>

struct type1 {
    int data;
    struct type2 *t2;
    struct type1 *t1;
};
typedef struct type1 Type1;

struct type2 {
    int data;
    struct type2 *next;
};
typedef struct type2 Type2;

Type1 *create_type1(int value) {
    Type1 *new_type1 = (Type1 *)malloc(sizeof(Type1));
    if (new_type1 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_type1->data = value;
    new_type1->t2 = NULL;
    new_type1->t1 = NULL;
    return new_type1;
}

Type2 *create_type2(int value) {
    Type2 *new_type2 = (Type2 *)malloc(sizeof(Type2));
    if (new_type2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_type2->data = value;
    new_type2->next = NULL;
    return new_type2;
}

void free_type1(Type1 *t1) {
    if (t1 != NULL) {
        free_type2(t1->t2);
        free(t1);
    }
}

void free_type2(Type2 *t2) {
    if (t2 != NULL) {
        free_type2(t2->next);
        free(t2);
    }
}

void free_graph(Type1 *graph) {
    if (graph != NULL) {
        free_type1(graph);
    }
}

void print_graph(Type1 *graph) {
    Type1 *current_t1 = graph;
    while (current_t1 != NULL) {
        printf("Type1 data: %d\n", current_t1->data);
        Type2 *current_t2 = current_t1->t2;
        while (current_t2 != NULL) {
            printf("  Type2 data: %d\n", current_t2->data);
            current_t2 = current_t2->next;
        }
        current_t1 = current_t1->t1;
    }
}

void add_type2_to_type1(Type1 *t1, int value) {
    Type2 *new_t2 = create_type2(value);
    new_t2->next = t1->t2;
    t1->t2 = new_t2;
}

void add_type1_to_graph(Type1 **graph, int value) {
    Type1 *new_t1 = create_type1(value);
    new_t1->t1 = *graph;
    *graph = new_t1;
}

void add_type2_to_graph(Type1 *graph, int t1_value, int t2_value) {
    Type1 *current_t1 = graph;
    while (current_t1 != NULL && current_t1->data != t1_value) {
        current_t1 = current_t1->t1;
    }
    if (current_t1 != NULL) {
        add_type2_to_type1(current_t1, t2_value);
    } else {
        fprintf(stderr, "Type1 with value %d not found\n", t1_value);
    }
}

int main() {
    return 0;
}