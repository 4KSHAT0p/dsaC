#include <stdio.h>

int main()
{
    int arr[11] = {1, 2, 3, 3, 4, 2, 5, 5, 7, 7, 1};
    for (int i = 0; i < 11; i++)
    {
        for (int j = i; j < 11; j++) //j=0;
        {
            if (i == j)
            {
                continue;   //break;
            }
            else
            {
                if (arr[i] == arr[j])
                {
                    printf("%d has a duplicate(s)\n", arr[i]);
                    break;
                }
            }
        }
    }

    return 0;
}