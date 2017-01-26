#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Phone-Book.h"

int main(void)
{
    int option;
    char newNumber[10];
    char newName[20];

    FILE *book = fopen("Phone-Book.txt", "r");

    if(book == NULL)
    {
        printf("Unable to open file !\n");
        exit(1);
    }

    load(book);
    sort();
    fclose(book);

    system("clear");

    printf("Welcome to Phone Book\n");
    printf("1. Display contacts\n");
    printf("2. Add contact\n");
    printf("3. Search contact\n");
    printf("4. Delete contact\n");
    printf("5. Exit\n");

    start :
    printf("\nChoose your option : ");
    scanf("%d", &option);

    switch(option)
    {
        case 1: system("clear");
                displayBook();
                break;

        case 2: printf("Name : ");
                scanf("%s", newName);

                printf("Phone Number : ");
                scanf("%s", newNumber);

                addContact(newName, newNumber);
                break;

        case 3: printf("Name : ");
                scanf("%s", newName);

                search(newName);
                break;

        case 4: printf("Name : ");
                scanf("%s", newName);

                delete(newName);
                break;

        case 5: printToBook();
                exit(0);
                break;

        default : printf("Incorrect option!\n");
                  exit(0);
    }

    goto start;
}