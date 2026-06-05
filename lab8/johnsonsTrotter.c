#include <stdio.h>

int a[10], dir[10];

void printPermutation(int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int mobile(int n)
{
    int i, mobile_prev = 0, mobile_index = -1;

    for(i = 0; i < n; i++)
    {
        if(dir[a[i]-1] == -1 && i != 0)
        {
            if(a[i] > a[i-1] && a[i] > mobile_prev)
            {
                mobile_prev = a[i];
                mobile_index = i;
            }
        }

        if(dir[a[i]-1] == 1 && i != n-1)
        {
            if(a[i] > a[i+1] && a[i] > mobile_prev)
            {
                mobile_prev = a[i];
                mobile_index = i;
            }
        }
    }

    return mobile_index;
}

void johnsonTrotter(int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = -1;
    }

    printPermutation(n);

    while(1)
    {
        int m = mobile(n);

        if(m == -1)
            break;

        int swapIndex;

        if(dir[a[m]-1] == -1)
            swapIndex = m - 1;
        else
            swapIndex = m + 1;

        int temp = a[m];
        a[m] = a[swapIndex];
        a[swapIndex] = temp;

        m = swapIndex;

        for(i = 0; i < n; i++)
        {
            if(a[i] > a[m])
                dir[a[i]-1] *= -1;
        }

        printPermutation(n);
    }
}

int main()
{
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
