/*
List with vector
*/

#include <stdio.h>

// define the size of the list
#define N 9

// types
struct list {
    int i; // occupancy control
    int data[N]; // data
};

// functions prototypes
void create_list(struct list *);
int consult_list(int, struct list *);
char full(struct list);
char empty(struct list);
char insert_list(struct list*);
void clean_list(struct list*);
int menu();
void print_list(struct list);
void remove_list(struct list*);

void main() {
    struct list L1; // list

    create_list(&L1); 

    int opt;
    do {
        opt = menu();

        switch (opt) {
            case 1:
                insert_list(&L1);
                break;
            case 2:
                remove_list(&L1);
                break;
            case 3: {
                int p;
                printf("Position: ");
                scanf("%d", &p);
                printf("Data: %d\n", consult_list(p, &L1));
                break;
            }
            case 4:
                print_list(L1);
                break;
            case 5:
                clean_list(&L1);
                break;
            case 6:
                break;
            default:
                printf("Invalid option\n");
        }
    } while (opt != 6);
}

void create_list(struct list *l) {
    l->i = -1; // list starts empty
}

int consult_list(int p, struct list *l) {
    if (p >= 0 && p <= l->i) {
        return l->data[p];
    }
    else {
        return -1; // invalid position
    }
}

char full(struct list l) {
    return (l.i == N - 1); // true or false
}

char empty(struct list l) {
    return (l.i == -1); // true or false
}

char insert_list(struct list *l) {
	int d;
	
    // checks if the list is full
	if (full(*l)) {
		printf("List is full\n");
		return 0; 
	}

    printf("Data: ");
	scanf("%d", &d);

    l->i++; // increment occupancy control
    l->data[l->i] = d; // insert data

    return 1;
}

void clean_list(struct list *l) {
    l->i = -1; // reset occupancy control
    printf("List cleared\n");
}

int menu() {
    int opt;

    printf("\n1 - Insert");
    printf("\n2 - Remove");
    printf("\n3 - Consult");
    printf("\n4 - Print");
    printf("\n5 - Clean");
    printf("\n6 - Exit");
    printf("\nOption: ");
    scanf("%d", &opt);

    return opt;
}

void print_list(struct list l) {
    printf("\nList: ");
    for (int j = 0; j < l.i; j++) {
		printf("%d ", l.data[j]);
	} 
	printf("\n");
}

void remove_list(struct list *l) {
    if (empty(*l)) {
        printf("List is empty\n");
        return;
    }
    printf("Removed: %d\n", l->data[l->i]); // Show removed element
    l->i--; // decrement occupancy control
}