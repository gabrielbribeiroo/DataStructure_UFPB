/**
 * @file circular_list.c
 * @brief Implementation of circular linked list.
 * 
 * @author Gabriel Ribeiro
 * @version 3.0
 * @date 2025-03-01 
 */

 #include "create.h"
 #include "insert.h"
 #include "delete.h"
 #include "route.h"
 #include "menu.h"
 
 int main() {
     int option;
 
     while (1) {  // Loop do menu principal
         menu();
         printf("\nOption: ");
         
         if (scanf("%d", &option) != 1) {
             printf("Invalid input. Try again.\n");
             while (getchar() != '\n'); // Limpa buffer
             continue;
         }
 
         if (option == 4) {
             printf("Exiting program...\n");
             break;  // Sai do loop principal e encerra o programa
         }
 
         int opt;  // Armazena a opção dos submenus
 
         switch (option) {
             case 1: { 
                 struct vector *l = malloc(sizeof(struct vector));
                 create_vector_list(l);
 
                 do {
                     display_menu_vector_list();
                     printf("\nOption: ");
                     if (scanf("%d", &opt) != 1) {
                         printf("Invalid input. Try again.\n");
                         while (getchar() != '\n');
                         continue;
                     }
 
                     switch (opt) {
                         case 1: insert_end_vector(l); break;
                         case 2: insert_begin_vector(l); break;
                         case 3: delete_end_vector(l); break;
                         case 4: delete_begin_vector(l); break;
                         case 5: search_vector_list(l); break;
                         case 6: print_vector_list(l); break;
                         case 7: clean_vector_list(l); break;
                         case 8:
                             printf("Exiting Vector List...\n");
                             clean_vector_list(l);
                             free(l);
                             break;
                         default:
                             printf("Invalid option\n");
                     }
                 } while (opt != 8);
                 break;
             }         
 
             case 2: {
                 struct node *ln = NULL;
                 create_linked_list(&ln);
 
                 do {
                     display_menu_linked_list();
                     printf("\nOption: ");
                     if (scanf("%d", &opt) != 1) {
                         printf("Invalid input. Try again.\n");
                         while (getchar() != '\n');
                         continue;
                     }
 
                     switch (opt) {
                         case 1: insert_begin_linked_list(&ln); break;
                         case 2: insert_middle_linked_list(&ln); break;
                         case 3: insert_end_linked_list(&ln); break;
                         case 4: delete_begin_linked_list(&ln); break;
                         case 5: delete_middle_linked_list(&ln); break;
                         case 6: delete_end_linked_list(&ln); break;
                         case 7: clean_linked_list(&ln); break;
                         case 8: print_linked_list(&ln); break;
                         case 9: search_linked_list(&ln); break;
                         case 10:
                             printf("Exiting Linked List...\n");
                             clean_linked_list(&ln);
                             break;
                         default:
                             printf("Invalid option\n");
                     }
                 } while (opt != 10);
                 break;
             }
 
             case 3: {
                 struct list *ld = NULL;
                 create_double_linked_list(&ld);
                 struct dnode *pd = NULL;
                 create_double_linked_node(&pd);
 
                 do {
                     display_menu_double_linked_list();
                     printf("\nOption: ");
                     if (scanf("%d", &opt) != 1) {
                         printf("Invalid input. Try again.\n");
                         while (getchar() != '\n');
                         continue;
                     }
 
                     switch (opt) {
                         case 1: insert_begin_double_linked_list(&ld); break;
                         case 2: insert_middle_double_linked_list(&ld); break;
                         case 3: insert_end_double_linked_list(&ld); break;
                         case 4: delete_begin_double_linked_list(&ld); break;
                         case 5: delete_middle_double_linked_list(&ld); break;
                         case 6: delete_end_double_linked_list(&ld); break;
                         case 7: clean_double_linked_list(&ld); break;
                         case 8: print1_double_linked_list(&ld); break;
                         case 9: print2_double_linked_list(&ld); break;
                         case 10: search_double_linked_list(&ld); break;
                         case 11:
                             printf("Exiting Double Linked List...\n");
                             clean_double_linked_list(&ld);
                             break;
                         default:
                             printf("Invalid option\n");
                     }
                 } while (opt != 11);
                 break;
             }
 
             default:
                 printf("Invalid option\n");
         }
     }
 
     return 0;
 } 