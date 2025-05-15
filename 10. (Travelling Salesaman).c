#include <stdio.h>
#define MAX 10
#define INF 99999

int n;
int dist[MAX][MAX];
int visited[MAX];
int min_cost = INF;

void tsp(int pos, int count, int cost, int start) {
    if (count == n && dist[pos][start]) {
        if (cost + dist[pos][start] < min_cost)
            min_cost = cost + dist[pos][start];
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[pos][i]) {
            visited[i] = 1;
            tsp(i, count + 1, cost + dist[pos][i], start);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter number of cities (max 10): ");
    scanf("%d", &n);
    printf("Enter distance matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    visited[0] = 1;
    tsp(0, 1, 0, 0);
    printf("Minimum cost of traveling all cities: %d\n", min_cost);
    return 0;
}
