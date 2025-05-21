#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void ss(int *, int);
void swap(int *, int *);
int main()
{
    int arr[9] = {17, 26, 20, 44, 55, 31, 54, 77, 93};
    ss(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
void ss(int *arr, int n)
{
    int win = n / 2;
    while (win >= 1)
    {
        for (int i = 0; i < n - win; i++)
        {
            if (arr[i] > arr[win + i])
            {
                swap(&arr[i], &arr[win + i]);
                if (i >= win)
                {
                    if (arr[i] < arr[i - win])
                    {
                        swap(&arr[i], &arr[i - win]);
                    }
                }
            }
        }
        win /= 2;
    }
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}