/*
Implements a postfix calculator using a stack.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

struct stack {
    double data[MAX]; // Stack for double values
    int ctr;
};

// Stack functions
void create(struct stack *l);
int is_empty(struct stack *l);
int is_full(struct stack *l);
void push(struct stack *l, double data);
double pop(struct stack *l);
int is_double(const char *str);

void create(struct stack *l) {
    l->ctr = 0;
}

int is_empty(struct stack *l) {
    return l->ctr == 0;
}

int is_full(struct stack *l) {
    return l->ctr == MAX;
}

void push(struct stack *l, double data) {
    if (is_full(l)) {
        printf("The stack is full.\n");
        return;
    }
    l->data[l->ctr++] = data;
}

double pop(struct stack *l) { 
    if (is_empty(l)) {
        printf("The stack is empty.\n");
        exit(1);
    }
    return l->data[--l->ctr];
}

int is_double(const char *str) {
    char *endptr;
    strtod(str, &endptr); // Try to convert the string to double
    return (*str != '\0' && *endptr == '\0'); // True if the whole string is a number
}

// Main function to evaluate the postfix expression
int main() {
    struct stack l;
    create(&l);

    char expression[MAX];
    printf("Enter the postfix expression (space-separated numbers and operators): ");
    fgets(expression, MAX, stdin);

    char *token = strtok(expression, " \n"); // Tokenize the input based on spaces
    while (token != NULL) {
        if (is_double(token)) { // If it's a number, push it to the stack
            push(&l, strtod(token, NULL)); // Convert to double and push
        } 
        else if (strlen(token) == 1 && strchr("+-*/%^#", token[0])) { // If it's an operator
            if (is_empty(&l)) {
                printf("Error: Not enough operands\n");
                exit(1);
            }
            double a = pop(&l);
            double b = pop(&l);
            double result = 0;

            switch (token[0]) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': 
                    if (a == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    result = b / a; 
                    break;
                case '%': 
                    if ((int)a == 0) {
                        printf("Error: Modulo by zero\n");
                        exit(1);
                    }
                    result = (int)b % (int)a; 
                    break;
                case '^': result = pow(b, a); break;
                case '#': result = b * b; break; // Square the value
                default:
                    printf("Error: Unknown operator %c\n", token[0]);
                    exit(1);
            }
            push(&l, result);
        } 
        else {
            printf("Error: Invalid token '%s'\n", token);
            exit(1);
        }

        token = strtok(NULL, " \n"); // Get the next token
    }

    if (l.ctr == 1) { // The final result should be the only element in the stack
        printf("Result: %lf\n", pop(&l));
    } 
    else {
        printf("Error: Invalid expression\n");
    }

    return 0;
}