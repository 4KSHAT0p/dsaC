// C program for the above approach

#include <stdio.h>
#include <windows.h>
#include<conio.h>
#include<stdlib.h>
void gotoxy(int,int,char);
// Driver Code
int main()
{
  
    printf("|  |  |  |\n");
    printf("|  |  |  |\n");
    printf("|  |  |  |\n");
	gotoxy(1,2,'O');
	
	return 0;
}
void gotoxy(int x,int y,char c)
{
COORD l;
	l.X = x;
	l.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), l);
    printf("%c",c);
}