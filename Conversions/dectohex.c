#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, l, k, dec;
    char arr[100];
    printf("enter a decimal number\n");
    scanf("%d", &dec);

    for (i = 0;; i++)
    {
        if (dec < pow(16, i))
            break;
    }
    printf("the hexadecimal equivalent of this number is ");
    for (j = 0; j < i; j++)
    {
        l = pow(16, j);

        if (((dec / l) % 16) == 1)
        {
            arr[j] = '1';
        }

        else if (((dec / l) % 16) == 2)
        {
            arr[j] = '2';
        }

        else if (((dec / l) % 16) == 3)
        {
            arr[j] = '3';
        }

        else if (((dec / l) % 16) == 4)
        {
            arr[j] = '4';
        }

        else if (((dec / l) % 16) == 5)
        {
            arr[j] = '5';
        }

        else if (((dec / l) % 16) == 6)
        {
            arr[j] = '6';
        }

        else if (((dec / l) % 16) == 7)
        {
            arr[j] = '7';
        }

        else if (((dec / l) % 16) == 8)
        {
            arr[j] = '8';
        }

        else if (((dec / l) % 16) == 9)
        {
            arr[j] = '9';
        }

        else if (((dec / l) % 16) == 10)
        {
            arr[j] = 'A';
        }

        else if (((dec / l) % 16) == 11)
        {
            arr[j] = 'B';
        }

        else if (((dec / l) % 16) == 12)
        {
            arr[j] = 'C';
        }

        else if (((dec / l) % 16) == 13)
        {
            arr[j] = 'D';
        }

        else if (((dec / l) % 16) == 14)
        {
            arr[j] = 'E';
        }

        else
        {
            arr[j] = 'F';
        }
    }

    for (k = i - 1; k >= 0; k--)
    {
        printf("%c", arr[k]);
    }
    return 0;
}