#include <stdio.h>
#include <stdbool.h>
typedef struct process
{
    float at;
    float bt;
    float bt2;
    float wt;
    float tat;
    int id;
    bool complete;
} proc;

void bubbleSort(proc *, int);
int minBurst(proc *, int, int);
void swap(proc *, proc *);

int main(void)
{

    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);

    proc pro[n];
    int k;
    for (k = 0; k < n; k++)
    {
        printf("Enter arrival time of process %d\n", k + 1);
        scanf("%f", &pro[k].at);
        printf("Enter the burst time of this process\n");
        scanf("%f", &pro[k].bt);
        pro[k].bt2 = pro[k].bt;
        pro[k].id = k + 1;
        pro[k].wt = 0.00;
        pro[k].tat = 0.00;
        pro[k].complete = false;
    }
    printf("\n\n\n\n");
    bubbleSort(pro, n);
    float elapsed_time = pro[0].at;
    pro[0].bt -= pro[1].at;
    elapsed_time = pro[1].at;
    printf("P%d gets executed for %f secs\n", pro[0].id, pro[1].at);
    float total_time = elapsed_time;
    for (int i = 0; i < n; i++)
    {
        total_time += pro[i].bt;
    }
    int i = 2;
    while (i <= n - 1)
    {
        if (pro[minBurst(pro, 0, i - 1)].bt > pro[i].at - elapsed_time)
        {
            pro[minBurst(pro, 0, i - 1)].bt -= pro[i].at - elapsed_time;
            printf("P%d gets executed for %f secs\n", pro[minBurst(pro, 0, i - 1)].id, pro[i].at - elapsed_time);
            elapsed_time = pro[i].at;
        }
        else
        {
            elapsed_time += pro[minBurst(pro, 0, i - 1)].bt;
            printf("P%d gets executed for %f secs\n", pro[minBurst(pro, 0, i - 1)].id, pro[minBurst(pro, 0, i - 1)].bt);
            printf("P%d complete\n", pro[minBurst(pro, 0, i - 1)].id);
            pro[minBurst(pro, 0, i - 1)].wt = elapsed_time - pro[minBurst(pro, 0, i - 1)].bt2 - pro[minBurst(pro, 0, i - 1)].at;
            pro[minBurst(pro, 0, i - 1)].tat = elapsed_time - pro[minBurst(pro, 0, i - 1)].at;
            pro[minBurst(pro, 0, i - 1)].bt = 0;
            pro[minBurst(pro, 0, i - 1)].complete = true;
            continue;
        }
        i++;
    }

    while (minBurst(pro, 0, n - 1) != 0) // total_time != elapsed_time
    {
        elapsed_time += pro[minBurst(pro, 0, n - 1)].bt;
        printf("P%d gets executed for %f secs\n", pro[minBurst(pro, 0, n - 1)].id, pro[minBurst(pro, 0, n - 1)].bt);
        printf("P%d complete\n", pro[minBurst(pro, 0, n - 1)].id);
        pro[minBurst(pro, 0, n - 1)].wt = elapsed_time - pro[minBurst(pro, 0, n - 1)].bt2 - pro[minBurst(pro, 0, n - 1)].at;
        pro[minBurst(pro, 0, n - 1)].tat = elapsed_time - pro[minBurst(pro, 0, n - 1)].at;
        pro[minBurst(pro, 0, n - 1)].bt = 0;
        pro[minBurst(pro, 0, n - 1)].complete = true;
    }

    printf("Process Analysis\n");
    printf("ID AT          BT       WT       TAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %f %f %f %f\n", pro[i].id, pro[i].at, pro[i].bt2, pro[i].wt, pro[i].tat);
    }

    return 0;
}

void swap(proc *x, proc *y)
{
    proc temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(proc *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].at > arr[j + 1].at)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int minBurst(proc *arr, int low, int high)
{
    int mini = low;
    for (int i = low; i <= high; i++)
    {
        if (!arr[i].complete && !arr[mini].complete)
        {
            if (arr[i].bt < arr[mini].bt)
            {
                mini = i;
            }
        }
        else if (arr[mini].complete && mini < high)
        {
            int j = mini + 1;
            while (j < high)
            {
                if (arr[j].complete)
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            mini = j;
        }
    }
    if (!arr[mini].complete)
    {
        return mini;
    }
    return 0;
}