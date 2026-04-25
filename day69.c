//  Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// ---------------- MIN HEAP ----------------

struct MinHeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    int pos[V];
    struct MinHeapNode** array;
};

// Create min heap node
struct MinHeapNode* newMinHeapNode(int v, int dist) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

// Create min heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos[capacity];
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return heap;
}

// Swap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify
void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;

    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        heap->pos[heap->array[smallest]->v] = idx;
        heap->pos[heap->array[idx]->v] = smallest;

        swapMinHeapNode(&heap->array[smallest], &heap->array[idx]);

        minHeapify(heap, smallest);
    }
}

// Check if empty
int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

// Extract min
struct MinHeapNode* extractMin(struct MinHeap* heap) {
    if (isEmpty(heap))
        return NULL;

    struct MinHeapNode* root = heap->array[0];

    struct MinHeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;

    heap->pos[root->v] = heap->size - 1;
    heap->pos[lastNode->v] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

// Decrease key
void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->v] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->v] = i;

        swapMinHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

// Check if vertex in heap
int isInMinHeap(struct MinHeap* heap, int v) {
    if (heap->pos[v] < heap->size)
        return 1;
    return 0;
}

// ---------------- DIJKSTRA ----------------

void dijkstra(struct Node* adj[], int src) {
    int dist[V];

    struct MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        heap->array[v] = newMinHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }

    heap->array[src] = newMinHeapNode(src, 0);
    heap->pos[src] = src;
    dist[src] = 0;
    heap->size = V;

    decreaseKey(heap, src, 0);

    while (!isEmpty(heap)) {
        struct MinHeapNode* minNode = extractMin(heap);
        int u = minNode->v;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->vertex;

            if (isInMinHeap(heap, v) && dist[u] != INT_MAX &&
                temp->weight + dist[u] < dist[v]) {

                dist[v] = dist[u] + temp->weight;
                decreaseKey(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// ---------------- MAIN ----------------

int main() {
    struct Node* adj[V];

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 7);
    addEdge(adj, 2, 4, 3);
    addEdge(adj, 3, 4, 1);

    dijkstra(adj, 0);

    return 0;
}