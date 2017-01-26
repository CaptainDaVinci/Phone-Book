#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Contacts
{
    char name[20];
    char number[10];
    struct Contacts *next;
};

struct Contacts *head = NULL;

void displayBook(void);
void addContact(char *, char *);
void search(char *);
void delete(char *);
void padding(char *);
void load(FILE *);
void sort(void);
void swap(struct Contacts *, struct Contacts *);
void printToBook(void);

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

void load(FILE *book)
{
    char temp[2];
    char name[20], number[10];

    if(fgets(temp, 2, book) == NULL)
    {
        printf("Phone-Book is empty!\n");
        exit(0);
    }

    rewind(book);

    struct Contacts *curr;
    struct Contacts *newContact = malloc(sizeof(struct Contacts));
    curr = newContact;
    head = newContact;

    while(fscanf(book, "%s\t%s\n", name, number) != EOF)
    {
        strcpy(curr -> name, name);
        strcpy(curr -> number, number);

        struct Contacts *newContact = malloc(sizeof(struct Contacts));
        curr -> next = newContact;
        curr = newContact;
    }
    curr -> next = NULL;
}

void sort(void)
{
    struct Contacts *curr = head;
    struct Contacts *prev = head;

    while(curr != NULL)
    {
        prev = head;
        while(prev != NULL)
        {
            if(strcmp(prev -> name, curr -> name) > 0)
            {
                printf("%s, %s\n", prev -> name, curr -> name);
                swap(prev, curr);
            }
            prev = prev -> next;
        }

        curr = curr -> next;
    }
}

void swap(struct Contacts *prev, struct Contacts *curr)
{
    char tempName[20];
    char tempNumber[10];

    strcpy(tempName, prev -> name);
    strcpy(tempNumber, prev -> number);
    strcpy(prev -> name, curr -> name);
    strcpy(prev -> number, curr -> number);
    strcpy(curr -> name, tempName);
    strcpy(curr -> number, tempNumber);
}

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

void addContact(char newName[], char newNumber[])
{
    padding(newName);

    struct Contacts *curr = head;
    struct Contacts *prev = head;
    struct Contacts *newContact = malloc(sizeof(struct Contacts));

    strcpy(newContact -> name, newName);
    strcpy(newContact -> number, newNumber);

    if(head == NULL)
    {
        head = newContact;
        newContact -> next = NULL;
        return ;
    }

    if(curr -> next == NULL)
    {
        if(strcmp(curr -> name, newName) > 0)
        {
            head = newContact;
            newContact -> next = curr;
        }

        else
        {
            curr -> next = newContact;
            newContact -> next = NULL;
        }

        return ;
    }

    while(curr != NULL)
    {
        if(strcmp(curr -> name, newName) > 0)
        {
            if(curr != head)
            {
                prev -> next = newContact;
                newContact -> next = curr;
            }

            else
            {
                head = newContact;
                newContact -> next = curr;
            }

            return ;
        }

        else if(curr -> next == NULL)
        {
            curr -> next = newContact;
            newContact -> next = NULL;
        }

        prev = curr;
        curr = curr -> next;
    }
}

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

void delete(char target[])
{
    if(head == NULL)
    {
        printf("Phone Book is empty !\n");
        return;
    }

    struct Contacts *curr = head;
    struct Contacts *prev = head;

    padding(target);

    while(curr != NULL)
    {
        if(strcmp(curr -> name, target) == 0)
        {
            if(head == curr)
            {
                head = curr -> next;
            }

            prev -> next = curr -> next;
            printf("\nContact deleted successfully\n");
            free(curr);
            return;
        }

        prev = curr;
        curr = curr -> next;
    }

    printf("Contact Not Found!\n");
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

void printToBook(void)
{
    FILE *book = fopen("Phone-Book.txt", "w");
    if(book == NULL)
    {
        printf("Unable to open file\n");
        exit(1);
    }

    struct Contacts *curr = head;


    while(curr != NULL)
    {
        fprintf(book, "%s\t%s\n", curr -> name, curr -> number);
        curr = curr -> next;
    }
}
