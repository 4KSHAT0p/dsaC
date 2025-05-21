#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *, int *);
int main()
{
    int n, j, k;
    printf("enter the index of array\n");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter element %d of array\n", i + 1);
        scanf("%d", &arr[i]);
    }

    for (j = 0; j < n; j++)   //j<n-1
    {
        for (k = 0; k < n; k++)  //k<n-i-1
        {
            if (arr[j] > arr[k])  //arr[k]>arr[k+1]
            {
                swap(&arr[j], &arr[k]);
            }
        }
    }

    for (int l = 0; l < n; l++)
    {
        printf("%d ", arr[l]);
    }
    return 0;
}
void swap(int *x, int *y)
{

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}