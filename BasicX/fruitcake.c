#include <stdio.h>
#include <stdlib.h>

int main()
{

    char arr[9][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 't', 0, 'f', 'c', 0, 'r', 'i', 'e', 'k', 'u', 'a'};
    char *p = "fruitcake";
    int howManyin(char x)
    {
        int count = 0;
        for (int i = 0; i < 9; i++)
        {
            if (arr[i][x - 65] != 0)
            {
                count++;
            }
        }
        return count;
    }
    void move(char x, char y)
    {
        if (x >= 65 && x <= 67 && y >= 65 && y <= 67 && x != y)
        {
            for (int i = 0; i < 9; i++)
            {
                if (arr[i][x - 65] != 0)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (arr[j][y - 65] != 0 && j > 0)
                        {
                            arr[j - 1][y - 65] = arr[i][x - 65];
                            arr[i][x - 65] = 0;
                            printf("moving %c from %c to %c\n", arr[j - 1][y - 65], x, y);
                            break;
                        }
                        else if (j == 8)
                        {
                            arr[8][y - 65] = arr[i][x - 65];
                            arr[i][x - 65] = 0;
                            printf("moving %c from %c to %c\n", arr[8][y - 65], x, y);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
    char whereIs(char x)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == x)
                {

                    return 65 + j;
                    goto label;
                }
            }
        }
    label:
    }
    for (int i = 0; i <= howManyin('C'); i++) // emptying the tower which has least number of elements will be used to make fruitcake
    {
        move('C', 'B');
    }
    void solve(int n)
    {

        char f = whereIs(p[n]);
        for (int i = 0; i < 9; i++)
        {
            if (arr[i][f - 65] != 0 && arr[i][f - 65] != p[n] && f == 'A')
            {
                move(f, 'B');
            }
            else if (arr[i][f - 65] != 0 && arr[i][f - 65] != p[n] && f == 'B')
            {
                move(f, 'A');
            }
            else if (arr[i][f - 65] == p[n])
            {
                move(f, 'C');
                break;
            }
        }
        if (n < 8)
        {
            solve(n + 1);
        }
    }
    solve(0);
    printf("\n\nA B C\n");
    printf("%d %d %c\n", arr[0][0], arr[0][1], arr[0][2]);
    printf("%d %d %c\n", arr[1][0], arr[1][1], arr[1][2]);
    printf("%d %d %c\n", arr[2][0], arr[2][1], arr[2][2]);
    printf("%d %d %c\n", arr[3][0], arr[3][1], arr[3][2]);
    printf("%d %d %c\n", arr[4][0], arr[4][1], arr[4][2]);
    printf("%d %d %c\n", arr[5][0], arr[5][1], arr[5][2]);
    printf("%d %d %c\n", arr[6][0], arr[6][1], arr[6][2]);
    printf("%d %d %c\n", arr[7][0], arr[7][1], arr[7][2]);
    printf("%d %d %c\n", arr[8][0], arr[8][1], arr[8][2]);
    return 0;
}