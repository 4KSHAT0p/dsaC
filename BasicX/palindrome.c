#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{

    int count = 0;
    char *string = malloc(100);
    printf("Enter a string\n");
    scanf("%s", string);
    string = realloc(string, strlen(string));
    for (int i = 0; i < strlen(string); i++)
    {

        if (string[i] == string[strlen(string) - 1 - i])
        {
            count++;
        }
    }

    if (count == strlen(string))
    {

        printf("This string is a palindrome");
    }

    else
    {
        printf("This string is not a palindrome");
    }

    return 0;
}