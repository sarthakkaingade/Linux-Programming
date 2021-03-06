/*
File - process2.c
Description - Example program to demonstrate data sharing between multiple processes. Original code with description present at https://computing.llnl.gov/tutorials/pthreads/man/pthread_mutexattr_init.txt
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "sem.h"

int main(int argc, char *argv[])
{
    semaphore_t *semap;

    semap = semaphore_open("semaphore");
    if (semap == NULL)
        exit(1);
    printf("Reading from shared file\n");
    semaphore_wait(semap);
    semaphore_close(semap);
    printf("Process 2 exiting\n");

    exit(0);
}
