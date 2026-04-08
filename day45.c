// Find the height (maximum depth) of a given binary tree.
#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}