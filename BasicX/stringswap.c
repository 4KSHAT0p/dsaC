#include<stdio.h>
void swap(char**x,char**y);
int main()
{

char*j="hhhhhhhkkkjkh";
char*h="jjjjjjjdd";
swap(&j,&h);


printf("%s",h);

    return 0;
}
void swap(char**x,char**y)
{
    char*temp=*x;
    *x=*y;
    *y=temp;
}