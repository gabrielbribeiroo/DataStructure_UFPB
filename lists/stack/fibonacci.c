/*
Returns the nth fibonacci number, using recursion.
*/

#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    // Get the number of fibonacci numbers to generate
    printf("Enter the number of fibonacci numbers to generate: ");
    scanf("%d", &n);

    // Print the fibonacci numbers
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}