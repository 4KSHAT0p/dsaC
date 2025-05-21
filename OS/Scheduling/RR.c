#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct process
{
    int id;
    float at;
    float bt;
    float wt;
    float tat;
};
#define tq (float)3

void swap(struct process *, struct process *);
int main()
{

    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    struct process p1[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time of process %d\n", i + 1);
        scanf("%f", &(p1[i].at));
        printf("Enter burst time of process %d\n", i + 1);
        scanf("%f", &(p1[i].bt));
        p1[i].id = i + 1;
        p1[i].wt = 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p1[j].at > p1[j + 1].at)
            {
                swap(&p1[j], &p1[j + 1]);
            }
        }
    }

    float elapsed = 0.00;
    int i = 0;
    int count = 0;
    while (count < n)
    {
        if (p1[i % n].bt > 0)
        {
            if (p1[i % n].at <= elapsed)
            {
                p1[i].wt = elapsed - p1[i % n].at;
                if (p1[i % n].bt <= tq)
                {
                    elapsed += p1[i % n].bt;
                    printf("Process %d executed for %f secs\n", p1[i % n].id, p1[i % n].bt);
                    printf("Process %d completed\n", p1[i % n].id, p1[i % n].id);
                    p1[i % n].bt = 0;
                    count++;
                }
                else
                {
                    printf("Process %d executed for %f secs\n", p1[i % n].id, tq);
                    p1[i % n].bt -= tq;
                    elapsed += tq;
                }
            }
            else
            {
                p1[i % n].wt = p1[i % n].at - elapsed;
            }
        }
        i++;
    }

    return 0;
}
void swap(struct process *x, struct process *y)
{
    struct process temp = *x;
    *x = *y;
    *y = temp;
}