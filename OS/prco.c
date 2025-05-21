#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define buff 5

int filled = 0;
sem_t buffer;
sem_t mutex;
int t[2] = {1, 2}; // id of producer and consumer

void test(int f)
{
    if (f == buff)
    {
        printf("The buffer is full\n");
    }
    else if (f == 0)
    {
        printf("The buffer is empty\n");
    }
}

void *producer(void *num)
{
    while (1)
    {
        //sleep(4);
        sem_wait(&mutex);
        test(filled);
        if (filled < buff)
        {
            filled++;
        }
        int *i = num;
        printf("Producer produces an item\n");
        sem_post(&buffer);
        sem_post(&mutex);
    }
}

void *consumer(void *num)
{
    while (1)
    {
        //sleep(4);
        sem_wait(&mutex);
        test(filled);
        if (filled > 0)
        {
            filled--;
        }
        int *i = num;
        printf("Consumer consumes an item\n");
        sem_wait(&buffer);
        sem_post(&mutex);
    }
}

int main()
{
    sem_init(&mutex, 0, 1);
    sem_init(&buffer, 0, 5);
    pthread_t threads[2];
    pthread_create(&threads[0], NULL, producer, &t[0]);
    pthread_create(&threads[1], NULL, consumer, &t[1]);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    return 0;
}