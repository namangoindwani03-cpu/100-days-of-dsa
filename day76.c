// Using DFS or BFS, count number of connected components.
#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
void dfs(int v, int n, int graph[MAX][MAX]) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i, n, graph);
        }
    }
}

// Function to count connected components
int countComponents(int n, int graph[MAX][MAX]) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, graph);
            count++;
        }
    }
    return count;
}

int main() {
    int n = 5;

    int graph[MAX][MAX] = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1}
    };

    printf("Number of connected components: %d", countComponents(n, graph));
    return 0;
}