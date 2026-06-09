#include <stdio.h>

float fractionalKnapsack(int value[], int weight[], int n, int W)
{
    float ratio[n];
    for(int i = 0; i < n; i++)
        ratio[i] = (float)value[i] / weight[i];

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                float tempR = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempR;

                int temp = value[i];
                value[i] = value[j];
                value[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }

    float profit = 0;
    for(int i = 0; i < n; i++)
    {
        if(weight[i] <= W)
        {
            profit += value[i];
            W -= weight[i];
        }
        else
        {
            profit += ratio[i] * W;
            break;
        }
    }

    return profit;
}

int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int value[n], weight[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d%d", &value[i], &weight[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    float result = fractionalKnapsack(value, weight, n, W);

    printf("Maximum Profit = %.2f\n", result);

    return 0;
}
