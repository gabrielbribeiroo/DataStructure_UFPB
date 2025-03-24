/**
 * @file manipulate.c
 * @brief Implementation of the functions to manipulate elements in a linked list.
 * 
 * @author Gabriel Ribeiro
 * @version 1.1
 * @date 2025-03-23
 */

#include "manipulate.h" // include the header file with the function prototypes

#define PI 3.14159

// insert a new element at the beginning of the list
void insert(struct node **n) {   
    switch(menu()) {
        case 0: 
            create_a(n);
            break;
        case 1:
            create_b(n);
            break;
        case 2:
            create_c(n);
            break;
        default:
            printf("Invalid option\n");
            break;      
    }
}