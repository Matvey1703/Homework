#include <stdio.h>

#include"list.h"

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
};

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

List* create()
{
	return new List;
}


void addToFront(List* list, int value)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ value, nullptr };
		return;
	}
	list->head = new ListElement{ value, list->head->next };
}

void addToBack(List* list, int value)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ value, nullptr };
		return;
	}

	ListElement* help = list->head;

	while (help->next != nullptr)
	{
		help = help->next;
	}
	help->next = new ListElement{ value, nullptr };
}

void displayList(List* list)
{
	if (isEmpty(list))
	{
		printf("empty list\n");
		return;
	}
	ListElement* helpElement = list->head;
	while (helpElement != nullptr)
	{
		printf("%i ", helpElement->value);
		helpElement = helpElement->next;
	}
	printf("\n");
}

void deleteFromFront(List* list)
{
	if (!isEmpty(list))
	{
		ListElement* oldHead = list->head;

		list->head = list->head->next;
		delete oldHead;
	}
}

void deleteList(List* list)
{
	if (!isEmpty(list))
	{
		while (list->head != nullptr)
		{
			ListElement* oldHead = list->head;
			list->head = list->head->next;
			delete oldHead;
		}
	}
	delete list;
}


int listSize(List* list)
{
	int size = 0;
	ListElement* help = list->head;

	while (help != nullptr)
	{
		size++;
		help = help->next;
	}
	return size;
}

bool listCompaisor(List* firstList, List* secondList)
{
	ListElement* firstHelper = firstList->head;
	ListElement* secondHelper = secondList->head;

	while (firstHelper != nullptr || secondHelper != nullptr)
	{
		if (firstHelper->value != secondHelper->value)
		{
			return false;
		}
		if (firstHelper->next == nullptr && secondHelper->next != nullptr)
		{
			return false;
		}
		if (firstHelper->next != nullptr && secondHelper->next == nullptr)
		{
			return false;
		}
		firstHelper = firstHelper->next;
		secondHelper = secondHelper->next;
	}

	return true;
}

bool symmetryCheck(List* list)
{
	List* listFront = create();
	List* lisrBack = create();
	ListElement* help = list->head;
	int size = listSize(list); 
	int mid = size / 2;

	for (int i = 0; i < size; i++)
	{
		if (i = mid && size % 2 > 0)
		{
			help = help->next;
		}
		else
		{
			if (i <= mid - 1)
			{
				addToBack(listFront, help->value);
			}
			if ((i >= size / 2))
			{
				addToFront(lisrBack, help->value);
			}
			help = help->next;
		}
	}

	bool isSymmetric = listCompaisor(listFront, lisrBack);

	deleteList(listFront);
	deleteList(lisrBack);
	return isSymmetric;
}