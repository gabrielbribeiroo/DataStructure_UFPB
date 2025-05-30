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

// Forward declaration of free_type2
void free_type2(Type2 *t2);

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
    } 
    else {
        fprintf(stderr, "Type1 with value %d not found\n", t1_value);
    }
}

void remove_type2_from_type1(Type1 *t1, int value) {
    Type2 *current_t2 = t1->t2;
    Type2 *prev_t2 = NULL;
    while (current_t2 != NULL && current_t2->data != value) {
        prev_t2 = current_t2;
        current_t2 = current_t2->next;
    }
    if (current_t2 != NULL) {
        if (prev_t2 != NULL) {
            prev_t2->next = current_t2->next;
        } else {
            t1->t2 = current_t2->next;
        }
        free(current_t2);
    } 
    else {
        fprintf(stderr, "Type2 with value %d not found\n", value);
    }
}

void remove_type1_from_graph(Type1 **graph, int value) {
    Type1 *current_t1 = *graph;
    Type1 *prev_t1 = NULL;
    while (current_t1 != NULL && current_t1->data != value) {
        prev_t1 = current_t1;
        current_t1 = current_t1->t1;
    }
    if (current_t1 != NULL) {
        if (prev_t1 != NULL) {
            prev_t1->t1 = current_t1->t1;
        } 
        else {
            *graph = current_t1->t1;
        }
        free_type1(current_t1);
    } 
    else {
        fprintf(stderr, "Type1 with value %d not found\n", value);
    }
}

void remove_type2_from_graph(Type1 *graph, int t1_value, int t2_value) {
    Type1 *current_t1 = graph;
    while (current_t1 != NULL && current_t1->data != t1_value) {
        current_t1 = current_t1->t1;
    }
    if (current_t1 != NULL) {
        remove_type2_from_type1(current_t1, t2_value);
    } 
    else {
        fprintf(stderr, "Type1 with value %d not found\n", t1_value);
    }
}

void remove_graph(Type1 **graph) {
    free_graph(*graph);
    *graph = NULL;
}

void print_type1(Type1 *t1) {
    if (t1 != NULL) {
        printf("Type1 data: %d\n", t1->data);
        Type2 *current_t2 = t1->t2;
        while (current_t2 != NULL) {
            printf("  Type2 data: %d\n", current_t2->data);
            current_t2 = current_t2->next;
        }
    } 
    else {
        printf("Type1 is NULL\n");
    }
}

void print_type2(Type2 *t2) {
    if (t2 != NULL) {
        printf("Type2 data: %d\n", t2->data);
        print_type2(t2->next);
    } 
    else {
        printf("Type2 is NULL\n");
    }
}

void print_graph_structure(Type1 *graph) {
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

void print_graph(Type1 *graph) {
    if (graph != NULL) {
        print_graph_structure(graph);
    } 
    else {
        printf("Graph is NULL\n");
    }
}

int main() {
    Type1 *graph = NULL;
    
    add_type1_to_graph(&graph, 1);
    add_type1_to_graph(&graph, 2);
    add_type1_to_graph(&graph, 3);


    add_type2_to_graph(graph, 1, 10);
    add_type2_to_graph(graph, 1, 20);
    add_type2_to_graph(graph, 2, 30);
    add_type2_to_graph(graph, 2, 40);
    add_type2_to_graph(graph, 3, 50);
    add_type2_to_graph(graph, 3, 60);

    printf("Graph structure:\n");
    print_graph(graph);

    printf("\nRemoving Type2 with value 20 from Type1 with value 1:\n");
    remove_type2_from_graph(graph, 1, 20);
    print_graph(graph);

    printf("\nRemoving Type1 with value 2:\n");
    remove_type1_from_graph(&graph, 2);
    print_graph(graph);

    printf("\nRemoving Type1 with value 3:\n");
    remove_type1_from_graph(&graph, 3);
    print_graph(graph);

    printf("\nRemoving Type1 with value 1:\n");
    remove_type1_from_graph(&graph, 1);
    print_graph(graph);

    printf("\nRemoving graph:\n");
    remove_graph(&graph);
    print_graph(graph);

    printf("Graph removed successfully.\n");

    // Free the graph memory
    free_graph(graph);

    return 0;
}