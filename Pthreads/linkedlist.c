/* 
File - linkedlist.c
Author - Sarthak Kaingade <sarthakkaingade@yahoo.com>
Description - Program to demonstrate linked lists.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
    char word[20];
    int count;
    struct node *next;
};

struct node* addnode(struct node** head, int count, char word[20]) {
   struct node *current = *head;
   struct node *newNode;
   newNode = malloc(sizeof(struct node));
   strcpy(newNode->word,word);
   newNode->count = count;
   newNode->next = NULL;

   if (current == NULL) {
      *head = newNode;
   }
   else {
      while (current->next != NULL) {
         current = current->next;
      }
      current->next = newNode;
   }
}

void PrintLinkedList(struct node *head) {
    struct node *current = head;

    while (current != NULL) {
        printf("%s\t%d\n", current->word, current->count);
        current = current->next;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)  {
        fprintf(stderr,"%s\n","Invalid number of arguments");
        fprintf(stderr,"%s\n","Usage: mapper FILENAME");
        return 1;
    }

    FILE *fd;
    char c[20], prev_char = '\0';;
    struct node *head;
    head = NULL;
    fd = fopen(argv[1],"rt");
    if (fd == NULL)	{
            printf("\nUnable to open the input file: %s\n",argv[1]);
            return 1;
    }
    while (fscanf(fd, "%s", c) != EOF) {
        if (head == NULL)   {
            prev_char = c[0];
        }
        if ((prev_char != c[0]))    {
            printf("\nDatabase:\n");
            PrintLinkedList(head);
            prev_char = c[0];
        }
        addnode(&head,0,c);
    }
    fclose(fd);
    return 0;
}
