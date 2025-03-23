/**
 * @file insert.c
 * @brief Implementation of the functions to insert elements in a linked list.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2025-03-23
 */

#include "insert.h" // include the header file with the function prototypes

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