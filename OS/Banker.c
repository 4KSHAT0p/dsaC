#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#define numR 3 // 3 types of resources
#define numP 5 // shared between 5 processes

int main()
{
    int alloc[numP][numR] = {0, 1, 0, 2, 0, 0, 3, 0, 2, 2, 1, 1, 0, 0, 2};
    int max[numP][numR] = {7, 5, 3, 3, 2, 2, 9, 0, 2, 2, 2, 2, 4, 3, 3};
    int avail[numR] = {3, 3, 2};
    bool finished[numP] = {0, 0, 0, 0, 0};
    int need[numP][numR];
    for (int i = 0; i < numP; i++)
    {
        for (int j = 0; j < numR; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    // need matrix filled
    int count = 0;
    while (1)
    {
        for (int i = 0; i < numP; i++)
        {
            if (!finished[i] && count != numP)
            {
                for (int j = 0; j < numR; j++)
                {
                    if (avail[j] < need[i][j])
                    {
                        count++;
                        break;
                    }
                    else if (j == numR - 1)
                    {
                        count = 0;
                        for (int k = 0; k < numR; k++)
                        {
                            avail[k] += alloc[i][k];
                            alloc[i][k] = 0;
                            need[i][k] = 0;
                            finished[i] = true;
                        }
                        printf("process %d completed\n", i);
                    }
                }
            }
            else if (i == numP - 1)
            {
                goto label;
            }
        }
    }
label:
    for (int i = 0; i < numP; i++)
    {
        if (finished[i] == 0)
        {
            printf("NO SAFE SEQUENCE EXISTS");
            break;
        }
        else
        {
            printf("SAFE SEQUENCE EXISTS");
            break;
        }
    }
    return 0;
}