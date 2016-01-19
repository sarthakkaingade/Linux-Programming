/*
File - fork.c
Author - Sarthak Kaingade <sarthakkaingade@yahoo.com>
Description - Example program to demostrate fork system call.
*/

#include<stdio.h>
#include<unistd.h>

int main(void)
{
    printf("Before fork.");
    fflush(stdout);
    pid_t pid = fork();
    if (pid < 0)    {
        fprintf(stderr,"%s\n","Unable to create the fork");
        return 1;
    }
    if (pid == 0)   {
        printf("Executed by child.\n");
    } else {
        printf("Executed by Parent.\n");
    }
    return 0;
}
