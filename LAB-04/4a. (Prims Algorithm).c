#include <stdio.h>
#include <limits.h>
#define N 5

int selectMin(int cost[], int visited[]) {
    int min = INT_MAX, idx;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && cost[i] < min) {
            min = cost[i];
            idx = i;
        }
    }
    return idx;
}

void displayMST(int from[], int graph[N][N]) {
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < N; i++)
        printf("%d --> %d  (weight: %d)\n", from[i], i, graph[i][from[i]]);
}

void prim(int graph[N][N]) {
    int from[N], cost[N], visited[N];

    for (int i = 0; i < N; i++) {
        cost[i] = INT_MAX;
        visited[i] = 0;
    }
    cost[0] = 0;
    from[0] = -1;
    for (int edges = 0; edges < N - 1; edges++) {
        int u = selectMin(cost, visited);
        visited[u] = 1;

        for (int v = 0; v < N; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < cost[v]) {
                from[v] = u;
                cost[v] = graph[u][v];
            }
        }
    }
    displayMST(from, graph);
}

int main() {
    int graph[N][N] = {
        {0, 3, 0, 0, 6},
        {3, 0, 1, 0, 4},
        {0, 1, 0, 2, 0},
        {0, 0, 2, 0, 5},
        {6, 4, 0, 5, 0}
    };
    prim(graph);
    return 0;
}
