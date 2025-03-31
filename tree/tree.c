#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *create(int, Node*, Node*);

int main() {
    Node *tree = 0;
    tree = create(4, 0, 0);
    tree->left = create(2, 0, 0);
    tree->right = create(6, 0, 0);
    tree->left->left = create(1, 0, 0);
    tree->left->right = create(3, 0, 0);
    tree->right->left = create(5, 0, 0);
    tree->right->right = create(7, 0, 0);
    return 0;
}

Node *create(int value, Node *sleft, Node *sright) {
    Node *new;
    new = (Node *)malloc(sizeof(Node));
    if (!new) {
        return 0;
    }
    new->data = value;
    new->left = sleft;
    new->right = sright;
    return new;
}