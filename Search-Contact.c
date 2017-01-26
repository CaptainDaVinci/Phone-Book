#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void padding(char *);

void search(char target[])
{
    padding(target);

    if(head == NULL)
    {
        printf("\nPhone Book is empty !\n");
        return ;
    }

    struct Contacts *curr = head;

    while(curr != NULL)
    {
        if(strcmp(curr -> name, target) == 0)
        {
            printf("\nContact Found!\n");
            printf("%s\t\t%s\n", curr -> name, curr -> number);
            return ;
        }

        curr = curr -> next;
    }

    printf("Contact Not Found!");
}
