
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
