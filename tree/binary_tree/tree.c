/*
The code contains two recursive functions that operate on a binary tree.
*/

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
Node* rotate_right(Node*);
Node* rotate_left(Node*);
Node* insert(Node*, int);
Node* remove(Node*, int);
void show_preorder(Node*);
void show_inorder(Node*);
void show_postorder(Node*);
Node* clean(Node*);
int node_count(Node*);
int height(Node*);
int max(int, int);
int get_balance(Node*);

int main() {
    Node *tree = NULL; // Initialize an empty tree

    // Insert elements into the tree
    tree = insert(tree, 8);
    tree = insert(tree, 3);
    tree = insert(tree, 2);
    tree = insert(tree, 5);
    tree = insert(tree, 10);

    printf("Tree in pre-order: ");
    show_preorder(tree); // Show the tree in pre-order traversal
    printf("\n");
    printf("Tree in sorted order: ");
    show_inorder(tree);
    printf("\n");
    printf("Tree in post-order: ");
    show_postorder(tree); // Show the tree in post-order traversal
    printf("\n");

    printf("Number of nodes: %d\n", node_count(tree)); // Count the number of nodes
    printf("Height of the tree: %d\n", height(tree)); // Calculate the height of the tree
    printf("Height of the left subtree: %d\n", height(tree->left)); // Height of the left subtree
    printf("Height of the right subtree: %d\n", height(tree->right)); // Height of the right subtree

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

// Function to rotate the tree to the right
Node *rotate_right(Node *root) {
    Node *new_root = root->left; // New root is the left child of the current root
    root->left = new_root->right; // Move the right child of the new root to the left child of the current root
    new_root->right = root; // Set the current root as the right child of the new root
    return new_root; // Return the new root
}

// Function to rotate the tree to the left
Node *rotate_left(Node *root) {
    Node *new_root = root->right; // New root is the right child of the current root
    root->right = new_root->left; // Move the left child of the new root to the right child of the current root
    new_root->left = root; // Set the current root as the left child of the new root
    return new_root; // Return the new root
}

// Function to insert a value into the BST
Node *insert(Node *root, int value) {
    // Standard BST insertion
    if (!root)
        return create(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root; // Ignore duplicates
    
    // Check the balance factor
    int balance = get_balance(root);

    // Cases of imbalance

    // Left Left (LL)
    if (balance > 1 && value < root->left->data)
        return rotate_right(root);

    // Right Right (RR)
    if (balance < -1 && value > root->right->data)
        return rotate_left(root);

    // Left Right (LR)
    if (balance > 1 && value > root->left->data) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    // Right Left (RL)
    if (balance < -1 && value < root->right->data) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root; // Already balanced
}    


// Function to remove a node from the BST
Node *remove(Node *root, int value) {
    if (!root) {
        return NULL; // Base case: if the node is NULL, return NULL
    }

    if (value < root->data) {
        root->left = remove(root->left, value); // Remove from the left subtree
    }
    else if (value > root->data) {
        root->right = remove(root->right, value); // Remove from the right subtree
    }
    else { // Node with only one child or no child
        if (!root->left) {
            Node *temp = root->right;
            free(root);
            return temp; // Return the right child
        }
        else if (!root->right) {
            Node *temp = root->left;
            free(root);
            return temp; // Return the left child
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        Node *temp = root->right;
        while (temp && temp->left) {
            temp = temp->left;
        }
        root->data = temp->data; // Copy the inorder successor's data to this node
        root->right = remove(root->right, temp->data); // Delete the inorder successor
    }
    return root; // Return the unchanged node pointer
}

// Function to show the tree in pre-order traversal
void show_preorder(Node *root) {
    if (root) {
        printf("%d ", root->data); // Visit the root
        show_preorder(root->left); // Traverse the left subtree
        show_preorder(root->right); // Traverse the right subtree
    }
    else return; // Base case: if the node is NULL, do nothing
}

// Function to show the tree in sorted order (in-order traversal)
void show_inorder(Node *root) {
    if (root) {
        show_inorder(root->left);
        printf("%d ", root->data);
        show_inorder(root->right);
    }
    else return; // Base case: if the node is NULL, do nothing
}

// Function to show the tree in post-order traversal
void show_postorder(Node *root) {
    if (root) {
        show_postorder(root->left); // Traverse the left subtree
        show_postorder(root->right); // Traverse the right subtree
        printf("%d ", root->data); // Visit the root
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

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get the balance of a node
int get_balance(Node *node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}
