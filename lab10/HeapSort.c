#include <stdio.h>

void heapBottomUp(int H[], int n) {
    int i, k, v, j;

    for (i = n / 2; i >= 1; i--) {
        k = i;
        v = H[k];

        while (2 * k <= n) {
            j = 2 * k;

            if (j < n && H[j] < H[j + 1])
                j++;

            if (v >= H[j])
                break;

            H[k] = H[j];
            k = j;
        }

        H[k] = v;
    }
}

void heapSort(int H[], int n) {
    int i, temp, k, v, j;

    heapBottomUp(H, n);

    for (i = n; i >= 2; i--) {
        temp = H[1];
        H[1] = H[i];
        H[i] = temp;

        k = 1;
        v = H[k];

        while (2 * k <= i - 1) {
            j = 2 * k;

            if (j < i - 1 && H[j] < H[j + 1])
                j++;

            if (v >= H[j])
                break;

            H[k] = H[j];
            k = j;
        }

        H[k] = v;
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int H[n + 1];

    printf("Enter elements:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &H[i]);

    heapSort(H, n);

    printf("Sorted array:\n");
    for (i = 1; i <= n; i++)
        printf("%d ", H[i]);

    return 0;
}
