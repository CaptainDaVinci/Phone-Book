#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

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

struct Contacts *head;

static void padding(char toPad[20])
{
    int i;
    int len = 15 - strlen(toPad);
    char padding[15];

    for (i = 0; i < len; i++)
    {
        padding[i] = ' ';
    }
    padding[i] = '\0';

    strcat(toPad, padding);
}

void addContact(char newName[], char newNumber[]);
void delete (char target[]);
void load(FILE *book);
void displayBook(void);
void search(char target[]);

#endif
