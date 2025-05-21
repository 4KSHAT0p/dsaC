#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdbool.h>
#define N 5
#define thinking 2
#define hungry 1
#define eating 0

int S[N];                      // state of philosopher
int phil[N] = {0, 1, 2, 3, 4}; // id

sem_t mutex;
sem_t forks[N];

void test(int PhID)
{
    if (S[PhID] == hungry && S[(PhID + 1) % N] != eating && S[(PhID + 4) % N] != eating)
    {
        S[PhID] = eating;
        sleep(2);
        printf("philosopher %d takes fork %d and %d, and he starts eating\n", PhID, (PhID + 1) % N, (PhID + 4) % N);
        sem_post(&forks[PhID]); // signal that it's free now
    }
}

void take_fork(int PhID)
{
    sem_wait(&mutex); // so that any other process won't be able to take any fork simultaneously
    S[PhID] = hungry;

    printf("philosopher %d is hungry\n", PhID);
    test(PhID); // eat if neighbours are not eating
    sem_post(&mutex); // release lock
    sem_wait(&forks[PhID]); // a fork acquired by PhID
    sleep(1);
}

void put_fork(int PhID)
{
    sem_wait(&mutex); // so that any other thread cant interfere
    S[PhID] = thinking;

    printf("philosopher %d puts down fork %d and %d and starts thinking\n", PhID, (PhID + 1) % N, (PhID % 4) % N);
    // now forks are available so check if neighbours want to eat or not
    test((PhID + 1) % N);
    test((PhID + 4) % N);

    sem_post(&mutex); // release lock
}

void *philosopher(void *num)
{
    while (true)
    {
        int *i = num;
        sleep(1);
        take_fork(*i);
        sleep(1);
        put_fork(*i);
    }
}

int main()
{
    pthread_t thread_id[N]; // threads

    sem_init(&mutex, 0, 1); // initialize mutex lock

    for (int i = 0; i < N; i++)

        sem_init(&forks[i], 0, 0);

    for (int i = 0; i < N; i++)
    {
        // create philosopher processes
        pthread_create(&thread_id[i], NULL,
                       philosopher, &phil[i]);

        printf("Philosopher %d is thinking\n", i + 1);
    }

    for (int i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);

    return 0;
}