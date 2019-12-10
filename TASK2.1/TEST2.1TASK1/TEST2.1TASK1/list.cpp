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

void addToFront(int newValue, List* list)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ newValue, nullptr };
		return;
	}
	list->head = new ListElement{ newValue, list->head };
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

void addToBack(int value, List* list)
{
	ListElement* help = list->head;

	if (!isEmpty(list))
	{
		while (help->next != nullptr)
		{
			help = help->next;
		}
		help->next = new ListElement{ value, nullptr };
	}
	else
	{
		list->head = new ListElement{ value, nullptr };
	}
	help = nullptr;
	delete help;
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

int toNumber(int* arrayNumber, int numberSize)
{
	int number = 0;
	int digit = 1;

	for (int i = numberSize - 1; i >= 0; i--)
	{
		number += arrayNumber[i] * digit;
		digit *= 10;
	}
	return number;
}


void toListFromFile(List* list, FILE* file)
{
	while (!feof(file))
	{
		char symbol = ' ';
		int size = 0;
		int arrayNumber[10]{}; 
		while ((symbol = fgetc(file)) != ' ' && !feof(file) && symbol != EOF)
		{
			arrayNumber[size] = symbol - '0';
			size++;
		}
		addToBack(toNumber(arrayNumber, size), list);
	}
}

void listRevol(FILE* file, List* revList)
{
	List* list = create();

	toListFromFile(list, file);
	
	if (isEmpty(list))
	{
		displayList(list);
		delete list;
		delete revList;
		return;
	}
	if (list->head->next == nullptr)
	{
		displayList(list);
		delete list;
		delete revList;
		return;
	}
	ListElement* help = list->head;
	while (help != nullptr)
	{
		addToFront(help->value, revList);
		help = help->next;
	}
	deleteList(list);
	delete help;
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
	delete firstHelper;
	delete secondHelper;
	return true;
}

bool test()
{
	List* revList = create();
	List* trueRevList = create();
	FILE* file = fopen("test.txt", "r");

	for (int i = 1; i <= 13; i++)
	{
		addToFront(i, trueRevList);
	}
	listRevol(file, revList);
	fclose(file);
	bool result = listCompaisor(revList, trueRevList);
	deleteList(revList);
	deleteList(trueRevList);
	return result;
}