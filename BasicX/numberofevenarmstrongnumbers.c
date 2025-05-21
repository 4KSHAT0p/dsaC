#include<stdio.h>
#include<math.h>
int main()
{
int up,lo,i,j,n,count=0;  // ye bahar define karna zaruri hai kyuki iski value hamesha zero nahi honi increment honi h

printf("enter lower limit\n");
scanf("%d",&lo);
printf("enter upper limit\n");
scanf("%d",&up);

for(n=lo;n<=up;n++)
{
   for(i=0;;i++)
   {
    if(n<pow(10,i))
    break;

   } 
int sum=0;                         //pehle maine sum bahar kiya tha declare and define isliye sum ki value har baar loop me 0 nahi thi add hoti ja rahi thi
   for(j=0;j<i;j++)
   {  
      int arr[i];
      int tend=pow(10,j);
      arr[j]=(n/tend)%10;;
      int l=pow(arr[j],i);
      sum+=l;
   }

if(sum==n && n%2==0)
{
count+=1;       // ye click nahi kiya ki number kaise nikale but baad me ho gaya
}

}
printf("the number of even armstrong numbers in range [%d,%d] is(are) %d",lo,up,count);
return 0;
}