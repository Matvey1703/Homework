#include <stdio.h>

#include "note.h"
#include "noteFunctions.h"
#include "test.h"
#include <string.h>

int main()
{
	if (!test())
	{
		printf("program work incorrectly\n");
		return -1;
	}

	Note book[100];
	bool run = true;
	FILE* file = fopen("phoneBook.txt", "a+");

	if (file == nullptr)
	{
		printf("File not found");
		return -1;
	}

	int size = loadBook(book, file);
	char nameForSearching[30]{};
	char phoneForSearching[30]{};

	fclose(file);

	while (run)
	{
		printf("   PHONE BOOK\n"
			"0 - exit\n"
			"1 - add contact\n"
			"2 - display contacts\n"
			"3 - search contact by name\n"
			"4 - search contact by phone\n"
			"5 - save changes\n"
		    " select an action...\n");

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
			printf("Input name: ");
			fgets(book[size].name, 30, stdin);
			book[size].name[strlen(book[size].name) - 1] = '\0';
			//gets_s(book[size].name, 30);
			printf("Input phone number: ");
			//fgets(book[size].phone, 30, stdin);
			gets_s(book[size].phone, 30);
			size++;
			break;
		case '2':
			printf("\nContacts in your phone book: \n");
			displayPhoneBook(book, size);
			printf("\n");
			break;
		case '3':
		{
			printf("Input name:\n");
			gets_s(nameForSearching, 30);
			int indexSearchNumber = searchByName(book, nameForSearching, size);
			printf((indexSearchNumber > 0) ? "%s's phone number is %s\n" : "Contact not found\n", 
				   nameForSearching, book[indexSearchNumber].phone);
			break;
		}
		case '4':
		{
			printf("Input phone number:\n");
			gets_s(phoneForSearching, 30);
			int indexSearchName = searchByPhone(book, phoneForSearching, size);
			printf((indexSearchName > 0) ? "Phone number %s belongs to %s\n" : "Contact not found\n", 
				   phoneForSearching, book[indexSearchName].name);
			break;
		}
		case '5':
			FILE* file = fopen("phoneBook.txt", "w");
			saveChanges(book, size, file);
			fclose(file);
			printf("Changes saved\n");
			break;
		}
	}
	return 0;
}