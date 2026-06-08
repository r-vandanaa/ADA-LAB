#include <stdio.h>
#define MAX 10
#define INF 9999

void prims(int n, int cost[MAX][MAX]) {
    int visited[MAX] = {0};
    visited[0] = 1;  
    int total = 0;

    printf("Edges in MST:\n");

    for (int edges = 0; edges < n - 1; edges++) {
        int u = -1, v = -1;
        int min = INF;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d -- %d  (weight %d)\n", u, v, min);
            visited[v] = 1;
            total += min;
        }
    }

    printf("Total weight = %d\n", total);
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

    prims(n, cost);
    return 0;
}
