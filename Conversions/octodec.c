#include <stdio.h>
#include <math.h>
int main()
{

    int oct, j, i, k, l, sum = 0;

    printf("enter a valid octal number\n");
    scanf("%d", &oct);

    for (i = 0;; i++)
    {
        if (oct < pow(10, i))
            break;
    }

    for (j = 0; j < i; j++)
    {
        k = pow(10, j);
        l = pow(8, j);

        sum = sum + ((oct / k) % 10) * l;
    }

    printf("the decimal equivalent of this number is %d", sum);

    return 0;
}