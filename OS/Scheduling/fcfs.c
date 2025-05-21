#include<stdio.h>
#include<stdlib.h>
struct process
{
    int id;
    float at;
    float bt;
    float wt;
    float tat;
};
void swap(struct process*,struct process*);
int main()
{
    int n;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    struct process p1[n];
    int i,j;

    for(i=0; i<n; i++)
    {
        printf("Enter arrival time of process %d\n",i+1);
        scanf("%f",&(p1[i].at));
        printf("Enter burst time of process %d\n",i+1);
        scanf("%f",&(p1[i].bt));
        p1[i].id=i+1;
    }

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(p1[j].at>p1[j+1].at)
            {
                swap(&p1[j],&p1[j+1]);
            }
        }
    }
float elapsed=0.00;
//sort acc. to at
p1[0].wt=0.00;// first process to arrive has 0 waiting time
p1[0].tat=p1[0].bt;
for(i=1;i<n;i++)
{
    p1[i].wt=p1[i-1].bt+elapsed-p1[i].at;
    elapsed+=p1[i-1].bt;
    p1[i].tat=p1[i].bt+p1[i].wt;
}

printf("ID       AT       BT       WT       TAT\n");
for(i=0;i<n;i++)
{
    printf("%d  %f  %f  %f  %f\n",p1[i].id,p1[i].at,p1[i].bt,p1[i].wt,p1[i].tat);
}

    return 0;
}
void swap(struct process* x,struct process* y)
{
    struct process temp=*x;
    *x=*y;
    *y=temp;
}