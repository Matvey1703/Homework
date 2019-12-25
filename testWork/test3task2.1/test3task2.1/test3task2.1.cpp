#include <stdio.h>

#include "list.h"

int main()
{
	List* list = create();
	bool run = true;
	int rangeBegin = 0;
	int rangeEnd = 0;
	int size = 0;

	while (run)
	{
		printf("   PHONE BOOK\n"
			"0 - exit\n"
			"1 - fill by rand values\n"
			"2 - revolve list\n"
			"3 - display list\n"
			" select an action...\n");

		
		char selection = getchar();

		while (getchar() != '\n')
		{
		}
		switch (selection)
		{
		case '0':
			run = false;
			break;
		case '1':
			printf("input size: ");
			scanf("%i", &size);
			printf("input diapazon:\n");
			printf("begin:");
			while (getchar() != '\n')
			{
			}
			scanf("%i", &rangeBegin);
			printf("end:");
			while (getchar() != '\n')
			{
			}
			scanf("%i", &rangeEnd);
			fillByRand(list, rangeBegin, rangeEnd, size);
			break;
		case '2':
			list = revolve(list);
			break;
		case '3':
			printf("List:\n");
			displayList(list);
			break;
		}
	}

	deleteList(list);
	return 0;
}
