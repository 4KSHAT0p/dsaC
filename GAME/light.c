#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
void scanvaldisp(int, int, int, int, char[3][3]);
void disparr(int, int, int, int, char);
int main(void)
{
    int i, j[4] = {0, 0, 0, 0};
    char arr[3][3];
    char name[10];
    printf("enter your name\n");
    gets(name);
    printf("%s, press enter to compete against me\n", name);
    if (getch() == 13)
    {

        while (1)
        {
            if (getch() == 224)
            {
                switch (getch())
                {
                case 72:
                    printf("up pressed\n");
                    j[0]++;
                    system("cls");
                    disparr(j[0], j[1], j[2], j[3], '*');
                    break;
                case 80:
                    printf("down pressed\n");
                    j[1]++;
                    system("cls");
                    disparr(j[0], j[1], j[2], j[3], '*');
                    break;
                case 75:
                    printf("left pressed\n");
                    j[2]++;
                    system("cls");
                    disparr(j[0], j[1], j[2], j[3], '*');
                    break;
                case 77:
                    printf("right pressed\n");
                    j[3]++;
                    system("cls");
                    disparr(j[0], j[1], j[2], j[3], '*');
                    break;
                }
            }
            else if (getch() == 13)
            {

                

            }
            else
            {
                printf("ABRUPT VALUE INPUTTED");
            }
        }
    }
    else
    {
        printf("YOU'RE A MF");
    }
    return 0;
}

void scanvaldisp(int w, int x, int y, int z, char a[3][3])
{
    w = w % 3;
    x = x % 3;
    y = y % 3;
    z = z % 3;
    int g = abs(w + x); // sum of ups and downs
    int h = abs(y + z); // sum of rights and lefts
    scanf("%c", &a[g][h]);
    system("cls");
    disparr(w, x, y, z, a[g][h]);
}
void disparr(int w, int x, int y, int z, char k)
{
    w = w % 3;
    x = x % 3;
    y = y % 3;
    z = z % 3;
    int g = abs(w + x);
    int h = abs(y + z);

    if (g == 0 && h == 0)
    {
        printf("|%c| | |\n", k);
        printf("| | | |\n");
        printf("| | | |\n");
    }
    if (g == 0 && h == 1)
    {
        printf("| |%c| |\n", k);
        printf("| | | |\n");
        printf("| | | |\n");
    }
    if (g == 0 && h == 2)
    {
        printf("| | |%c|\n", k);
        printf("| | | |\n");
        printf("| | | |\n");
    }
    if (g == 1 && h == 0)
    {
        printf("| | | |\n");
        printf("|%c| | |\n", k);
        printf("| | | |\n");
    }
    if (g == 1 && h == 1)
    {
        printf("| | | |\n");
        printf("| |%c| |\n", k);
        printf("| | | |\n");
    }
    if (g == 1 && h == 2)
    {
        printf("| | | |\n");
        printf("| | |%c|\n", k);
        printf("| | | |\n");
    }
    if (g == 2 && h == 0)
    {
        printf("| | | |\n");
        printf("| | | |\n");
        printf("|%c| | |\n", k);
    }
    if (g == 2 && h == 1)
    {
        printf("| | | |\n");
        printf("| | | |\n");
        printf("| |%c| |\n", k);
    }
    if (g == 2 && h == 2)
    {
        printf("| | | |\n");
        printf("| | | |\n");
        printf("| | |%c|\n", k);
    }
}
