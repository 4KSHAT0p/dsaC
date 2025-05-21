#include <stdio.h>
#include <string.h>
int main()
{
	int i;
	char arr[100];

	printf("Enter a statement\n");

	gets(arr);

	for (i = 0; i < strlen(arr); i++)
	{

		if (arr[i] == ' ')
		{
			arr[i] = ' ';
		}

		else if (arr[i] >= 97 && arr[i] <= 109)
		{
			arr[i] += 13;
		}

		else if (arr[i] >= 110 && arr[i] <= 122)
		{
			arr[i] -= 13;
		}

		
		printf("%c", arr[i]);
	}

	return 0;
}
