#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int top = -1;
    char *string = calloc(100,sizeof(char));
    printf("Enter a valid infix expression without blank spaces\n");
    scanf("%s", string);
    string = realloc(string, strlen(string));
    int l = strlen(string);
    char stack[l]; // making an character array of size equal to length of string
    char *prefix=calloc(l,sizeof(char));
    char *postfix=calloc(l,sizeof(char));
    void push(char x)
    {
        if (top < l-1)
        {
            top++;
            stack[top] = x;
        }
        else
        {
            printf("\nSTACK OVERFLOW\n");
        }
    }

    char pop(void)
    {
        if (top == -1)
        {
            printf("\nSTACK UNDERFLOW\n");
            return '\0';
        }
        else
        {
            top--;
            return stack[top + 1];
        }
    }
    int prec(char x) // function to check compare precedence of operators
    {
        if (x == '*' || x == '/')
        {
            return 3;
        }
        else if (x == '+' || x == '-')
        {
            return 2;
        }
        else if (x == '^')
        {
            return 4;
        }
    }

    printf("\nPROCESSING......\n\n");
int j=0;
    for (int i = 0; i < l; i++)
    {
        if (string[i] >= 48 && string[i] <= 57)
        {
            //printf("%c", string[i]);
            postfix[j++]=string[i];
        }
        else if (string[i] == '*' || string[i] == '/' || string[i] == '+' || string[i] == '-' || string[i] == '^')
        {
            if (top == -1 || prec(string[i]) > prec(stack[top]))
            {
                push(string[i]);
            }
            else
            {
                while (stack[top] != '(')
                {
                    //printf("%c", pop());
                    postfix[j++]=pop();
                    if (top == -1)
                    {
                        break;
                    }
                }
                push(string[i]);
            }
        }
        else if (string[i] == '(')
        {
            push(string[i]);
        }
        else if (string[i] == ')')
        {
            while (stack[top] != '(')
            {
               // printf("%c", pop());
               postfix[j++]=pop();
            }
            pop();
        }
        else
        {
            printf("\n%c is a INVALID OPERATOR/OPERAND\n", string[i]);
            break;
        }
    }

    while(top!=-1)
    {
        postfix[j++]=pop();
    }
    printf("%s",postfix);
    free(string);
    free(postfix);
    free(prefix);
    return 0;
}