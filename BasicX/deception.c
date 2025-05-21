#include <stdio.h>
int find(int[], int, int);
int main()
{
    int n;
    printf("enter the dimensions of the array\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("the smallest missing integer in this array is %d", find(arr, 0, n - 1));

    return 0;
}
int find(int x[], int s, int e)
{
    if (s > e)
        return e + 1;

    if (s != x[s])
        return s + 2;

    int m = (s + e) / 2;

    if (x[m] == m)
        return find(x, m + 1, e);

    return find(x, s, m);
}