#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[7] = {1, 1, 2, 2, 2, 3, 3};

    int *f = arr;
    int *s = arr;
    int index = 1;
    for (int i = 1; i < 7; i++)
    {
        if (*(s + i) != *f)
        {
            f = s + i;
            arr[index++] = *(s + i);
        }
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}