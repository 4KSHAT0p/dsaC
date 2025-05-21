#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *exp = malloc(20);
    printf("enter a valid expression\n");
    scanf("%[^\n]s", exp);
    int len = strlen(exp);
    char stack[len];
    int top = -1;
    int count = 0;

    int isPair(char x)
    {
        if (x == '(' || x == ')')
        {
            return 1;
        }
        else if (x == '{' || x == '}')
        {
            return 2;
        }
        else if (x == '[' || x == ']')
        {
            return 3;
        }
    }
    void push(char x)
    {
        if (top < len)
        {
            top++;
            stack[top] = x;
        }
        else
        {
            printf("\nSTACK OVERFLOW\n");
        }
    }
    void pop(void)
    {
        if (top == -1)
        {
            printf("\nSTACK UNDERFLOW\n");
        }
        else
        {
            top--;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            while (top != -1)
            {
                if (isPair(exp[i]) == isPair(stack[top]))
                {
                   count++;
                }
                else
                {
                    break;
                }
                pop();
            }
        }
    }
    if (count%2!=0)
    {
        printf("BALANCED. MAX STACK SIZE IS %d", count);
    }
    else
    {
        printf("UNBALANCED.");
    }

    return 0;
}