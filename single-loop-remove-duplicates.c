#include <stdio.h>

void removeDuplicates(char *str)
{
    short int sChar = sizeof(char *), replacing = 0;
    int cc = 0;
    // Marking and removing
    for (char *c = str, *d = (str + 1), *r; !(*c == '\0' && *d == '\0');)
    {
        cc++;
        if (replacing)
        {
            if (*r == '\0')
            {
                replacing = 0;
                continue;
            }
            *r = *(r + 1);
            r++;
            continue;
        }
        if (*d == '\0')
        {
            c++;
            d = (c + 1);
        }
        if (*c == *d)
        {
            r = d;
            replacing = 1;
            continue;
        }
        d++;
    }
}
int main()
{
    char inString[100][100] = {{'\0'}};
    int number = 0, count = 0;
    scanf("%d%*c", &number);
    for (count = 0; count < number; count++)
    {
        scanf("%[^\n]%*c", inString[count]);
    }
    for (count = 0; count < number; count++)
    {
        removeDuplicates(inString[count]);
        printf("%s\n", inString[count]);
    }
    return 0;
}
