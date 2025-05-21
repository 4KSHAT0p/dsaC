#include <stdio.h>

int main()
{
    int arr[8] = {18, 4, 5, 3, 12, 9, 4, 1};
    int n;
    char another = 'Y';
    while (another == 'Y')
    {
        printf("enter the element you want to search\n");
        scanf("%d", &n);

        for (int i = 0; i < 8; i++)
        {
            if (arr[i] == n)
            {
                printf("element is present at the index %d\n", i);
                break;
            }
            else if (i == 7)
            {
                printf("element is not present\n");
            }
        }
        getchar();
        printf("want to search for another element (Y/N) ?\n");
        another = getchar();
    }
    return 0;
}