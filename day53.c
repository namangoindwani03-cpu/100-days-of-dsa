// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}


struct Pair {
    struct TreeNode* node;
    int col;
};


struct Queue {
    struct Pair* data;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int cap) {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->capacity = cap;
    q->front = q->size = 0;
    q->rear = cap - 1;
    q->data = malloc(cap * sizeof(struct Pair));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, struct TreeNode* node, int col) {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear].node = node;
    q->data[q->rear].col = col;
    q->size++;
}

struct Pair dequeue(struct Queue* q) {
    struct Pair p = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return p;
}


void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    int minCol = 0, maxCol = 0;

    struct Queue* q = createQueue(100);
    enqueue(q, root, 0);

    int** cols = calloc(200, sizeof(int*));
    int* colSizes = calloc(200, sizeof(int));

    while (!isEmpty(q)) {
        struct Pair p = dequeue(q);
        struct TreeNode* node = p.node;
        int col = p.col + 100; 

        colSizes[col]++;
        cols[col] = realloc(cols[col], colSizes[col] * sizeof(int));
        cols[col][colSizes[col] - 1] = node->val;

        if (p.col < minCol) minCol = p.col;
        if (p.col > maxCol) maxCol = p.col;

        if (node->left) enqueue(q, node->left, p.col - 1);
        if (node->right) enqueue(q, node->right, p.col + 1);
    }

    
    printf("Vertical Order Traversal:\n");
    for (int i = minCol; i <= maxCol; i++) {
        int idx = i + 100;
        for (int j = 0; j < colSizes[idx]; j++) {
            printf("%d ", cols[idx][j]);
        }
        printf("\n");
    }
}


int main() {
   
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(0);
    root->right->left = newNode(1);
    root->right->right = newNode(7);

    verticalOrder(root);

    return 0;
}