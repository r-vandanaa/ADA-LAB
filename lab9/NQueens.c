#include <stdio.h>
#include <stdlib.h>

int x[20], n;

void queen(int r)
{
    for(int c = 1; c <= n; c++)
    {
        int ok = 1;

        for(int i = 1; i < r; i++)
        {
            if(x[i] == c || abs(x[i] - c) == abs(i - r))
            {
                ok = 0;
                break;
            }
        }

        if(ok)
        {
            x[r] = c;

            if(r == n)
            {
                printf("\nChess Board:\n");

                for(int i = 1; i <= n; i++)
                {
                    for(int j = 1; j <= n; j++)
                    {
                        if(x[i] == j)
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
                queen(r + 1);
            }
        }
    }
}

int main()
{
    printf("Enter n: ");
    scanf("%d", &n);

    queen(1);

    return 0;
}
