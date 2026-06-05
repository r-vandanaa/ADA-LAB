#include <stdio.h>
#define INTMAX 999999
void floyds(int n, int graph[n][n]){
    for(int k=0; k<n;k++){
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                if(graph[i][j] >= graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }

            }
        }
    }
    for(int i=0;i<n;i++){
        printf("From vertex %d\n",i+1);
        for(int j=0; j<n; j++){
            printf("%d to %d --> %d\n", i+1, j+1, graph[i][j]);
        }
    }

}


int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter adjacency matrix (Enter zero for no path): \n");
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==0 && i!=j ){
                graph[i][j]=INTMAX;
            }
        }
    }
    floyds(n,graph);
}