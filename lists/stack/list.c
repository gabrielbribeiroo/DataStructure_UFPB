/**
 * @file list.c
 * @brief Implementation of stack.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2025-03-10 
 */

#include "create.h" 
#include "insert.h"
#include "delete.h"
#include "route.h"
#include "menu.h"

int main() {
    int opt1, opt2;
    menu();
    scanf("%d", &opt1);

    switch (opt1) {
        case 1: {
            struct vector *l; 
            create_vector_list(l);
            display_menu_vector_list();
            scanf("%d", &opt2);
            switch (opt2) {
                case 1:
                    push_vector(l);
                    break;
                case 2:
                    pop_vector(l);
                    break;
                case 3:
                    search_vector_list(l);
                    break;
                case 4:
                    print_vector_list(l);
                    break;
                case 5:
                    clean_vector_list(l);
                    break;
                case 6:
                    exit(0);
                    break;
                default:
                    printf("Invalid option\n");
                    break;
            }
            break;
        }
        case 2: {
            struct node **l;
            create_linked_list(l);
            display_menu_linked_list();
            scanf("%d", &opt2);
            switch (opt2) {
                case 1:
                    push_linked_list(l);
                    break;
                case 2:
                    pop_linked_list(l);
                    break;
                case 3:
                    search_linked_list(l);
                    break;
                case 4:
                    print_linked_list(l);
                    break;
                case 5:
                    clean_linked_list(l);
                    break;
                case 6:
                    exit(0);
                    break;
                default:
                    printf("Invalid option\n");
                    break;
            }
            break;
        }
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}