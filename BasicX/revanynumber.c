#include <stdio.h>
#include <math.h>

int main()
{
    long long int num, rev, i, m, um, it;

    printf("enter a number\n");
    scanf("%d", &num);

    for (m = 0;; m++)
    {
        if (num < pow(10, m))
            break;
    }

    rev = 0;

    for (i = 0; i <= m - 1, m > 0; i++)
    {
        it = pow(10, m - 1);

        um = num / pow(10, i);

        rev = ((um % 10) * it) + rev;

        m--;
    }

    printf("The reverse of this number is %d", rev);
}