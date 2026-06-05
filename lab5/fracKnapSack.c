#include <stdio.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

float calculateProfit(int values[], int weights[], int W, int n){
    float ratio[n];

    for(int i = 0; i < n; i++){
        ratio[i] = (float)values[i] / weights[i];
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(ratio[j] < ratio[j + 1]){
                swap(&ratio[j], &ratio[j + 1]);
                swapInt(&values[j], &values[j + 1]);
                swapInt(&weights[j], &weights[j + 1]);
            }
        }
    }

    float totalProfit = 0.0;

    for(int i = 0; i < n; i++){
        if(W >= weights[i]){
            totalProfit += values[i];
            W -= weights[i];
        } else {
            totalProfit += ratio[i] * W;
            break;
        }
    }

    return totalProfit;
}

int main(){
    int n, W;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int values[n], weights[n];
    for(int i=0;i<n;i++){
        printf("For item %d, Enter weight and value: ", i+1);
        scanf("%d%d",&weights[i], &values[i]);
    }
    printf("Enter the capacity: ");
    scanf("%d",&W);
    float profit = calculateProfit(values, weights,W, n);
    printf("The profit is %.2f", profit);
}