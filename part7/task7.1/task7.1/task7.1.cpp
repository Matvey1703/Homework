#include "list.h"

#include <stdio.h>

bool test()
{
	List* list = create();

	for (int i = 1; i <= 13; i++)
	{
		addElement(i, list);
	}

	for (int i = 1; i <= 13; i++)
	{
		if (!isInList(list, i))
		{
			deleteList(list);
			return false;
		}
	}

	if (!checkSort(list))
	{
		deleteList(list);
		return false;
	}

	if (!deleteElement(5, list) || deleteElement(17, list))
	{
		deleteList(list);
		return false;
	}

	if (!addElement(5, list) || addElement(13, list))
	{
		deleteList(list);
		return false;
	}

	deleteList(list);
	return true;
}

int main()
{
	if (!test())
	{
		printf("program works incorrectly");
		return -1;
	}

	List* list = create();
	bool run = true;
	int value = 0;

	while (run)
	{
		printf("0 - exit\n"
			"1 - add element\n"
			"2 - delete element\n"
			"3 - display list\n"
			"  select an action...\n");
		const char selection = getchar();
		switch (selection)
		{
		case '0':
			run = false;
			break;
		case '1':
			printf("input new value: ");
			scanf("%i", &value);
			if (!addElement(value, list))
			{
				printf("Element is already in the list\n");
			}
			break;
		case '2':
			printf("input value to delete: ");
			scanf("%i", &value);
			printf(deleteElement(value, list) ? "element %i is successfully deleted\n" : 
				                                "no element for deletion\n", value);
			break;
		case '3':
			displayList(list);
			break;
		default:
			break;
		}
	}

	deleteList(list);
	return 0;
}