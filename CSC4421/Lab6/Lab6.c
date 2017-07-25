#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *subtract();

void *divide();

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int x = 19530;

main()
{
    int rc1, rc2;
    pthread_t thread1, thread2;
    /* Create independent threads each of which will execute functionC */
    int itCounter = 1;
    printf("x = %d\n", x);
    while (x != 5)
    {
        printf("\nITERATION %d\n", itCounter);
        if ((rc1 = pthread_create(&thread1, NULL, subtract, NULL)))
        {
            printf("Thread creation failed: %d\n", rc1);
        }
        pthread_join(thread1, NULL);
        if ((rc2 = pthread_create(&thread2, NULL, divide, NULL)))
        {
            printf("Thread creation failed: %d\n", rc2);
        }
        pthread_join(thread2, NULL);
        itCounter++;
    }
    return (0);
}
void *subtract()
{
    pthread_mutex_lock(&mutex1);
    x = x - 5;
    printf("Thread 1: x = %d\n", x);
    pthread_mutex_unlock(&mutex1);
}

void *divide()
{
    pthread_mutex_lock(&mutex1);
    x = x / 5;
    printf("Thread 2: x = %d\n", x);
    pthread_mutex_unlock(&mutex1);
}