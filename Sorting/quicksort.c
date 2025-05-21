#include <stdio.h>
#include <stdlib.h>
void swap(int *, int *);
void quicksort(int[], int, int);
int main()
{
                   //i,j
    int arr[8] = {0, 2, 5, 7, 1, 4, 3, 6};

    quicksort(arr, 0, 7);

    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", arr[i]);
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
void quicksort(int x[], int low, int high)
{
    if(low<high)  //why this?
    {

    int pivot = x[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (x[i]<=pivot && i < high)
        i++; 
        while (x[j]>pivot)
        j--;
        
        if(i<j)
        {
        swap(&x[i], &x[j]);
        }
        
    }
    swap(&x[low], &x[j]);
    int Pindex = j;
    //printf("j is %d \n",j);
    quicksort(x, low, Pindex - 1);
    quicksort(x, Pindex + 1, high);
    }
}