#include <stdio.h>
int main()
{
    int i, j, k, m;

    printf("enter the base\n");
    scanf("%d", &m);

    if (m % 2 == 0)
    {

        for (i = m - 1; i >= 1; i -= 2)
        {

            for (k = ((i + 1) / 2); k >= 1; k--)
            {
                printf(" ");
            }

            for (j = m; j >= i; j--)
            {
                printf("x");
            }

            printf("\n");
        }
    }

    else
    {
        for (i = m; i >= 1; i -= 2)
        {
            for (k = (i - 1) / 2; k >= 1; k--)

            {

                printf(" ");
            }

            for (j = m; j >= i; j--)
            {

                printf("x");
            }

            printf("\n");
        }
    }
    return 0;
}

