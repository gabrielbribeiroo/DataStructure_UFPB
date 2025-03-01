/**
 * @file circular_list.c
 * @brief Implementation of circular linked list.
 * 
 * @author Gabriel Ribeiro
 * @version 2.1
 * @date 2025-03-01 
 */

// include libraries
#include "create.h"
#include "insert.h"
#include "delete.h"
#include "route.h"
#include "menu.h"

// main function
int main() {
    menu();
    printf("\nOption: ");
    int option, opt;
    scanf("%d", &option);

    do {
        switch (option) {
            case 1:
                display_menu_vector_list();
                struct vector *l;
                create_vector_list(l);
                printf("\nOption: ");
                scanf("%d", &opt);
                switch (opt) {
                    case 1:
                        insert_end_vector(l);
                        break;
                    case 2:
                        insert_begin_vector(l);
                        break;
                    case 3:
                        delete_end_vector(l);
                        break;
                    case 4:
                        delete_begin_vector(l);
                        break;
                    case 5:
                        search_vector_list(l);
                        break;
                    case 6:
                        print_vector_list(l);
                        break;
                    case 7:
                        clean_vector_list(l);
                        break;
                    case 8:
                        printf("Exiting...");
                        break;
                    default:
                        printf("Invalid option");
                        break;
                }
                break;

            case 2:
                display_menu_linked_list();
                struct node *l;
                create_linked_list(l);
                printf("\nOption: ");
                scanf("%d", &opt);
                switch (opt) {
                    case 1:
                        insert_begin_linked_list(l);
                        break;
                    case 2:
                        insert_middle_linked_list(l);
                        break;
                    case 3:
                        insert_end_linked_list(l);
                        break;
                    case 4:
                        delete_begin_linked_list(l);
                        break;
                    case 5:
                        delete_middle_linked_list(l);
                        break;
                    case 6:
                        delete_end_linked_list(l);
                        break;
                    case 7:
                        clean_linked_list(l);
                        break;
                    case 8:
                        print_linked_list(l);
                        break;
                    case 9:
                        search_linked_list(l);
                        break;
                    case 10:
                        printf("Exiting...");
                        break;
                    default:
                        printf("Invalid option");
                        break;
                }
                break;
            case 3:
                display_menu_double_linked_list();
                printf("\nOption: ");
                scanf("%d", &opt);
                struct list *l;
                struct dnode *p;
                create_double_linked_list(l);
                create_double_linked_node(p);
                switch (opt) {
                    case 1:
                        insert_begin_double_linked_list(l);
                        break;
                    case 2:
                        insert_middle_double_linked_list(l);
                        break;
                    case 3:
                        insert_end_double_linked_list(l);
                        break;
                    case 4:
                        delete_begin_double_linked_list(l);
                        break;
                    case 5:
                        delete_middle_double_linked_list(l);
                        break;
                    case 6:
                        delete_end_double_linked_list(l);
                        break;
                    case 7:
                        clean_double_linked_list(l);
                        break;
                    case 8:
                        print1_double_linked_list(l);
                        break;
                    case 9:
                        print2_double_linked_list(l);
                        break;
                    case 10:
                        search_double_linked_list(l);
                        break;
                    case 11:
                        printf("Exiting...");
                        break;
                    default:
                        printf("Invalid option");
                        break;
                }
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid option");
                break;
        }
    } while (option != 4);

    return 0;
}