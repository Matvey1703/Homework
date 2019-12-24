#include <stdio.h>

#include "list.h"

bool test()
{
	List* list = create();

	addElement(30, 0, list);
	if (!deleteByPosition(list, 0) || !isEmpty(list))
	{
		deleteList(list);
		return false;
	}

	addElement(6, 0, list);
	addElement(11, 0, list);
	addElement(15, 1, list);
	addElement(17, 3, list);
	addElement(9, 1, list);
	addElement(22, 4, list);
	addElement(3, 5, list);
	addElement(8, 7, list);
	displayList(list);

	List* list1 = create();
	addElement(8, 0, list1);
	addElement(17, 0, list1);
	addElement(3, 0, list1);
	addElement(22, 0, list1);
	addElement(6, 0, list1);
	addElement(15, 0, list1);
	addElement(9, 0, list1);
	addElement(11, 0, list1);
	displayList(list1);

	if (!listComparison(list, list1))
	{
		deleteList(list1);
		deleteList(list);
		return false;
	}

	if (!deleteByPosition(list, 2) || !deleteByPosition(list, 0) || !deleteByPosition(list, 5))
	{
		deleteList(list1);
		deleteList(list);
		return false;
	}
	if (isInList(list, 15) || isInList(list, 11) || isInList(list, 8))
	{
		deleteList(list1);
		deleteList(list);
		return false;
	}

	deleteList(list1);
	deleteList(list);
	return true;
}

int main()
{
	if (!test())
	{
		return -1;
	}

	List* list = create();

	bool run = true;
	int value = 0;
	int position = 0;

	while (run)
	{
		printf("\n0 - exit\n"
			"1 - add element\n"
			"2 - delete element by position\n"
			"3 - display list\n"
			"  select an action...\n");

		const char selection = getchar();
		while (getchar() != '\n')
		{
		}

		switch (selection)
		{
		case '0':
			run = false;
			break;
		case '1':
			printf("input new value: ");
			scanf("%i", &value);
			printf("input new position: ");
			while (getchar() != '\n')
			{
			}
			scanf("%i", &position);
			addElement(value, position, list);
			break;
		case '2':
			printf("input new position: ");
			scanf("%i", &position);
			printf(deleteByPosition(list, position) ? "element succesfully deleted\n" : "no element for deletion\n");
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
