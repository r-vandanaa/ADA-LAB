#include <stdio.h>
#define LEFT -1
#define RIGHT 1

int a[20], dir[20];
void printPermutation(int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int getMobile(int n) {
    int mobile = -1, index = -1;
    for (int i = 0; i < n; i++) {
        if (dir[a[i]] == LEFT && i > 0 && a[i] > a[i-1] && a[i] > mobile) {
            mobile = a[i];
            index = i;
        }
        if (dir[a[i]] == RIGHT && i < n-1 && a[i] > a[i+1] && a[i] > mobile) {
            mobile = a[i];
            index = i;
        }
    }
    return index;
}

void johnsonTrotter(int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
        dir[a[i]] = LEFT;
    }

    printPermutation(n);

    while (1) {
        int m = getMobile(n);
        if (m == -1) break;

        int swapIndex = (dir[a[m]] == LEFT) ? m-1 : m+1;

        int temp = a[m];
        a[m] = a[swapIndex];
        a[swapIndex] = temp;

        m = swapIndex;

        for (int i = 0; i < n; i++) {
            if (a[i] > a[m]) dir[a[i]] *= -1;
        }

        printPermutation(n);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
