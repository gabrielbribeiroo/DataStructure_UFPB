/*
Implement a function that takes a string as a parameter and shifts its characters one position to the right. 
For example, the string “home" would be changed to “ehom”.
*/

#include <stdio.h>
#include <string.h>

#define MAX 101

void spin_string(char *str) {
    int len = strlen(str);

    // remove the newline character from the string
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--; // update the length of the string
    }

    if (len <= 1) return; // if the string has 0 or 1 character, there is nothing to do

    char last = str[len - 1]; // save the last character

    // shift the characters one position to the right
    for (int i = len - 1; i > 0; i--) {
        str[i] = str[i - 1];
    }

    str[0] = last; // move the last character to the first position
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading the string\n");
        return 1;
    }

    spin_string(str);

    printf("The new string is: %s", str);

    return 0;
}