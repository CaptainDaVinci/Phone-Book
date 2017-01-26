
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
