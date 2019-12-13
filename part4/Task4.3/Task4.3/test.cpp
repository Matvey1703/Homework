#include "note.h"
#include "noteFunctions.h"
#include "test.h"

#include <string.h>
#include <stdio.h>

bool isSimilarTest()
{
	char string1[] = { "Irina Shihman" };
	char string2[] = { "Irina Shihman" };
	char string3[] = { "Saint Petersburg" };
	char string4[] = { "Saint Petersbur" };

	return isSimilar(string1, string2) && !isSimilar(string1, string3) && !isSimilar(string3, string4);
}

bool searchByPhoneTest(Note* book, int size)
{
	char phoneNumber1[30] = { "12345678" };
	char phoneNumber2[30] = { "89812345678" };

	return searchByPhone(book, phoneNumber1, size) == -1 && searchByPhone(book, phoneNumber2, size) == 1;
}

bool searchByNameTest(Note* book, int size)
{
	char name1[30] = { "Genadiy" };
	char name2[30] = { "Irina" };

	return searchByName(book, name1, size) == -1 && searchByName(book, name2, size) == 1;
}

bool noteCompaisor(Note* book1, int size1, Note* book2, int size2)
{
	if (size1 != size2)
	{
		return false;
	}
	for (int i = 0; i < size1; i++)
	{
		if (!isSimilar(book1[i].name, book2[i].name) || !isSimilar(book1[i].phone, book2[i].phone))
		{
			return false;
		}
	}
	return true;
}

bool test()
{
	if (!isSimilarTest())
	{
		return false;
	}

	FILE* file = fopen("test.txt", "a+");
	Note book[10];
	int size = 3;
	Note bookFromFile[10];
	int sizeBookFromFile = loadBook(bookFromFile, file);

	fclose(file);

	strncpy(book[0].name, "Fedor", 30);
	strncpy(book[0].phone, "123456", 30);
	strncpy(book[1].name, "Irina", 30);
	strncpy(book[1].phone, "89812345678", 30);
	strncpy(book[2].name, "Gena", 30);
	strncpy(book[2].phone, "87654321", 30);

	if (!noteCompaisor(book, size, bookFromFile, sizeBookFromFile))
	{
		return false;
	}

	strncpy(bookFromFile[sizeBookFromFile].name, "Anna", 30);
	strncpy(bookFromFile[sizeBookFromFile].phone, "1703812", 30);
	sizeBookFromFile++;

	strncpy(book[size].name, "Anna", 30);
	strncpy(book[size].phone, "1703812", 30);
	size++;

	file = fopen("test2.txt", "w");
	saveChanges(book, sizeBookFromFile, file);
	fclose(file);

	if (!noteCompaisor(book, size, bookFromFile, sizeBookFromFile))
	{
		return false;
	}

	return searchByNameTest(book, size) && searchByPhoneTest(book, size);
}