#include <stdio.h>

void prims(int cost[10][10], int n) {
    int i, j, u = 0, v = 0, min, mincost = 0, visited[10] = {0}, ne = 1;

    visited[0] = 1;  // Start from vertex 0

    printf("The edges considered for MST are:\n");

    while (ne < n) {
        min = 999;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    // Skip if already visited or no edge (i.e., cost[i][j] == 0)
                    if (!visited[j] && cost[i][j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (!visited[v]) {
            printf("%d. Edge (%d -> %d) = %d\n", ne++, u, v, min);
            mincost += min;
            visited[v] = 1;
        }

        cost[u][v] = cost[v][u] = 999;  // Mark edge as used
    }

    printf("Cost of Minimum Spanning Tree is %d\n", mincost);
}

int main() {
    int i, j, n, cost[10][10];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(cost, n);

    return 0;
}
