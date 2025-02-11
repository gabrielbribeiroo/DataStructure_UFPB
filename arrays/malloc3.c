/*
Allocate memory for a 2D array using malloc
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {
    int **a;

    a = (int **) malloc(N * sizeof(int *)); // allocate memory for N pointers to integers
    for (int i = 0; i < N; i++) {
        a[i] = (int *) malloc(N * sizeof(int)); // allocate memory for N integers
    }

    // fill the array with some values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = (i+1) * (j+1);
        }
    }

    // print the array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}