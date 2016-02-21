/*
File - sem.h
Description - Example program to demonstrate data sharing between multiple processes. Original code with description - https://computing.llnl.gov/tutorials/pthreads/man/pthread_mutexattr_init.txt
*/
#ifndef SEM_H
#define SEM_H

struct semaphore {
    pthread_mutex_t lock;
    pthread_cond_t nonzero;
    unsigned count;
};
typedef struct semaphore semaphore_t;

semaphore_t *semaphore_create(char *semaphore_name);
semaphore_t *semaphore_open(char *semaphore_name);
void semaphore_post(semaphore_t *semap);
void semaphore_wait(semaphore_t *semap);
void semaphore_close(semaphore_t *semap);

#endif
