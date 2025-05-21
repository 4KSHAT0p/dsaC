#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<conio.h>
void checkTriplet(int[],int);
int main(void)
{
int n;
printf("enter the number of elements in the array\n");
scanf("%d",&n);
int arr[n];
printf("now, enter each element of this array\n");
for(int i=0;i<n;i++)
{
    printf("now, enter %d element of this array\n",i+1);
    scanf("%d",&arr[i]);
}

checkTriplet(arr,n);
return 0;
}
void checkTriplet(int x[],int y)
{
    int i,j,k,count=0,ter=99;
for(i=0;i<y;i++)
{
    for(j=0;j<y;j++)
    {
        for(k=0;j<y;k++)
        {
            if(pow(x[i],2) == pow(x[j],2) + pow(x[k],2))
            {
                count++;
            }
            
        }
    }
}
printf("you have %d pythagorean triplet(s) in this array\n",count);

}