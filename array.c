#include <stdio.h>
void print(char string[][100])
{
    string[0][0] = 'G';
    string[1][0] = 'S';
    printf("%s\n%s\n", string, (string+1));
}

int main(int argc, char const *argv[])
{
    char string[2][100] = {{'\0'}, {'\0'}};
    scanf("%s", string[0]);
    scanf("%s", string[1]);
    print(string);
    printf("%s\n", string[0]);
    printf("%s\n", string[1]);
}
