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

void addElement(int value, List* list, int a, int b)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ value, nullptr };
		return;
	}

	if (value < a)
	{
		if (list->head->value >= a)
		{
			list->head = new ListElement{ value, list->head->next };
			return;
		}
		ListElement* prev = nullptr;
		ListElement* next = list->head;
		while (next != nullptr && next->value < a)
		{
			prev = next;
			next = next->next;
		}
		prev->next = new ListElement{ value, next };
	}
	else if (value >= a && value <= b)
	{
		ListElement* prev = nullptr;
		ListElement* next = list->head;

		while (next != nullptr && next->value <= b)
		{
			prev = next;
			next = next->next;
		}
		prev->next = new ListElement{ value, next };
	}

	else if (value > b)
	{
		ListElement* help = list->head;

		while (help->next != nullptr)
		{
			help = help->next;
		}
		help->next = new ListElement{ value, nullptr };
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

void writeFromListToFile(FILE* file, List* list)
{
	ListElement* help = list->head;

	while (help != nullptr)
	{
		fprintf(file, "%i ", help->value);
		help = help->next;
	}
}

void addToBack(int value, List* list)
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

bool test()
{
	List* list = create();
	List* trueList = create();
	int a = 10;
	int b = 15;


	addElement(7, list, a, b);
	addElement(20, list, a, b);
	addElement(6, list, a, b);
	addElement(12, list, a, b);
	addElement(22, list, a, b);
	addElement(11, list, a, b);
	addElement(15, list, a, b);
	addElement(10, list, a, b);
	addElement(19, list, a, b);

	addToBack(7, trueList);
	addToBack(6, trueList);
	addToBack(12, trueList);
	addToBack(11, trueList);
	addToBack(15, trueList);
	addToBack(10, trueList);
	addToBack(20, trueList);
	addToBack(22, trueList);
	addToBack(19, trueList);

	bool result = listCompaisor(list, trueList);

	deleteList(list);
	deleteList(trueList);

	return result;
}
