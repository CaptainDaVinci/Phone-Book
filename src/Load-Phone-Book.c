void swap(struct Contacts *, struct Contacts *);
void sort(void);

void load(FILE *book)
{
    char temp[2];
    char name[20], number[10];

    // To check if the phone-book is empty or not.
    if(fgets(temp, 2, book) == NULL)
    {
        printf("Phone-Book is empty!\n");
        exit(0);
    }

    rewind(book);

    struct Contacts *curr;
    struct Contacts *newContact = malloc(sizeof( *newContact));
    curr = newContact;
    head = newContact;

    // scan the file and copy the name and number in each line
    // to a new node in linked-list.
    while(fscanf(book, "%s\t%s\n", name, number) != EOF)
    {
        strcpy(curr -> name, name);
        strcpy(curr -> number, number);

        struct Contacts *newContact = malloc(sizeof( *newContact));
        curr -> next = newContact;
        curr = newContact;
    }
    curr -> next = NULL;
}

void sort(void)
{
    struct Contacts *curr = head;
    struct Contacts *prev = head;

    // iterate through the linked-list.
    // sorts the elements in the Linked-List alphabetically
    // through selection sort.
    while(curr != NULL)
    {
        prev = head;
        while(prev != NULL)
        {
            if(strcmp(prev -> name, curr -> name) > 0)
            {
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
