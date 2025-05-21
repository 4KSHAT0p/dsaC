#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[50];
int top = -1;
void push(char);
char pope(void);
int main()
{
  printf("\n\nMAX STRING SIZE IS 50\n\n");
  printf("Enter a string\n");
  while (1)
  {
    char c = getchar();
    push(c);
    if (c == '.')
    {
      break;
    }
  }
  push('\0'); // fundamental property of a string is that it ends with '\0' null character.

while(top!=-1)
{
  printf("%c",pope());
}

  return 0;
}
void push(char x)
{
  if (top < 50)
  {
    top++;
    stack[top] = x;
  }
  else
  {
    printf("STACK OVERFLOW");
    exit(0); // to inhibit for loop from executing after stack overflow
  }
}

char pope(void)
{
  if (top == -1)
  {
    printf("STACK UNDERFLOW");
  }
  else
  {
    top--;
    return stack[top+1];
  }
}