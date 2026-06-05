#include <stdio.h>
#include <stdlib.h>

int x[20];
int n;

int place(int k, int i)
{
    int j;

    for(j = 1; j < k; j++)
    {
        if((x[j] == i) || (abs(k - j) == abs(i - x[j])))
            return 0;
    }

    return 1;
}

void nqueens(int k)
{
    int i;

    for(i = 1; i <= n; i++)
    {
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                int j;

                printf("\nSolution:\n");

                for(j = 1; j <= n; j++)
                {
                    printf("Row %d -> Column %d\n", j, x[j]);
                }

                printf("\nChess Board:\n");

                int r, c;

                for(r = 1; r <= n; r++)
                {
                    for(c = 1; c <= n; c++)
                    {
                        if(x[r] == c)
                            printf(" Q ");
                        else
                            printf(" . ");
                    }
                    printf("\n");
                }

                printf("\n");
            }
            else
            {
                nqueens(k + 1);
            }
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);

    nqueens(1);

    return 0;
}
