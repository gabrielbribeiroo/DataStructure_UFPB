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

// Function prototype to create a new node
Node *create(int, Node*, Node*);

// Function prototype to print the entire tree (preorder traversal)
void print(Node*);

// Funtction prototype to print the binary tree
void print_ordered(Node*);

// Function to free all nodes of a binary tree
Node *clean(Node*);

int main() {
    // Pointer to the root of the tree, initially NULL
    Node *tree = 0;

    // Manually constructing the binary tree:
    // Creating the root node with value 4
    tree = create(4, 0, 0);
    
    // Creating the children of the root node
    tree->left = create(2, 0, 0);  // Left child (2)
    tree->right = create(6, 0, 0); // Right child (6)

    // Creating the children of node 2
    tree->left->left = create(1, 0, 0);  // Left child of 2 (1)
    tree->left->right = create(3, 0, 0); // Right child of 2 (3)

    // Creating the children of node 6
    tree->right->left = create(5, 0, 0);  // Left child of 6 (5)
    tree->right->right = create(7, 0, 0); // Right child of 6 (7)

    // Print the tree using a preorder traversal
    print(tree);

    clean(tree);

    return 0; // End of the program
}

// Function to create a new tree node
Node *create(int value, Node *sleft, Node *sright) {
    // Dynamically allocate memory for a new node
    Node *new;
    new = (Node *)malloc(sizeof(Node));

    // Check if memory allocation was successful
    if (!new) {
        return 0; // Return NULL in case of failure
    }

    // Assign values to the new node
    new->data = value;
    new->left = sleft;
    new->right = sright;

    return new; // Return the pointer to the newly created node
}



// Function to print the tree using preorder traversal
void print(Node *root) {
    if (root) { // If the current node is not NULL
        printf("%d ", root->data); // Print the value of the node
        print(root->left);         // Recursively print the left subtree
        print(root->right);        // Recursively print the right subtree
    }
    else {
        return; // Base case: if the node is NULL, return
    }
}

// Function to print the binary tree in an ordered manner (in-order traversal)
void print_ordered(Node *root) {
    // Base case: if the current node is NULL, return (end recursion)
    if (!root) {
        return;
    }

    // Recursively print the left subtree
    print_ordered(root->left);

    // Print the current node's value
    printf("%d ", root->data);

    // Recursively print the right subtree
    print_ordered(root->right);

    return; // Explicit return (optional, as void functions return automatically)
}

// Function to free all nodes of a binary tree
Node *clean(Node *root) {
    // If the root is not NULL, continue the recursion
    if (root) {
        // Recursively clean the left subtree
        root->left = clean(root->left);
        
        // Recursively clean the right subtree
        root->right = clean(root->right);
        
        // Free the current node
        free(root);
    }

    // Return NULL to indicate that the tree has been cleared
    return 0;
}