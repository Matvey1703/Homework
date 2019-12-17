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
		addToBack(list, toNumber(arrayNumber, size));
	}
}


int main()
{
	List* list = create();
	FILE* file = fopen("file.txt", "r");

	toListFromFile(list, file);
	fclose(file);
	printf(symmetryCheck(list) ? "list symmetry" : "list not symmetry");
	
	deleteList(list);
	return 0;
}