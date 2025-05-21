#include <stdio.h>
#include <math.h>

int main()
{

    long int dec, i, j, k, arr[100];
    printf("enter a decimal number\n");
    scanf("%d", &dec);

    for (i = 0;; i++)
    {
        if (dec < pow(8, i))
            break;
    }

    printf("the octal equivalent of this number is ");

    for (j = 0; j < i; j++)
    {
        arr[99] = pow(8, j);

        arr[j] = (dec / arr[99]) % 8;
    }

    for (k = i - 1; k >= 0; k--)
    {
        printf("%d", arr[k]);
    }

    return 0;
}