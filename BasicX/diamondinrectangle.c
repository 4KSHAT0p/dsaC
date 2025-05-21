#include<stdio.h>

int main()
{
    int i,k,n;
    printf("enter");
    scanf("%d",&n);

    for(i=2*n;i>1;i--)
    {
        printf("*");
    }
    printf("\n");
for(i=n;i>1;i--)
{
    for(k=0;k<i-1;k++)  //stars1
    {
        printf("*");
        
    }
    
   for(k=n;k>=i;k--)  //spaces 1
    {
        printf(" ");
        
    }
   
   for(k=n-1;k>=i;k--)  //spaces 2
    {
        printf(" ");
        
    }
   for(k=0;k<i-1;k++)  //stars2
    {
        printf("*");
        
    }

   
    printf("\n");
}

for(i=n-1;i>1;i--)

{
     for(k=n;k>=i;k--)  //stars 3
    {
        printf("*");
        
    }
    
    for(k=0;k<i-1;k++)  //spaces 3
    {
        printf(" ");
        
    }
    for(k=1;k<i-1;k++)  //spaces 4
    {
        printf(" ");
        
    }
   for(k=n;k>=i;k--)  //stars 4
    {
        printf("*");
        
    }
    printf("\n");
}

 for(i=2*n;i>1;i--)
    {
        printf("*");
    }
    
    return 0;
}