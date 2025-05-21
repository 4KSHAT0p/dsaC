#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>

int main(void)
{

int i,j=0,k=0;

  for (i = 1;; i++)
    {

    label:
        if (getch() == 224)
        {
            if (getch() == 80)
            {
                j++;
                printf("you pressed down %d times\n", j);
                goto label;
            }
            
        else
        {
            printf("abrupt\n");
        }
        }}

  return 0;
}