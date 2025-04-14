/*

*/

#include <stdio.h>
#include <stdlib.h>

struct type1 {
    int data;
    struct type2 *t2;
    struct type1 *t1;
};
typedef struct type1 Type1;

struct type2 {
    int data;
    struct type2 *next;
};
typedef struct type2 Type2;

int main() {
    return 0;
}