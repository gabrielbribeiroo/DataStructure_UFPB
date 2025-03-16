/*
Implements a postfix calculator using a stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // To check if a character is a digit

#define MAX 100

struct stack {
    int data[MAX]; // Load the stack with integers
    int ctr;
};

// Functions to manipulate the stack
void create(struct stack *l);
int is_empty(struct stack *l);
int is_full(struct stack *l);
void push(struct stack *l, int data);
int pop(struct stack *l);

void create(struct stack *l) {
    l->ctr = 0; // Initialize the counter to 0 to indicate an empty stack
}

int is_empty(struct stack *l) {
    return l->ctr == 0;
}

int is_full(struct stack *l) {
    return l->ctr == MAX;
}

void push(struct stack *l, int data) {
    if (is_full(l)) {
        printf("The stack is full.\n");
        return;
    }
    l->data[l->ctr++] = data; // Insert the data and increment ctr
}

int pop(struct stack *l) {
    if (is_empty(l)) {
        printf("The stack is empty.\n");
        exit(1); // End the program, as there is nothing to pop
    }
    return l->data[--l->ctr]; // Decrement ctr and return the value
}

// Main function to evaluate the postfix expression
int main() {
    struct stack l;
    create(&l); // Initialize the stack

    char expression[MAX];
    printf("Enter the postfix expression: ");
    fgets(expression, MAX, stdin);

    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) { // If the character is a digit, push it to the stack
            push(&l, expression[i] - '0'); // Convert the character to an integer
        } 
        else if (expression[i] == '+' || expression[i] == '-' || 
                 expression[i] == '*' || expression[i] == '/') {
            int a = pop(&l);
            int b = pop(&l);
            int result;

            switch (expression[i]) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': result = b / a; break;
            }

            push(&l, result); // Push the result back to the stack
        }
    }

    // The last element in the stack is the result
    printf("Result: %d\n", pop(&l));

    return 0;
}