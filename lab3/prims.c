#include <stdio.h>
#define MAX 10
#define INT_MAX 10000

void prims(int n, int cost[MAX][MAX]){
    int visited[MAX] = {0};
    visited[0] = 1;

    int num_of_edges = 0;
    int min_cost = 0;
    int u = -1, v = -1;

    printf("Edges:");

    while(num_of_edges < n - 1){
        int min = INT_MAX;

        for(int i = 0; i < n; i++){
            if(visited[i] == 1){
                for(int j = 0; j < n; j++){
                    if(visited[j] == 0 && cost[i][j] < min){
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(min == INT_MAX){
            printf("\nGraph is not connected\n");
            return;
        }

        printf("\n%d --> %d", u, v);
        min_cost += min;
        visited[v] = 1;
        num_of_edges++;
    }

    printf("\nTotal weight of graph: %d\n", min_cost);
}

int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        scanf("%d", &cost[i][j]);
        if(i != j && cost[i][j] == 0){
            cost[i][j] = INT_MAX;
        }
    }
}

    prims(n, cost);
    return 0;
}