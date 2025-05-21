#include <stdio.h>
int main()
{
    int arr[5] = {0,1,2,3,4};

    for (int i = 1; i < 5; i++)
    {
        int key = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] < key)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}