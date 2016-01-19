/*
File - pipe.c
Author - Sarthak Kaingade <sarthakkaingade@yahoo.com>
Description - Example program to demostrate pipe system call.
*/

#include<stdio.h>
#include<unistd.h>

int main(void)
{
    int n, fd[2];
    char buffer[50];
    printf("Before fork.");
    fflush(stdout);
    pipe(fd);
    pid_t pid = fork();
    if (pid < 0)    {
        fprintf(stderr,"%s\n","Unable to create the fork");
        return 1;
    }
    if (pid == 0)   {
        printf("Executed by child.\n");
        close(fd[1]);
        n = read(fd[0],buffer,50);
        write(STDOUT_FILENO,buffer,n);
    } else {
        printf("Executed by Parent.\n");
        close(fd[0]);
        write(fd[1],"Data passed to child\n",21);
    }
    return 0;
}
