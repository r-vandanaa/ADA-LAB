#include <stdio.h>

int maxi(int a, int b){
    if(a>b) return a;
    return b;
}

int knapSack(int weights[], int costs[], int w, int n){
    int V[n+1][w+1];
    for(int i=0; i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0||j==0)  V[i][j]=0;
            else{
                if(j<weights[i-1]){
                    V[i][j]=V[i-1][j];
                }
                else{
                    V[i][j]=maxi(V[i-1][j], (V[i-1][j-weights[i-1]]+costs[i-1]));
                }
            }
        }
    }
    return V[n][w];
}

int main(){
    int n,w;
    printf("Enter number of items: ");
    scanf("%d",&n);
    int weights[n], costs[n];
    for(int i=0;i<n;i++){
        printf("Enter weight and cost of item %d: ", i+1);
        scanf("%d%d",&weights[i],&costs[i]);
    }
    printf("Enter maximum weight: ");
    scanf("%d",&w);
    int maxCost=knapSack(weights, costs, w, n);
    printf("Maximum cost obtained: %d",maxCost);
}