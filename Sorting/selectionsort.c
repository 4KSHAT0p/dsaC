#include<stdio.h>
void swap(int*,int*);
void selectionSort(int,int[]);
int main()
{

int arr[6]={7,22,4,12,29,1};
selectionSort(6,arr);
for(int i=0;i<6;i++)
{
    printf("%d ",arr[i]);
}

return 0;
}
void selectionSort(int n,int arr[])
{
    int min,i,j;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
           if(arr[j]<arr[min])
           {
            min=j;
           }
        }
        if(min!=i)
        {
            swap(&arr[min],&arr[i]);
        }
    }
}
void swap(int* x,int* y)
{
int temp;
temp=*x;
*x=*y;
*y=temp;
}