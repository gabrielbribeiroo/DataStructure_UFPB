#include <stdio.h>
#include <stdlib.h>

// Definition of the binary tree node structure
struct node {
    int data;            // Value stored in the node
    struct node *left;   // Pointer to the left child
    struct node *right;  // Pointer to the right child
};

// Define an alias "Node" for "struct node" to simplify usage
typedef struct node Node;

// Function prototypes
Node* create(int);
Node* insert(Node*, int);
void show(Node*);
Node* clean(Node*);
int node_count(Node*);
int height(Node*);


int main() {
    Node *tree = NULL; // Initialize an empty tree

    // Insert elements into the tree
    tree = insert(tree, 8);
    tree = insert(tree, 3);
    tree = insert(tree, 2);
    tree = insert(tree, 5);
    tree = insert(tree, 10);

    printf("Tree in sorted order: ");
    show(tree);
    printf("\n");

    // Clean up the tree
    tree = clean(tree);
    return 0;
}

// Function to create a new node
Node *create(int value) {
    Node *new = (Node*)malloc(sizeof(Node));
    if (!new) {
        return NULL; // Memory allocation failed
    }
    new->data = value;
    new->left = new->right = NULL;
    return new;
}

// Function to insert a value into the BST
Node *insert(Node *root, int value) {
    if (!root) {
        return create(value); // Create a new node if tree is empty
    }

    if (value < root->data) {
        root->left = insert(root->left, value); // Insert into the left subtree
    }
    else if (value > root->data) {
        root->right = insert(root->right, value); // Insert into the right subtree
    }

    return root; // Return the unchanged node pointer
}

// Function to show the tree in sorted order (in-order traversal)
void show(Node *root) {
    if (root) {
        show(root->left);
        printf("%d ", root->data);
        show(root->right);
    }
    else return; // Base case: if the node is NULL, do nothing
}

// Function to free all nodes in the tree
Node *clean(Node *root) {
    if (root) {
        root->left = clean(root->left);
        root->right = clean(root->right);
        free(root);
    }
    return NULL;
}

// Function to count the number of nodes in the tree
int node_count(Node *root) {
    int a, b;
    if (!root) {
        return 0; // Base case: if the node is NULL, return 0
    }
    a = node_count(root->left); // Count nodes in the left subtree
    b = node_count(root->right); // Count nodes in the right subtree
    return (a + b + 1); // Return total count (left + right + 1 for the current node)
}

// Function to calculate the height of the tree
int height(Node *root) {
    int a, b;
    if (!root) {
        return 0; // Base case: if the node is NULL, return 0
    }
    a = height(root->left); // Height of the left subtree
    b = height(root->right); // Height of the right subtree
    return (a > b ? a : b) + 1; // Return the maximum height + 1 for the current node
}