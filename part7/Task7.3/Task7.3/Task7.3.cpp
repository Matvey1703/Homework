#include <stdio.h>

#include "list.h"
#include "sort.h"

List* load(char* fileName)
{
	List* list = create();
	FILE* file = fopen(fileName, "r");

	while (!feof(file))
	{
		char symbol = ' ';
		int i = 0;
		char name[30]{};
		char phone[30]{};

		while (!feof(file) && (symbol = fgetc(file)) != '-')
		{
			if (symbol != ' ')
			{
				name[i] = symbol;
				i++;
			}
		}
		i = 0;
		while (!feof(file) && (symbol = fgetc(file)) != '\n')
		{
			if (symbol != ' ' && symbol != EOF && symbol != '\0')
			{
				phone[i] = symbol;
				i++;
			}
		}
		if (name[0] != '\0')
		{
			addElement(name, phone, list);
		}
	}

	fclose(file);
	return list;
}

bool test()
{
	char fileName[] = "test.txt";
	char fileName1[] = "byName.txt";
	char fileName2[] = "byPhone.txt";
	List* listForSortingByName = load(fileName);
	List* listForSortingByPhone = load(fileName);
	List* listSortedByName = load(fileName1);
	List* listSortedByPhone = load(fileName2);

	ListElement* head1 = headPointer(listForSortingByName);
	ListElement* tail1 = tailPointer(listForSortingByName);
	mergeSort(listForSortingByName, head1, tail1, false);

	ListElement* head2 = headPointer(listForSortingByPhone);
	ListElement* tail2 = tailPointer(listForSortingByPhone);
	mergeSort(listForSortingByPhone, head2, tail2, true);

	bool result = listComparison(listForSortingByName, listSortedByName)
		&& listComparison(listForSortingByPhone, listSortedByPhone);
	
	deleteList(listForSortingByName);
	deleteList(listForSortingByPhone);
	deleteList(listSortedByName);
	deleteList(listSortedByPhone);

	return result;
}

int main()
{
	if (!test())
	{
		printf("program work incorrectly\n");
		return -1;
	}

	char fileName[] = "file.txt";
	List* list = load(fileName);
	bool run = true;

	while (run)
	{
		printf("   PHONE BOOK\n"
			"0 - exit\n"
			"1 - display contacts\n"
			"2 - sotr by name\n"
			"3 - sort by phone\n"
			" select an action...\n");

		ListElement* head = headPointer(list);
		ListElement* tail = tailPointer(list);

		char selection = getchar();

		while (getchar() != '\n')
		{
		}
		switch (selection)
		{
		case '0':
			run = false;
			break;
		case '1':
			printf("Contacts:\n");
			displayList(list);
			break;
		case '2':
			mergeSort(list, head, tail, false);
			break;
		case '3':
			mergeSort(list, head, tail, true);
			break;
		}
	}
	
	deleteList(list);
	return 0;
}