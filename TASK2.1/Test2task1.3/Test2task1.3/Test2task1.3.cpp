#include <stdio.h>

#include "list.h"

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


void toListFromFile(List* list, FILE* file, int a, int b)
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
		addElement(toNumber(arrayNumber, size), list, a, b);
	}
}


int main()
{
	if (!test())
	{
		printf("error");
		return -1;
	}

	int a = 5;
	int b = 10;
	FILE* f = fopen("f.txt", "r");
	
	List* list = create();

	toListFromFile(list, f, a, b);
	fclose(f);

	FILE* g = fopen("g.txt", "a+");
	writeFromListToFile(g, list);
	fclose(g);

	deleteList(list);
	return 0;
}





