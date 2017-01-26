
struct Contacts
{
    char name[20];
    char number[10];
    struct Contacts *next;
};

struct Contacts *head = NULL;

#include "padding.c"
#include "Display.c"
#include "Add-Contact.c"
#include "Delete-Contact.c"
#include "Search-Contact.c"
#include "Load-Phone-Book.c"
#include "printToBook.c"
