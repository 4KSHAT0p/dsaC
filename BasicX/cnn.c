//convolutional neural network
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char c;
    int m, n;
    printf("enter dimensions of image(mxn)\n");
    scanf("%d%d", &m, &n);
    int img[m][n];
    for (int *ptr = &img[0][0]; ptr <= &img[m - 1][n - 1]; ptr++)
    {
        printf("enter an element\n");
        scanf("%d", ptr);
    }
    int ver[3][3] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
    int hor[3][3] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
    int pimg[m - 2][n - 2];
    int imgprocessing(int x[m][n], char y, int z, int w)
    {
        int sum = 0;
        if (y == 'v')
        {
            for (int i = z; i < 3 + z; i++)
            {
                signed int m = 1;
                for (int j = w; j < 3 + w; j++)
                {
                    sum += x[i][j] * m;
                    m--;
                }
            }
        }
        else if (y == 'h')
        {
            signed int m = 1;
            for (int i = z; i < 3 + z; i++)
            {

                for (int j = w; j < 3 + w; j++)
                {
                    sum += x[i][j] * m;
                }
                m--;
            }
        }
        return sum;
    }
    while (1)
    {
        getchar();
        printf("Enter 'V' for vertical edge detection OR 'H' for horizontal edge detection\n");
        scanf("%c", &c);

        if (c == 'V')
        {
            for (int i = 0; i < m - 2; i++)
            {
                for (int j = 0; j < n - 2; j++)
                {
                    pimg[i][j] = imgprocessing(img, 'v', i, j);
                }
            }
            for (int i = 0; i < m - 2; i++)
            {
                for (int j = 0; j < n - 2; j++)
                {
                    printf("%d ", pimg[i][j]);
                }
                printf("\n");
            }
        }
        else if (c == 'H')
        {
            for (int i = 0; i < m - 2; i++)
            {
                for (int j = 0; j < n - 2; j++)
                {
                    pimg[i][j] = imgprocessing(img, 'h', i, j);
                }
            }
            for (int i = 0; i < m - 2; i++)
            {
                for (int j = 0; j < n - 2; j++)
                {
                    printf("%d ", pimg[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("invalid input\nprogram ended successfully");
            exit(1);
        }
    }
    return 0;
}
