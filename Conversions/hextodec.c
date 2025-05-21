#include <stdio.h>
#include<string.h>
#include<math.h>

int main()
{
   int arr[100]; 
   char str[100];
   int i,j,k,sum=0;
   printf("Enter a valid hexadecimal number\n");
   gets(str);
   
   if (strlen(str)>1)

  { for(i=0,j=strlen(str)-1;i<=strlen(str)-1,j>=0;i++,j--)
   {
    if(str[i]=='A')
    {arr[i]=10;}

    else if(str[i]=='B')
    {arr[i]=11;} 
    
    else if(str[i]=='C')
    {arr[i]=12;}

    else if(str[i]=='D')
    {arr[i]=13;}

    else if(str[i]=='E')
    {arr[i]=14;}

    else if(str[i]=='F')
    {arr[i]=15;}

    else{
        arr[i]=str[i];
        arr[i]-=48;
    }

    

k=pow(16,j);
sum=sum+(k*arr[i]);


   }
   printf("the decimal equivalent of %s is %d",str,sum);

   }

   else
   {
     
    printf("enter a valid 2 or more digit hexadecimal number"); 
    

   }

   
    return 0;
}