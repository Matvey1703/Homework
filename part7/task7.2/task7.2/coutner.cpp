#include "counter.h"

#include "list.h"

int counter(int m, int n)
{
	if (n == 0 || m == 0)
	{
		return 0;
	}

	List* list = create();

	for (int i = n; i >= 1; i--)
	{
		addElement(i, list);
	}

	ListElement* helpElement = listHead(list);
	
	ListElement* next = helpElement;
	shiftNext(&next);

	while (!listElements—omparison(&next, &helpElement))
	{
		for (int i = 1; i < m; ++i)
		{
			shiftNext(&helpElement);
			shiftNext(&next);
		}
		ListElement* elementToDelete = helpElement;
		shiftNext(&helpElement);
		next = helpElement;
		if (!deleteElement(&elementToDelete, list))
		{
			deleteList(list);
			return -1;
		}
		shiftNext(&next);
	}

	int result = top(&helpElement);
	deleteList(list);
	return result;
}