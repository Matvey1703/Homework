#include <string.h>

#include "kmp.h"

void prefixFunction(char* string, int* pi)
{
	const int stringSize = strlen(string);
	int maxPrefix = 0; // Maximum length of matching prefix and postfix.
	int stringIndex = 1;

	pi[0] = 0;

	while (stringIndex < stringSize)
	{
		if (string[stringIndex] == string[maxPrefix])
		{
			pi[stringIndex] = maxPrefix + 1;
			stringIndex++;
			maxPrefix++;
		}
		else
		{
			if (maxPrefix == 0)
			{
				pi[stringIndex] = 0;
				stringIndex++;
			}
			else
			{
				maxPrefix = pi[maxPrefix - 1];
			}
		}
	}
}

int finder(char* subString, char* string)
{
	int subStringSize = strlen(subString);
	int stringSize = strlen(string);
	int stringIndex = 0;
	int subStringIndex = 0;
	int* pi = new int[subStringSize] {};

	prefixFunction(subString, pi);

	while (stringIndex <= stringSize - subStringSize)
	{
		while (string[stringIndex] == subString[subStringIndex])
		{
			if (subStringIndex == subStringSize - 1)
			{
				delete[] pi;
				return stringIndex - subStringSize + 1;
			}
			stringIndex++;
			subStringIndex++;
		}
		if (subStringIndex == 0)
		{
			stringIndex++;
		}
		else
		{
			subStringIndex = pi[subStringIndex - 1];
		}
	}

	delete[] pi;
	return -1;
}