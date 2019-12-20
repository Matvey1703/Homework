#include <stdio.h>
#include <string.h>

#include "list.h"

const int maxSize = 30;

struct ListElement
{
	char name[maxSize]{};
	char phone[maxSize]{};
	ListElement* next = nullptr;
	ListElement* prev = nullptr;
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

void addElement(char* name, char* phone, List* list)
{
	if (isEmpty(list))
	{
		list->head = new ListElement;
		list->tail = list->head;
		strncpy(list->head->phone, phone, maxSize);
		strncpy(list->head->name, name, maxSize);
		return;
	}
	ListElement* newElement = new ListElement;
	newElement->prev = list->tail;
	list->tail->next = newElement;
	list->tail = newElement;
	strncpy(list->tail->phone, phone, maxSize);
	strncpy(list->tail->name, name, maxSize);
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
		printf("%s - %s\n", helpElement->name, helpElement->phone);
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

ListElement* headPointer(List* list)
{
	return list->head;
}

ListElement* tailPointer(List* list)
{
	return list->tail;
}

bool listComparison(List* list1, List* list2)
{
	ListElement* helper1 = list1->head;
	ListElement* helper2 = list2->head;

	while (helper1 != nullptr && helper2 != nullptr)
	{
		if (strcmp(helper1->name, helper2->name) != 0 || strcmp(helper1->phone, helper2->phone) != 0)
		{
			return false;
		}
		helper1 = helper1->next;
		helper2 = helper2->next;
	}
	return true;
}

ListElement* shiftNext(ListElement* listElement)
{
	return listElement->next;
}

ListElement* shiftPrev(ListElement* listElement)
{
	return listElement->prev;
}

char* fieldPhone(ListElement* listElement)
{
	return listElement->phone;
}

char* fieldName(ListElement* listElement)
{
	return listElement->name;
}

void copyFields(ListElement** element1, ListElement** element2)
{
	strcpy((*element1)->phone, (*element2)->phone);
	strcpy((*element1)->name, (*element2)->name);
}