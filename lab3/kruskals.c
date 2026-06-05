#include <stdio.h>

#define MAX 10
#define INT_MAX 10000

void kruskals(int n, int cost[MAX][MAX]){
    int parent[MAX] = {0};
    int ne = 0, mincost = 0;
    int u, v, a, b;

    printf("Edges:\n");

    while(ne < n - 1){
        int min = INT_MAX;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        int root_u = u;
        while(parent[root_u] != 0)
            root_u = parent[root_u];

        int root_v = v;
        while(parent[root_v] != 0)
            root_v = parent[root_v];

        if(root_u != root_v){
            parent[root_v] = root_u;
            printf("%d --> %d = %d\n", a, b, min);
            mincost += min;
            ne++;
        }

        cost[a][b] = cost[b][a] = INT_MAX;
    }

    printf("Total weight of graph: %d\n", mincost);
}

int main(){
    int n;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
            if(i != j && cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }

    kruskals(n, cost);
    return 0;
}