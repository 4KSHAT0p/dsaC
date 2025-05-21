#include <stdio.h>
int fact(int);
int main()
{
    printf("%d", fact(8));

    return 0;
}
int fact(int x)
{
    int h;

    h = x * fact(x - 1);

    if (x >= 1)
    {
        return h;
    }

    else
    {
        return 1;
    }
}
