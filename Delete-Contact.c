
void delete(char target[])
{
    if(head == NULL)
    {
        printf("Phone Book is empty !\n");
        return;
    }

    struct Contacts *curr = head;
    struct Contacts *prev = head;

    padding(target);

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
