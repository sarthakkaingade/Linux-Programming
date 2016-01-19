/*
File - myprog.c
Author - Sarthak Kaingade <sarthakkaingade@yahoo.com>
Description - Example program to support demostration of exec system call.
*/

#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    printf("Inside myprog: %s %s\n",argv[0],argv[1]);
    return 0;
}
