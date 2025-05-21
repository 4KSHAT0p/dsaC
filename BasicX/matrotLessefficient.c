#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void matrixRotation(int, int, int[5][4], int);
void matrixRotation(int matrix_rows, int matrix_columns, int matrix[5][4], int r)
{
    int min;
    if (matrix_rows < matrix_columns)
    {
        min = matrix_rows;
    }
    else
    {
        min = matrix_columns;
    }
    int dd = min / 2;
    for (int i = 0; i < r; i++)
    {

        for (int j = 0; j < dd; j++)
        {
            int first = matrix[j][j];

            for (int k = j + 1; k < matrix_columns - j; k++)
            {
                matrix[j][k - 1] = matrix[j][k];
            }
            for (int m = j; m < matrix_rows - 1 - j; m++)
            {
                matrix[m][matrix_columns - j - 1] = matrix[m + 1][matrix_columns - j - 1];
            }
            for (int n = j; n < matrix_columns - 1 - j; n++)
            {
                matrix[matrix_rows - j - 1][matrix_columns - n - 1] = matrix[matrix_rows - j - 1][matrix_columns - n - 2];
            }
            for (int p = j; p < matrix_rows - 1 - j; p++)
            {
                matrix[matrix_rows - p - 1][j] = matrix[matrix_rows - p - 2][j];
            }
            matrix[j + 1][j] = first;
        }
    }

    for (int i = 0; i < matrix_rows; i++)
    {
        for (int j = 0; j < matrix_columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{

    int arr[5][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    matrixRotation(5, 4, arr, 1);

    return 0;
}