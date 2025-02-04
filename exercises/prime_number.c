/*
Implement a function to test whether an integer is prime or not. 
This function must obey the following prototype and have a return value of 1 if n is prime and O otherwise.
*/

#include <stdio.h>

int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    
    // Get the number from the user
    printf("Enter a number: ");
    scanf("%d", &n);

    // Check if the number is prime
    if (is_prime(n)) {
        printf("%d is a prime number.\n", n);
    } 
    else {
        printf("%d is not a prime number.\n", n);
    }
    
    return 0;
}