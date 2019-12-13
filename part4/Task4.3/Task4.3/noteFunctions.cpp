#include <stdio.h>

#include "note.h"
#include "noteFunctions.h"

void displayPhoneBook(Note* book, int size)
{
	int i = 0;

	while (i < size)
	{
		printf("%s * %s\n", book[i].name, book[i].phone);
		i++;
	}
}

bool isSimilar(char* firstString, char* secondString)
{
	int i = 0;

	while (firstString[i] != '\0' || secondString[i] != '\0')
	{
		if (firstString[i] != secondString[i])
		{
			return false;
		}
		i++;
	}
	return true;
}

void saveChanges(Note* book, int size, FILE* file)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%s * %s\n", book[i].name, book[i].phone);
	}
}

int loadBook(Note* book, FILE* file)
{
	int size = -1;

	while (!feof(file))
	{
		size++;
		char symbol = ' ';
		int i = 0;

		while (!feof(file) && (symbol = fgetc(file)) != '*')
		{
			if (symbol != ' ')
			{
				book[size].name[i] = symbol;
				i++;
			}
		}
		i = 0;
		while (!feof(file) && (symbol = fgetc(file)) != '\n')
		{
			if (symbol != ' ' && symbol != '*' && symbol != EOF)
			{
				book[size].phone[i] = symbol;
				i++;
			}
		}
	}
	return size;
}

int searchByName(Note* book, char* name, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (isSimilar(book[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

int searchByPhone(Note* book, char* phone, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (isSimilar(book[i].phone, phone))
		{
			return i;
		}
	}
	return -1;
}