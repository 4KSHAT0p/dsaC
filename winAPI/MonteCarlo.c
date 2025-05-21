#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
  int abscissa;      // abscissa of random point generated
  int ordinate;      // ordinate of random point generated
  int in_circle = 0; // number of random points inside the circle of radius side/2
  int in_square = 0; // number of random points inside the square of side = side;
  DWORD dwWritten = 0;
  int side = 8000; // side of square
  int i = 0;

  // area assumed to start from (0,0) to (side,side)

  srand(time(NULL)); // seeding the random number generator

  HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); // using windows api functions to display points at specific coordinates
  if (hout == INVALID_HANDLE_VALUE)
  {
    return EXIT_FAILURE;
  }

  // drawing square

  for (int i = 0; i < side / 500; i++) // dividing by 500 such that is displays on the screen as screen width and height are much less compared to RAND_MAX
  {
    const char *line = "+";
    COORD top = {i, 5};
    COORD left = {0, i + 5};
    COORD bottom = {i, (side / 500) + 5};
    COORD right = {side / 500, i + 5};
    WriteConsoleOutputCharacter(hout, line, 1, top, &dwWritten);
    WriteConsoleOutputCharacter(hout, line, 1, left, &dwWritten);
    WriteConsoleOutputCharacter(hout, line, 1, bottom, &dwWritten);
    WriteConsoleOutputCharacter(hout, line, 1, right, &dwWritten);
  }

  // drawing x and y axes

  while (i != 20)
  {
    COORD y = {68, i + 3};
    COORD pi = {66, i + 3};
    WriteConsoleOutputCharacter(hout, "|", 1, y, &dwWritten);
    if (i + 3 == 13)
    {
      WriteConsoleOutputCharacter(hout, "Pi", 2, pi, &dwWritten);
    }
    i++;
  }
  i = 0;

  while (i != 100)
  {
    COORD x = {i + 68, 22};
    WriteConsoleOutputCharacter(hout, "-", 1, x, &dwWritten);
    i++;
  }
  i = 0;

  while (i != 30000) // 30000 is the number of samples
  {
    abscissa = rand();
    ordinate = rand();
    const char *point = ".";
    COORD c = {abscissa / 500, ordinate / 500}; // dividing by 500 such that it displays on the screen as screen width and height are much less compared to RAND_MAX
    WriteConsoleOutputCharacter(hout, point, 1, c, &dwWritten);
    //Sleep(10);                                                                                                     // we can vary this according to speed of animation we want
    double radius = sqrt(pow((double)abs(abscissa - (side / 2)), 2) - pow((double)abs(ordinate - (side / 2)), 2)); // calculating the radius of circle
    if (abscissa < side && ordinate < side)
    {
      in_square++;
    }
    if (radius < (double)side / 2)
    {
      in_circle++;
    }

    // to draw graph
    COORD coordinate = {70 + (i / 10), (int)((double)4 / ((double)in_square / (double)in_circle)) + 10};
    WriteConsoleOutputCharacter(hout, "*", 1, coordinate, &dwWritten);

    i++;
  }
  system("cls");
  Sleep(100);
  printf("The estimated value of Pi is %lf", (double)4 / ((double)in_square / (double)in_circle));

  return 0;
}