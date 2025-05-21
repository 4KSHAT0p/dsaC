#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[6]={1,2,1,3,4,2};
int n=6;
    int max=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }

    int hash[max+1]={0};

    for(int i=0;i<n;i++)
    {
        hash[arr[i]]++;
    }

    for(int i=0;i<max+1;i++)
    {
        printf("%d occurs %d times\n",i,hash[i]);
    }
}
