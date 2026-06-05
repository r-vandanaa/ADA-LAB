#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int partition(int* arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j]>pivot) {
            j--;
        }
        if(i<j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int*arr, int low, int high){
    if(low<high){
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}


int main() {
    for(int i=1;i<=20;i++){
        int n=10000*i;
        int arr[n];
        srand(time(NULL));

        for (int i = 0; i < n; i++)
            arr[i] = rand();

        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%f\n",cpu_time);
    }
}