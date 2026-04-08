// Check whether a given binary tree is symmetric around its center.
#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to check mirror
int isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;

    if (t1 == NULL || t2 == NULL)
        return 0;

    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Main function to check symmetry
int isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}