#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

struct ListElement
{
	int value;
	ListElement* next = nullptr;
	ListElement* prev = nullptr;
};

struct List
{
	ListElement* head = nullptr;
	int size = 0;
};

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

List* create()
{
	return new List;
}

void addElementToFront(int value, List* list)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ value, nullptr, nullptr };
		list->size++;
		return;
	}
	ListElement* newElement = new ListElement{ value, list->head, nullptr };
	list->head->prev = newElement;
	list->head = newElement;
	list->size++;
	return;
}
void addElementToBack(int value, List* list)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ value, nullptr, nullptr };
		list->size++;
		return;
	}
	ListElement* helpElement = list->head;

	while (helpElement->next != nullptr)
	{
		helpElement = helpElement->next;
	}
	helpElement->next = new ListElement{ value, nullptr, helpElement };
	list->size++;
	return;
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

bool listComparison(List* list1, List* list2)
{
	if (list1->size != list2->size)
	{
		return false;
	}

	ListElement* helper1 = list1->head;
	ListElement* helper2 = list2->head;

	while (helper1 != nullptr && helper2 != nullptr)
	{
		if (helper1->value != helper2->value)
		{
			return false;
		}
		helper1 = helper1->next;
		helper2 = helper2->next;
	}
	return true;
}

List* revolve(List* list)
{
	List* bufferList = create();

	ListElement* helper = list->head;
	while (helper != nullptr)
	{
		addElementToFront(helper->value, bufferList);
		helper = helper->next;
	}
	deleteList(list);
	return bufferList;
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

int rndFromRange(int rangeBegin = 5, int rangeEnd = 15)
{
	return rand() % (rangeEnd - rangeBegin + 1) + rangeBegin;
}

void fillByRand(List* list, int rangeBegin, int rangeEnd, int size)
{
	for (int i = 0; i < size; i++)
	{
		addElementToBack(rndFromRange(rangeBegin, rangeEnd), list);
	}
}