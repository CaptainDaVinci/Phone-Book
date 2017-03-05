/*
 *  Title    : Phone-Book
 *  Author   : CaptainDaVinci
 *  Date     : 29-01-2017
 *
 *  Following is a basic, phone book implementation in C.
 *  It uses Linked-List to store all the data and then prints
 *  them in the file "Phone-Book.txt"
 *
 *  It is capable of sorting, adding and deleting contacts
 *  given to it.
 *
 */
#include "Phone-Book.h"

void saveChanges(void);

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

    // used to load the data from the phone-book into linked-list.
    load(book);
    fclose(book);


    printf("Welcome to Phone Book\n");
     while(1)
     {
         printf("\n1. Display contacts\n");
         printf("2. Add contact\n");
         printf("3. Search contact\n");
         printf("4. Delete contact\n");
         printf("5. Exit\n");

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

             case 5: printf("Changes Saved!\n");
                     saveChanges();
                     exit(0);
                     break;

             default : printf("Changes not saved !\nIncorrect option!\n");
                       exit(0);
         }
    }
}

// The various changes which are made to the list are saved and the file
// Phone-Book.txt is overwritten.
void saveChanges(void)
{
    FILE *book = fopen("Phone-Book.txt", "w");

    if(book == NULL)
    {
        printf("Unable to open file\n");
        exit(1);
    }

    struct Contacts *curr = head;
    rewind(book);

    while(curr->next != NULL)
    {
        fprintf(book, "%s\t%s\n", curr->name, curr->number);
        curr = curr->next;
    }
    fprintf(book, "%s\t%s", curr->name, curr->number);

    fclose(book);
}
