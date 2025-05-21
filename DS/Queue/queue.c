#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 8
int main()
{

    int queue[MAXSIZE];
    int front=-1;
    int rear=-1;

    void QINSERT(int x)
    {
        if (rear == MAXSIZE - 1)
        {
            printf("QUEUE OVERFLOW\n");
        }
        else
        {
           if (front == -1)
           {
                front = 0; // to signify the start of queue
           }
            rear++;
            queue[rear] = x;
        }
    }
    int QDELETE(void)
    {
        if(front==-1 || front>rear)
        {
            printf("QUEUE UNDERFLOW\n");
        }
        else
        {
        front++;
        return queue[front-1];
        }
    }
    void QDISPLAY(void)
    {
        if(front==-1)
        {
            printf("QUEUE IS EMPTY\n");
        }
        else
        {
            printf("\nQUEUE:\n");
            while(front!=rear+1)
            {
              printf("%d ",QDELETE());
            }
        }   
    }

    QINSERT(1);
    QINSERT(2);
    QINSERT(3);
    QDISPLAY();
    return 0;
}