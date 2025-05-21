#include <stdio.h>
#include <stdlib.h>
void mergesort(int[], int, int);
int temp[9];
int main()
{
    int arr[9] = {12, 100, 11, 23, 23, 63, 10, 5, 67};

    mergesort(arr, 0, 8);

    for (int i = 0; i < 9; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
void mergesort(int x[], int low, int high)
{
    if (low < high)
    {
        int middle = (low + high) / 2;
        mergesort(x, low, middle);
        mergesort(x, middle + 1, high);

        int index = low; // why starting index is not zero and it's low
        int i = low;
        int j = middle + 1;
        while (i <= middle && j <= high)
        {
            if (x[i] < x[j])
            {
                temp[index++] = x[i];
                i++;
            }
            else
            {
                temp[index++] = x[j];
                j++;
            }
        }
        while (i <= middle)
        {
            temp[index++] = x[i];
            i++;
        }
        while (j <= high)
        {
            temp[index++] = x[j];
            j++;
        }
        for (int i = low; i <= high; i++)
        {
            x[i] = temp[i];
        }
    }
    else
    {
        printf("error\n");
    }
}
// note on time and space complexity of mergesort and quicksort
/*
dividing the array into halves contribute O(log n)
merging them contributes O(n) (as we are iterating whole list of n size)
overall is nearly O(nlog n)
space complexity is O(n);

*/