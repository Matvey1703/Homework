#include <stdio.h>

#include"list.h"

struct ListElement
{
	int value;
	int count = 1;
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

void addElement(int newValue, List* list)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ newValue, 1, nullptr };
		return;
	}

	if (newValue < list->head->value)
	{
		list->head = new ListElement{ newValue, 1, list->head };
		return;
	}

	ListElement* prev = nullptr;
	ListElement* next = list->head;

	while (next != nullptr && newValue >= next->value)
	{
		if (newValue == next->value)
		{
			next->count++;
			return;
		}
		prev = next;
		next = next->next;
	}
	prev->next = new ListElement{ newValue, 1, next };
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
		printf("Number: %i Quantity: %i\n", helpElement->value, helpElement->count);
		helpElement = helpElement->next;
	}
	printf("\n");
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

bool checkSort(List* list)
{
	ListElement* helpElement = list->head;

	if (!isEmpty(list))
	{
		while (helpElement->next != nullptr)
		{
			if (helpElement->value > helpElement->next->value)
			{
				return false;
			}
			helpElement = helpElement->next;
		}
	}
	return true;
}

bool isInList(List* list, int number)
{
	ListElement* helpElement = list->head;

	while (helpElement != nullptr)
	{
		if (number == helpElement->value)
		{
			return true;
		}
		helpElement = helpElement->next;
	}
	return false;
}