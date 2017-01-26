
void addContact(char newName[], char newNumber[])
{
    padding(newName);

    struct Contacts *curr = head;
    struct Contacts *prev = head;
    struct Contacts *newContact = malloc(sizeof(struct Contacts));

    strcpy(newContact -> name, newName);
    strcpy(newContact -> number, newNumber);

    if(head == NULL)
    {
        head = newContact;
        newContact -> next = NULL;
        return ;
    }

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
