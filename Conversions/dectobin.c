// decimal to binary

#include <stdio.h>
#include <math.h>

void PrintBin(int);
void PrintBin(int a)
{
    int i;
    for (i = 0;; i++)
    {
        if (a < pow(2, i))
            break;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        if ((a & (1 << j)) != 0)
        {
            printf("1");
        }
        else
            printf("0");
    }
}

int main()
{

    // long int dec, arr[100], i, j, k, l, sum = 0;

    // printf("enter a decimal number\n");
    // scanf("%d", &dec);

    // for (k = 0;; k++)
    // {
    //     if (dec < pow(2, k))
    //         break;
    // }

    // for (i = 0, j = 0, l = 0; i <= 99, j <= k, l <= k; i++, j++, l++)
    // {

    //     arr[99] = pow(2, j);

    //     arr[98] = pow(10, l);

    //     arr[i] = (dec / arr[99]) % 2;

    //     sum = sum + (arr[i] * arr[98]);
    // }

    // printf("the binary equivalent of %d is %d", dec, sum);
    PrintBin(45);
    return 0;
}