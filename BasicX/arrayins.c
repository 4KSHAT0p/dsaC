#include<stdio.h>
void insert(int[6],int,int);
int main()
{
int arr[6]={1,2,3,4,5,0};
insert(arr,6,1);
for(int i=0;i<6;i++)
{
    printf("%d\n",arr[i]);
}

    return 0;
}
void insert(int x[6],int element,int index)
{
     for(int i=index;i<6;i++)
     {
         x[i+1]=x[i]; 
     }
     x[index]=element;
}