#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void merge(int *arr, int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int *arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();
        double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d elements = %f seconds\n", n, cpu_time);
    }
    
    return 0;
}