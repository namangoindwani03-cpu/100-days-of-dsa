//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Zigzag traversal
void zigzagTraversal(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int arr[100];

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            int index = leftToRight ? i : size - 1 - i;
            arr[index] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        // Print current level
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);

        printf("\n");

        leftToRight = !leftToRight;
    }
}


int main() {
   
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Zigzag Traversal:\n");
    zigzagTraversal(root);

    return 0;
}