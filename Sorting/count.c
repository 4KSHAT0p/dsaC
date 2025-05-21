#include <stdio.h>
void count(int *, int);

int main()
{
int arr[7]={4,1,6,2,4,1};
count(arr,7);
    return 0;
}
void count(int *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }
    int temp[max+1];
    for (int j = 0; j <= max; j++)
    {
        temp[j] = 0;
    }

    for (int k = 0; k < n; k++)
    {
        temp[arr[k]]++;
    }
    
    for(int m=1;m<=max;m++)  //i am getting intuition but not clear
    {
        temp[m]+=temp[m-1];
    }

for(int i=0;i<=max;i++)
{
    printf("%d ",temp[i]);
}
}