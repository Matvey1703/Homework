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

bool deleteElement(int value, List* list)
{
	if (isEmpty(list) || value < list->head->value)
	{
		return false;
	}
	if (value == list->head->value)
	{
		ListElement* oldHead = list->head;
		list->head = list->head->next;
		delete oldHead;
	}
	ListElement* prev = nullptr;
	ListElement* next = list->head;
	while (next != nullptr && value > next->value)
	{
		prev = next;
		next = next->next;
	}
	if (next == nullptr || value != next->value)
	{
		return false;
	}
	prev->next = next->next;
	delete next;
	return true;
}

void addElement(int newValue, List* list)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ newValue, nullptr };
		return;
	}
	if (newValue < list->head->value)
	{
		list->head = new ListElement{ newValue, list->head };
		return;
	}
	ListElement* prev = nullptr;
	ListElement* next = list->head;
	while (next != nullptr && newValue >= next->value)
	{
		if (newValue == next->value)
		{
			printf("Element is already in the list\n");
			return;
		}
		prev = next;
		next = next->next;
	}
	prev->next = new ListElement{ newValue, next };
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