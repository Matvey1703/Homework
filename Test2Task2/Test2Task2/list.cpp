#include <stdio.h>
#include <string.h>

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

void addElement(int value, int position, List* list)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ value, nullptr, nullptr };
		list->size++;
		return;
	}

	if (position == 0)
	{
		ListElement* newElement = new ListElement{ value, list->head, nullptr };
		list->head->prev= newElement;
		list->head = newElement;
		list->size++;
		return;
	}

	if (position >= list->size)
	{
		ListElement* helpElement = list->head;

		while (helpElement->next != nullptr)
		{
			helpElement = helpElement->next;
		}
		helpElement->next = new ListElement{ value, nullptr, helpElement };
		list->size++;
		return;
	}

	ListElement* helpElement = list->head;
	for (int i = 0; i < position; i++)
	{
		helpElement = helpElement->next;
	}
	ListElement* newElement = new ListElement{ value, helpElement, helpElement->prev };
	helpElement->prev->next = newElement;
	helpElement->prev = newElement;
	list->size++;
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

bool deleteByPosition(List* list, int position)
{
	if (isEmpty(list) || position >= list->size)
	{
		return false;
	}

	if (position == 0)
	{
		ListElement* elementToDelete = list->head;
		list->head = list->head->next;
		if (list->size == 1)
		{
			delete elementToDelete;
			list->size--;
			return true;
		}
		list->head->prev = nullptr;
		delete elementToDelete;
		list->size--;
		return true;
	}
	ListElement* helpElement = list->head;
	for (int i = 0; i < position - 1; i++)
	{
		helpElement = helpElement->next;
	}
	ListElement* elementToDelete = helpElement->next;
	helpElement->next = helpElement->next->next;
	if (elementToDelete->next != nullptr)
	{
		elementToDelete->next->prev = helpElement;
	}
	delete elementToDelete;
	list->size--;
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