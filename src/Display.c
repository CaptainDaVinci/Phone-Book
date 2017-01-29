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
        padding(curr -> name);
        printf("%s\t %s\n", curr -> name, curr -> number);
        curr = curr -> next;
    }
}
