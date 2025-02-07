/*
Implement a function that takes a string as a parameter and changes the occurrences of longer characters to shorter ones.
*/

// libraries
#include <stdio.h>
#include <string.h>

#define MAX 101

void lower(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
} 

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    lower(str);
    printf("The string in lowercase is: %s", str);
    return 0;
}