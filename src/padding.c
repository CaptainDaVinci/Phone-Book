
// Adds white spaces to the end of a given string
// Upto 15 Characters.

void padding(char toPad[20])
{
    int i;
    int len = 15 - strlen(toPad);
    char padding[15];

    for(i = 0; i < len; i++)
    {
        padding[i] = ' ';
    }
    padding[i] = '\0';

    strcat(toPad, padding);
}
