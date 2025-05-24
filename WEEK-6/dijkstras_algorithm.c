#include <stdio.h>
int cost[10][10], n, result[10][2], weight[10];
void dijkstras(int[][10], int,int);


void dijkstras(int cost[][10], int s,int n)
{
    int d[10], p[10], visited[10];
    int i, j, u, v;

    for (i = 0; i < n; i++)
    {
        d[i] = 999;
        visited[i] = 0;
        p[i] = s;
    }

    d[s] = 0;

    for (i = 0; i < n - 1; i++)
    {
        int min = 999;
        u = -1;

        // Find the unvisited node with minimum distance
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }

        if (u == -1)
            break; // No more reachable nodes

        visited[u] = 1;

        // Update distances of neighbors
        for (v = 0; v < n; v++)
        {
            if (!visited[v] && cost[u][v] != 999 && d[u] + cost[u][v] < d[v])
            {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
            }
        }
    }

    // Store results
    for (i = 0; i < n; i++)
    {
        result[i][0] = p[i];
        result[i][1] = i;
        weight[i] = d[i];
    }
}



int main()
{
    int i, j, s;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 999; // Treat 0 (non-connected) as infinite cost
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &s);

    dijkstras(cost, s,n);

    printf("\nShortest Paths from vertex %d:\n", s);
    for (i = 0; i < n; i++)
    {
        if (i != s)
        {
            printf("(%d -> %d) with weight %d\n", result[i][0], result[i][1], weight[i]);
        }
    }

    return 0;
}
