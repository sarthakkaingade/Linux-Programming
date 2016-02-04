/*
File - pthreads.c
Author - Sarthak Kaingade <sarthakkaingade@yahoo.com>
Description - Example program to demonstarte Pthreads POSIX API.
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 3

void *hello(void *thread_no)
{
    printf("Thread %ld created\n",(long)thread_no);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int ret;
    printf("Thread creation demonstration.\n");
    for (long i = 0; i < NUM_THREADS; i++)   {
        ret = pthread_create(&threads[i],NULL,hello,(void *)i);
        if (ret)    {
            fprintf(stderr,"%s %ld\n","Failed to create thread",i);
            return 1;
        }
    }
    pthread_exit(NULL);

    return 0;
}
