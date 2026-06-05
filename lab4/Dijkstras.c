#include <stdio.h>
#define INT_MAX 10000
#define MAX 100

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstras(int cost[MAX][MAX], int n, int s){
    int dist[MAX], visited[MAX], parent[MAX];

    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[s] = 0;

    for(int i = 0; i < n; i++){
        int u = minDistance(dist, visited, n);
        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < n; v++){
            if (!visited[v] && cost[u][v] != INT_MAX &&
                dist[u] != INT_MAX &&
                dist[u] + cost[u][v] < dist[v]) {

                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Vertex\tDistance (from given source %d) \n",s);
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
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
            if(cost[i][j] == 0 && i != j){
                cost[i][j] = INT_MAX;
            }
        }
    }

    dijkstras(cost, n, 0);
}