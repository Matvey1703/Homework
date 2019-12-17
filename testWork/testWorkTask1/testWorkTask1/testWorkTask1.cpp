#include <stdio.h>

#include "list.h"

bool test()
{
	List* list = create();

	for (int i = 1; i <= 13; i += 2)
	{
		addElement(i, list);
	}

	for (int i = 14; i >= 2; i -= 2)
	{
		addElement(i, list);
	}

	for (int i = 1; i <= 14; i++)
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

	deleteList(list);
	return true;
}


int main()
{
	if (!test())
	{
		printf("program works inccorrectly");
		return -1;
	}

	List* list = create();
	int number = -1;

	printf("Input numbers: \n");

	while (number != 0)
	{
		scanf("%i", &number);
		if (number != 0)
		{
			addElement(number, list);
		}
	}

	displayList(list);

	deleteList(list);
	return 0;
}