// binary to decimal

#include <stdio.h>
#include <math.h>
int main()
{

   long int bin, i, j, k, l, arr[100],sum=0;


   printf("enter a binary number\n");
   scanf("%d", &bin);

   for (i = 0;; i++)
   {
      if (bin < (pow(10, i)))
         break;
   }

   for (j = 0, k = 0, l = 0; j <= i, k<99, l <=i-1; j++, k++, l++)
   {

      arr[99] = pow(10, j);

      arr[98] = pow(2, l);

      arr[k] = (bin / arr[99]) % 10;

      sum = sum + (arr[k] * arr[98]);
   }

   printf("the decimal equivalent of %d is %d", bin, sum);

   return 0;
}