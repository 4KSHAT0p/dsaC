#include <stdio.h>
int main()
{
  int m, n, counth = 0, countv = 0, countd = 0;
  printf("enter dimensions of array\n");
  scanf("%d %d", &m, &n);

  char arr[n][m];
  printf("enter elements\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      getchar();
      scanf("%c", &arr[i][j]);
    }
  }
  for (int i = 0; i < n; i++) // horizontal
  {
    for (int j = 0; j < m; j++)
    {
      if ((arr[i][j] == 's') && (arr[i][j + 1] == 'a') && (arr[i][j + 2] == 'b') && (arr[i][j + 3] == 'a'))
      {
        counth++;
      }
    }
  }
  for (int i = 0; i < n; i++) // vertical
  {
    for (int j = 0; j < m; j++)
    {
      if ((arr[j][i] == 's') && (arr[j + 1][i] == 'a') && (arr[j + 2][i] == 'b') && (arr[j + 3][i] == 'a'))
      {
        countv++;
      }
    }
  }
  if (m > n)
  {
    for (int i = 0; i < n; i++)
    {
      if ((arr[i][i] == 's') && (arr[i + 1][i + 1] == 'a') && (arr[i + 2][i + 2] == 'b') && (arr[i + 3][i + 3] == 'a'))
      {
        countd++;
      }
    }
  }
  else
  {
    for (int i = 0; i < m; i++)
    {
      if ((arr[i][i] == 's') && (arr[i + 1][i + 1] == 'a') && (arr[i + 2][i + 2] == 'b') && (arr[i + 3][i + 3] == 'a'))
      {
        countd++;
      }
    }
  }

  printf("\nthe number of times the word 'saba' appeared horizontally from left to right is %d\n", counth);
  printf("the number of times the word 'saba' appeared vertically from up to down is %d\n", countv);
  printf("the number of times the word 'saba' appeared diagonally from up to down is %d\n", countd);

  return 0;
}