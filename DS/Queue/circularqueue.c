#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
int main()
{
    int cqueue[MAXSIZE];
    int front = -1;
    int rear = -1;

    void CQINSERT(int x)
    {
        if ((rear == MAXSIZE - 1 && front == 0) || rear + 1 == front)
        {
            printf("CQUEUE OVERFLOW\n%d can't be enqueued\n", x);
        }
        else if (rear == MAXSIZE - 1 && front > 0)
        {
            rear = 0;
            cqueue[rear] = x;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            cqueue[rear] = x;
        }
    }
    void CQDELETE(void)
    {
        if (front < MAXSIZE - 1)
        {
            front++;
        }
        else
        {
            front = 0;
        }
    }
    void CQDISPLAY(void)
    {
        if (front < rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", cqueue[i]);
            }
        }
        else
        {
            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", cqueue[i]);
            }
            for (int i = front; i < MAXSIZE; i++)
            {
                printf("%d ", cqueue[i]);
            }
        }
    }
    CQINSERT(15);
    CQINSERT(36);
    CQINSERT(28);
    CQINSERT(10);
    CQINSERT(23);
    CQDISPLAY();
    printf("\n");
    CQDELETE();
    CQDISPLAY();
    printf("\n");
    CQINSERT(12);
    CQDISPLAY();

    return 0;
}