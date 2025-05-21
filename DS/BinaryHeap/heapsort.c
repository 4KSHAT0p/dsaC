// see ONENOTE
//these codes are more efficient than heap.c
#include <stdio.h>
#include <stdlib.h>
void HEAPIFY(int *, int);
void HEAPIFY2(int *, int, int); // here we are heapifying a particular index
void BUILDHEAP(int*,int);
void delete(int*,int);
void heapsort(int*,int);
void swap(int *, int *);
int main()
{
    int arr[5] = {2,3,1,6,0};  //only root not following heap property
    heapsort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
void HEAPIFY(int *arr, int n) // sift down approach
{
    if (n <= 0)
    {
        return;
    }
    int largest = (n - 2) / 2;
    int right = (2 * largest) + 2;
    int left = (2 * largest) + 1;

    if (right < n)
    {
        if (arr[largest] < arr[right])
        {
            largest = right;
        }
        if (arr[largest] < arr[left])
        {
            largest = left;
        }
    }
    else
    {
        if (arr[largest] < arr[left])
        {
            largest = left;
        }
    }
    if (largest != (n - 2) / 2)
    {
        swap(&arr[largest], &arr[(n - 2) / 2]);
    }

    HEAPIFY(arr, n - 2); // #math   n ko aise manipulate karna hai ki naya n -2/2=(n-2)/2 -1 aaye
}

void HEAPIFY2(int *arr, int n, int i)  //logn
{
    
    int largest=i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if(right<n && arr[right]>arr[largest])
    {
       largest=right;
    }
    if(left<n && arr[left]>arr[largest])  //it may happen that index i is a leaf node
    {
        largest=left;
    }
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
    }
    else
    {
        return;  //i=largest means arr[i]>left && arr[i]>right or left/right dont exist i.e. leaf
    }
    HEAPIFY2(arr,n,largest);
}
void delete(int* arr,int n) //TC logn
{
    swap(&arr[0],&arr[n-1]);
    HEAPIFY2(arr,n-1,0);
}
void heapsort(int*arr,int n) //O(n+nlogn)
{
    BUILDHEAP(arr,n); //O(n)
    for(int i=n;i>0;i--) //O(nlogn)
    {
        delete(arr,i);
    }
}
void swap(int *x, int *y)
{
    if (*x == *y)
    {
        return;
    }
    else
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
}
void BUILDHEAP(int* arr,int n)  //sift down approach
{
   for(int i=(n-2)/2;i>=0;i--)
   {
      HEAPIFY2(arr,n,i);
   }
}
