#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void displayBook(void)
{
    if(head == NULL)
    {
        printf("Phone Book is empty!\n");
        return ;
    }

    struct Contacts *curr = head;

    printf("\nNAME\t\tNUMBER\n");
    while(curr != NULL)
    {
        padding(curr -> name);
        printf("%s\t %s\n", curr -> name, curr -> number);
        curr = curr -> next;
    }
}
