// Using BFS or DFS, check if the entire graph is connected.
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
int n; // number of vertices

void dfs(int v) {
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int isConnected() {
    dfs(0); // start from node 0

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return 0; // not connected
    }
    return 1; // connected
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isConnected())
        printf("Graph is Connected\n");
    else
        printf("Graph is NOT Connected\n");

    return 0;
}