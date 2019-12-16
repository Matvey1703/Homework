
#include "list.h"

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
	ListElement* tail = nullptr;
};

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

List* create()
{
	return new List;
}

bool deleteElement(ListElement** elementToDelete, List* list)
{
	if (isEmpty(list) || elementToDelete == nullptr)
	{
		return false;
	}
	if (*elementToDelete == list->head && list->head == list->tail)
	{
		ListElement* oldHead = list->head;
		list->head = nullptr;
		list->tail = nullptr;
		delete oldHead;
		return true;
	}
	if (*elementToDelete == list->head)
	{
		ListElement* oldHead = list->head;
		list->head = list->head->next;
		list->tail->next = list->head;
		delete oldHead;
		return true;
	}
    if (*elementToDelete == list->tail)
	{
		ListElement* oldTail = list->tail;
		ListElement* helpElement = list->head;
		while (helpElement->next != list->tail)
		{
			helpElement = helpElement->next;
		}
		list->tail = helpElement;
		list->tail->next = list->head;
		delete oldTail;
		return true;
	}
	ListElement* helpElement = list->head;
	while (helpElement->next != *elementToDelete)
	{
		helpElement = helpElement->next;
	}
	helpElement->next = helpElement->next->next;
	delete *elementToDelete;
	return true;
}

void addElement(int newValue, List* list)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ newValue, nullptr };
		list->tail = list->head;
		list->head->next = list->tail;
		
	}
	else
	{
		list->head = new ListElement{ newValue, list->head };
		list->tail->next = list->head;
	}
}

void deleteList(List* list)
{
	if (!isEmpty(list))
	{
		while (list->head != list->tail)
		{
			ListElement* oldHead = list->head;
			list->head = list->head->next;
			list->tail->next = list->head;
			delete oldHead;
		}
		delete list->head;
	}
	delete list;
}

ListElement* listHead(List* list)
{
	return list->head;
}

bool listElementsÑomparison(ListElement** element1, ListElement** element2)
{
	return *element1 == *element2;
}

void shiftNext(ListElement** listElement)
{
	*listElement = (*listElement)->next;
}

int top(ListElement** listElement)
{
	return (*listElement)->value;
}

void deleteListElement(ListElement** listElement)
{
	delete* listElement;
}