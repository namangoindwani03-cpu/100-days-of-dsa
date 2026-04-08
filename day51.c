// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

#include <stdio.h>
#include <stdlib.h>

// Define TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search a node (returns pointer)
struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->val == key)
        return root;

    if (key < root->val)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find LCA in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root; // LCA found
    }
    return NULL;
}

// Inorder traversal (for checking)
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Build BST
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    int n1, n2;
    printf("Enter two node values to find LCA: ");
    scanf("%d %d", &n1, &n2);

    // Search nodes
    struct TreeNode* p = search(root, n1);
    struct TreeNode* q = search(root, n2);

    if (p == NULL || q == NULL) {
        printf("One or both nodes not found in BST.\n");
        return 0;
    }

    // Find LCA
    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        printf("LCA of %d and %d is: %d\n", n1, n2, lca->val);
    else
        printf("LCA not found.\n");

    return 0;
}