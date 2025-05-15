#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

void dfs(int u) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (graph[u][v] && !visited[v])
            dfs(v);
    }
    push(u);
}

int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }
    printf("Topological Sort: ");
    while (top != -1)
        printf("%d ", pop());
    printf("\n");
    return 0;
}
