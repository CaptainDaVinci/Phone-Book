#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Phone-Book.h"

static void padding(char *toBePadded);

void displayBook(void)
{
    // if the phone-book is empty.
    if(head == NULL)
    {
        printf("Phone Book is empty!\n");
        return ;
    }

    struct Contacts *curr = head;

    printf("\nNAME\t\tNUMBER\n");

    // iterate through the linked-list and display the contact.
    while(curr != NULL)
    {
        padding(curr->name);
        printf("%s\t %s\n", curr->name, curr->number);
        curr = curr->next;
    }
}

void padding(char toPad[20])
{
    int i;
    int len = 15 - strlen(toPad);
    char padding[15];

    for(i = 0; i < len; i++)
    {
        padding[i] = ' ';
    }
    padding[i] = '\0';

    strcat(toPad, padding);
}
