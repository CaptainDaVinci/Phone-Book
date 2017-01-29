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
