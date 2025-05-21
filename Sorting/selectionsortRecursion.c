#include <stdio.h>
#include <stdlib.h>
void selectionSort(int[], int, int);
void swap(int *, int *);
int main(int argc, char *argv[])
{
    int arr[5] = {14, 12, 15, 78, 23};
    selectionSort(arr, 5, 0);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//most intuitive way to make recursive function
void selectionSort(int x[], int n, int i) //n ending index and i starting index to sort
{
    if (i == n - 2)
    {
        return;
    }
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        if (x[min] < x[j])
        {
            min = j;
        }
    }

    swap(&x[i], &x[min]);
    selectionSort(x, n, i + 1);
}
