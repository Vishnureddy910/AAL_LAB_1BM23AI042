#include <stdio.h>

#define V 5
#define E 7

int parent[V];

int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

void unionSets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB)
        parent[rootB] = rootA;
}

void sortEdges(int edges[E][3]) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                for (int k = 0; k < 3; k++) {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }
}

void kruskal(int edges[E][3]) {
    int total = 0;
    for (int i = 0; i < V; i++)
        parent[i] = i;
    printf("Edge \tWeight\n");
    int count = 0;
    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (find(u) != find(v)) {
            unionSets(u, v);
            printf("%d - %d \t%d\n", u, v, w);
            total += w;
            count++;
        }
    }
    printf("Total cost: %d\n", total);
}

int main() {
    int edges[E][3] = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 2},
        {2, 3, 4},
        {3, 4, 2},
        {2, 4, 5}
    };
    sortEdges(edges);
    kruskal(edges);
    return 0;
}
