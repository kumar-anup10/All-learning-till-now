#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, writeblock;
int data = 0, rcount = 0;

void *reader(void *arg)
{
    int f = *(int *)arg;
    free(arg);

    sem_wait(&mutex);
    rcount++;
    if (rcount == 1)
        sem_wait(&writeblock);
    sem_post(&mutex);

    printf("Data read by the reader %d is %d\n", f, data);
    sleep(1);

    sem_wait(&mutex);
    rcount--;
    if (rcount == 0)
        sem_post(&writeblock);
    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg)
{
    int f = *(int *)arg;
    free(arg);

    sem_wait(&writeblock);
    data++;
    printf("Data written by the writer %d is %d\n", f, data);
    sleep(1);
    sem_post(&writeblock);

    return NULL;
}

int main()
{
    pthread_t rtid[3], wtid[3];
    sem_init(&mutex, 0, 1);
    sem_init(&writeblock, 0, 1);

    for (int i = 0; i < 3; i++)
    {
        int *rid = malloc(sizeof(int));
        int *wid = malloc(sizeof(int));
        *rid = i;
        *wid = i;
        pthread_create(&wtid[i], NULL, writer, wid);
        pthread_create(&rtid[i], NULL, reader, rid);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(wtid[i], NULL);
        pthread_join(rtid[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&writeblock);

    return 0;
}