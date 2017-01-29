void addContact(char newName[], char newNumber[])
{
    // Used to add spaces at the end of each name, so
    // as that output is better formatted.
    padding(newName);

    struct Contacts *curr = head;
    struct Contacts *prev = head;
    struct Contacts *newContact = malloc(sizeof(struct Contacts));

    // copy the name and number given by user to the new node.
    strcpy(newContact -> name, newName);
    strcpy(newContact -> number, newNumber);

    // If the phone-book was already empty.
    if(head == NULL)
    {
        head = newContact;
        newContact -> next = NULL;
        return ;
    }

    // If there exists only a single contact in the list.
    // add that contact alphabetically.
    if(curr -> next == NULL)
    {
        if(strcmp(curr -> name, newName) > 0)
        {
            head = newContact;
            newContact -> next = curr;
        }

        else
        {
            curr -> next = newContact;
            newContact -> next = NULL;
        }

        return ;
    }

    // Adds the contact to the list in such a way so that
    // the list remains sorted.
    while(curr != NULL)
    {
        if(strcmp(curr -> name, newName) > 0)
        {
            if(curr != head)
            {
                prev -> next = newContact;
                newContact -> next = curr;
            }

            else
            {
                head = newContact;
                newContact -> next = curr;
            }

            return ;
        }

        else if(curr -> next == NULL)
        {
            curr -> next = newContact;
            newContact -> next = NULL;
        }

        prev = curr;
        curr = curr -> next;
    }
}
