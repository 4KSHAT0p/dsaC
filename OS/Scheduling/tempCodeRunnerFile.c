#include <stdio.h>
typedef struct process
{
    float at;
    float bt;
    float wt;
    float tat;
    int id;
} P;

void bubbleSort(P *, int);
void swap(P *, P *);
float hrrn(P);
void sorthrrn(P *, int, int); //sort according to response ratios

int main()
{
    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);

    P pro[n];
    int k;
    for (k = 0; k < n; k++)
    {
        printf("Enter arrival time of process %d\n", k + 1);
        scanf("%f", &pro[k].at);
        printf("Enter the burst time of this process\n");
        scanf("%f", &pro[k].bt);
        pro[k].id = k + 1;
    }

    float elapsed = 0.00;

    bubbleSort(pro, n);

    float total_time = 0.00;

    for (int i = 0; i < n; i++)
    {
        total_time += pro[i].bt;
    }
    pro[0].wt = 0.00;
    elapsed += pro[0].bt;
    int i = 1, j = 1;
    while (elapsed != total_time)
    {

        if (i == n || pro[i].at > elapsed)
        {
            if (i == n)
            {
                sorthrrn(pro, j, i);
            }
            else
            {
                sorthrrn(pro, j, i - 1);
            }
            elapsed += pro[j].bt;
            j++;
            i = j;
        }
        else
        {
            pro[i].wt = elapsed - pro[i].at;
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        pro[i].tat=pro[i].wt + pro[i].bt;
    }

    printf("ID      AT      BT      WT      TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d %f %f %f %f\n",pro[i].id,pro[i].at,pro[i].bt,pro[i].wt,pro[i].tat);
    }

    return 0;
}

void swap(P *x, P *y)
{
    P temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(P *arr, int n)
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
void sorthrrn(P *arr, int low, int high)
{
    if (low < high)
    {
        int i, j;
        for (i = low; i < high - 1; i++)
        {
            for (j = low; j < high + 1 - i; j++)
            {
                if (hrrn(arr[j]) < hrrn(arr[j + 1]))
                {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }
    else
    {

        return;
    }
}
float hrrn(P x)
{
    return ((x.wt + x.bt) / x.bt);
}