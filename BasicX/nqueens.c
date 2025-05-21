#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
int main()
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hout == INVALID_HANDLE_VALUE) {
         return EXIT_FAILURE;
    }
    int x = 25, y = 25;
    DWORD dwWritten = 0;
    COORD cursor = {x, y};
    COORD cc={x+5,y+5};
    const char cs[] = "1";
    WriteConsoleOutputCharacter(hout, cs, strlen(cs), cursor, &dwWritten); 
    WriteConsoleOutputCharacter(hout, cs, strlen(cs), cc, &dwWritten);
    //Sleep(5000);
    return 0;
}