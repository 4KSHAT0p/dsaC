#include <stdio.h>
int profit(int *, int);
int main()
{
    int arr[3] = {2,4,1};

    printf("%d", profit(arr, 3));
    return 0;
}

int profit(int *arr, int n)
{

    int min = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[min] > arr[i])
        {
            min = i;
        }
    }
    printf("min is %d\n", min);
if(min==n-1)
{
    profit(arr,n-1);
}
else{
    int max=min;
    for (int j = min; j < n-1; j++)
    {
        if (arr[j] < arr[j + 1])
        {
            max = j + 1;
        }
    }
    printf("max is %d\n", max);
    if (arr[max] > arr[min])
    {
        return arr[max] - arr[min];
    }
    else
    {
        return 0;
    }
}
}