#include <stdio.h>
int main()
{
      int n, i, j;
      printf("enter a number\n");
      scanf("%d", &n);
      for (i = 0; i < n; i++) // for number of lines in which pattern is to be printed (can be modified)
      {
            for (j = n; j >i; j--) // for number of elements present in 1 line (can be modified)
            {
                  printf("*");
            }
            printf("\n");
      }
      printf("\n");
}
