#include "Phone-Book.h"

void addContact(char newName[], char newNumber[])
{
    // Used to add spaces at the end of each name, so
    // as that output is better formatted.
    padding(newName);

    struct Contacts *curr = head;
    struct Contacts *prev = head;
    struct Contacts *newContact = malloc(sizeof( *newContact));

    // copy the name and number given by user to the new node.
    strcpy(newContact->name, newName);
    strcpy(newContact->number, newNumber);

    // If the phone-book was already empty.
    if(head == NULL)
    {
        head = newContact;
        newContact->next = NULL;
        return ;
    }

    // If there exists only a single contact in the list.
    // add that contact alphabetically.
    if(curr->next == NULL)
    {
        if(strcmp(curr->name, newName) > 0)
        {
            head = newContact;
            newContact->next = curr;
        }

        else
        {
            curr->next = newContact;
            newContact->next = NULL;
        }

        return ;
    }

    // Adds the contact to the list in such a way so that
    // the list remains sorted.
    while(curr != NULL)
    {
        if(strcmp(curr->name, newName) > 0)
        {
            if(curr != head)
            {
                prev->next = newContact;
                newContact->next = curr;
            }

            else
            {
                head = newContact;
                newContact->next = curr;
            }

            return ;
        }

        else if(curr->next == NULL)
        {
            curr->next = newContact;
            newContact->next = NULL;
        }

        prev = curr;
        curr = curr->next;
    }
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

    // Adds spaces to the end of the given name.
    padding(target);

    // Iterates through the list, to find the target name. If found, free that
    // Node.
    while(curr != NULL)
    {
        if(strcmp(curr->name, target) == 0)
        {
            if(head == curr)
            {
                head = curr->next;
            }

            prev->next = curr->next;
            printf("\nContact deleted successfully\n");
            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("Contact Not Found!\n");
}

// To display phonebook
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

// To search for a contact by name.
void search(char target[])
{
    // Adds spaces at the end of the target name, so as to match
    // with the names in the list.
    padding(target);

    if(head == NULL)
    {
        printf("\nPhone Book is empty !\n");
        return ;
    }

    struct Contacts *curr = head;

    // Iterate through the list and compare each node's name field
    // with that of the target, if found display its data, else move on.
    // If no such name is found, exit from the loop.
    while(curr != NULL)
    {
        if(strcmp(curr->name, target) == 0)
        {
            printf("\nContact Found!\n");
            printf("%s\t\t%s\n", curr->name, curr->number);
            return ;
        }

        curr = curr->next;
    }

    printf("Contact Not Found!");
}
