#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

struct Contacts
{
    char name[20];
    char number[10];
    struct Contacts *next;
};
struct Contacts *head;

void addContact(char newName[], char newNumber[]);
void delete(char target[]);
void load(FILE *book);
void displayBook(void);
void search(char target[]);

#endif
