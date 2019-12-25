#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isMMGroup(char* string)
{
	bool run = true;
	int i = 0;
	int state = 0;

	while (run)
	{
		switch (state)
		{
		case 0:
			if (isdigit(string[i]))
			{
				state = 1;
			}
			else
			{
				return false;
			}
			break;
		case 1:
			if (isdigit(string[i]))
			{
				state = 2;
			}
			
			else
			{
				return false;
			}
			break;
		case 2:
			if (string[i] == 'M' || string[i] == 'B' || string[i] == 'S')
			{
				state = 3;
			}
			else
			{
				return false;
			}
			break;
		case 3:
			if (string[i] == '1')
			{
				state = 4;
			}
			else if (isdigit(string[i]) && string[i] != 0)
			{
				state = 5;
			}
			else
			{
				return false;
			}
			break;
		case 4:
			if (string[i] == 0)
			{
				state = 5;
			}
			else if (string[i] == '-')
			{
				state = 6;
			}
			else
			{
				return false;
			}
			break;
		case 5:
			if (string[i] == '-')
			{
			state = 6;
			}
			else
			{
				return false;
			}
			break;
		case 6:
			if (string[i] == 'm')
			{
				state = 7;
			}
			else
			{
				return false;
			}
			break;
		case 7:
			if (string[i] == 'm')
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		i++;
	}
}

int main()
{
	char string[30]{};

	printf("Input string: ");
	fgets(string, 30, stdin);
	string[strlen(string) - 1] = '\0';

	printf(isMMGroup(string) ? "is mm group" : "not mm group");
	return 0;
}