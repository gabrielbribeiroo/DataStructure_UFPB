/*
Bubble sort algorithm with a list
*/

#include <stdio.h>

#define N 5

struct list {
    int value[N];
    int n;
} l;

void create(struct list *l) {
    l->n = -1;
}

void insert(struct list *l, int value) {
    if (l->n == N - 1) {
        printf("List is full\n");
        return;
    }
    l->n++;
    l->value[l->n] = value;
}

void print(struct list l) {
    if (l.n == -1) { 
        printf("List is empty\n");
        return;
    }
    for (int i = 0; i <= l.n; i++) {
        printf("%d ", l.value[i]);
    }
    printf("\n");
}

int main() {
    struct list l;
    int i, j, aux;
    
    create(&l);

    insert(&l, 8);
    insert(&l, 4);
    insert(&l, 11);
    insert(&l, 7);
    insert(&l, 0);

    for (i = 0; i <= l.n - 1; i++) {
        for (j = i + 1; j <= l.n; j++) {
            if (l.value[j] < l.value[i]) {
                aux = l.value[i];
                l.value[i] = l.value[j];
                l.value[j] = aux;
            }
        }
    }

    print(l);

    return 0;
}