#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 8
int main()
{
    int ptime[5][2] = {1, 3,
                       2, 1,
                       3, 2,
                       4, 2,
                       5, 2};

    int queue[BUFFER_SIZE];
    int front = -1;
    int rear = -1;
    void QINSERT(int x)
    {
        if (rear == BUFFER_SIZE - 1)
        {
            printf("QUEUE OVERFLOW\n");
        }
        else
        {
            if (front = -1)
            {
                front = 0; // to signify the start of queue
            }
            rear++;
            queue[rear] = x;
        }
    }
    int QDELETE(void)
    {
        if (front == -1 || front > rear)
        {
            printf("QUEUE UNDERFLOW\n");
        }
        else
        {
            front++;
        }
        return queue[front - 1];
    }
    // AS arrival time is 0 all processes are present in the queue and are waiting to be processed
    // logically we can deduce that waiting time for P1 will be 0 because it was the process which arrived first.
    // when P1 was getting processed P2 was waiting hence, waiting time for P2 will be processing time of P2.
    // while P1 was getting processed other processes were also waiting so processing time of P1 will be added in all other elements
    // we can understand the pattern now!

    // we have to enqueue waiting times for all distinct processes
    // so we will
    for (int i = 0; i < 5; i++)
    {
        QINSERT(ptime[i][1]);
    }
    QINSERT(0); // waiting time for first process is 0
    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += QDELETE();
    }

    printf("The average waiting time will be %f", sum / 5);

    return 0;
}