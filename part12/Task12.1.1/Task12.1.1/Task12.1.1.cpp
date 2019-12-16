#include <stdio.h>
#include <string.h>

#include "kmp.h"

void readFromFile(char* fileName, char* string)
{
	FILE* file = fopen(fileName, "a+");
	int i = 0;
	char symbol = ' ';

	while (!feof(file) && (symbol = fgetc(file)) != EOF)
	{
		string[i++] = symbol;
	}

	fclose(file);
}


bool arrayComparison(int* array1, int* array2, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (array1[i] != array2[i])
		{
			return false;
		}
	}
	return true;
}

bool test()
{
	char fileName[] = "test.txt";
	char subString1[] = "Irina";
	char subString2[] = "interviewer";
	char subString3[] = "Russia";
	char subString4[] = "abbaabbab";
	char string[100] = {};
	int pi[9] = {};
	int truePi[9] = { 0, 0, 0, 1, 1, 2, 3, 4, 2 };

	readFromFile(fileName, string);

	prefixFunction(subString4, pi);
	
	bool prefixFunctionTest = arrayComparison(pi, truePi, 9);

	bool finderTest = finder(subString1, string) == 0 ||
		finder(subString2, string) == 24 ||
		finder(subString3, string) == 39;

	return  prefixFunctionTest && readFromFile;
}

int main()
{
	if (!test())
	{
		printf("Program work incorrectly");
		return -1;
	}

	char fileName[] = "string.txt";
	char string[100] = {};
	char subString[30] = {};

	printf("Input substring: ");
	fgets(subString, 30, stdin);
	subString[strlen(subString) - 1] = '\0';

	readFromFile(fileName, string);

	int position = finder(subString, string);
	printf(position != -1 ? "position of the first occurrence of the substruct in struct is %i" :
		"the substring is not contained in the string", position);

	return 0;
}