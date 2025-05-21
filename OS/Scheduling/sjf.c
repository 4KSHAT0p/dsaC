#include <stdio.h>
#include <stdlib.h>
typedef struct PRO
{
    float burstime;
    float arrival_time;
    float wt;
    float tat;
    int id;
} process;

void swap(process *, process *);

int main()
{

    int n;
    printf("enter the number of processes\n");
    scanf("%d", &n);
    float elapsed = 0.00;
    float min;
    int index;
    process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        printf("Enter the arrival time of process %d\n", i + 1);
        scanf("%f", &(p[i].arrival_time));
        printf("Enter the burst time of process %d\n", i + 1);
        scanf("%f", &(p[i].burstime));
    }

    // sorting

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrival_time > p[j + 1].arrival_time)
            {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
    p[0].wt = 0.00; // wt for the first process will be 0
    elapsed += p[0].burstime;
    p[0].tat=elapsed-p[0].arrival_time;
    for (int j = 1; j < n; j++)
    {
        min = (float)INT_MAX;
        for (int i = j; i < n; i++)
        {
            if (i < n)
            {
                if (p[i].arrival_time < elapsed && p[i].burstime < min)
                {
                    min = p[i].burstime;
                    index = i;
                }
                if (i == n - 1)
                {
                    elapsed += p[index].burstime;
                    p[index].wt = elapsed - p[index].arrival_time - p[index].burstime;
                    p[index].tat = elapsed - p[index].arrival_time;
                    if (j != index)
                    {
                        swap(&p[index], &p[j]);
                    }
                }
            }
        }
    }

    printf("Process Analysis\n");
    printf("ID AT          BT       WT       TAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %f %f %f %f\n", p[i].id, p[i].arrival_time, p[i].burstime, p[i].wt, p[i].tat);
    }

    return 0;
}

void swap(process *x, process *y)
{
    process temp = *x;
    *x = *y;
    *y = temp;
}
