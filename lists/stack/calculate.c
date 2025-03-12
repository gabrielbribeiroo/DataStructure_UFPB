/*
Implements a postfix calculator using a stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct list {
    char data[MAX];
    int ctr;
};

// function prototypes
void create(struct list *);
int is_empty(struct list *);
int is_full(struct list *);
void push(struct list *, char);
void pop(struct list *);

// creates a new stack
void create(struct list *l) {
    l = (struct list *)malloc(sizeof(struct list));
    l->ctr = 0;
}

// checks if the stack is empty
int is_empty(struct list *l) {
    return l->ctr == 0;
}

// checks if the stack is full
int is_full(struct list *l) {
    return l->ctr == MAX;
}

// pushes a new element to the stack
void push(struct list *l, char data) {
    if (is_full(l)) {
        printf("The stack is full.\n");
        return;
    }
    l->data[l->ctr] = data;
    l->ctr++;
}

// pops an element from the stack
void pop(struct list *l) {
    if (is_empty(l)) {
        printf("The stack is empty.\n");
        return;
    }
    l->ctr--;
}

// calculates the result of the postfix expression
int main() {
    struct list *l;
    create(l);
    char expression[MAX];
    printf("Enter the postfix expression: ");
    fgets(expression, MAX, stdin);
    for (int i=0; i<strlen(expression); i++) {
        if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/') {
            push(l, expression[i]);
        } 
        else {
            int a = l->data[l->ctr-1] - '0';
            pop(l);
            int b = l->data[l->ctr-1] - '0';
            pop(l);
            int result;
            switch (expression[i]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
            }

            push(l, result + '0');
        }
    }

    pop(l);
    printf("Result: %d\n", l->data[l->ctr-1] - '0');
    free(l);

    return 0;
}