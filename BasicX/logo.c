#include <stdio.h>
int main()
{

    int n;
    int c = 0, d = 0;
    printf("enter dimensions\n");
    scanf("%d", &n);
    int arr[n][n];
    for (int *p = &arr[0][0]; p <= &arr[n - 1][n - 1]; p++)
    {
        scanf("%d", p);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[i][j] == arr[i][n - j - 1]) && (arr[i][j] == arr[n - i - 1][j]))
            {
                c = 1;
            }
            else
            {
                d = 2;
            }
        }
    }

    if (d == 2)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }

    return 0;
}