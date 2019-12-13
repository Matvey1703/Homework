#include "counter.h"

#include "list.h"

int counter(int m, int n)
{
	List* list = create();

	for (int i = n; i >= 1; i--)
	{
		addElement(i, list);
	}

	ListElement* helpElement = nullptr;
	listHead(&helpElement, list);
	
	ListElement* next = nullptr;
	next = helpElement;
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
			return -1;
		}
		shiftNext(&next);
	}

	int result = top(&helpElement);
	deleteList(list);
	return result;
}