#include <stdio.h>
#define MAX 100
#define INF 9999

void dijkstra(int cost[MAX][MAX], int n, int src) {
    int dist[MAX], visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = -1, min = INF;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break; 
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != INF && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("Vertex\tDistance from source %d\n", src);
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int n;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0) {
                cost[i][j] = INF; 
            }
        }
    }

    dijkstra(cost, n, 0); // source = 0
    return 0;
}
