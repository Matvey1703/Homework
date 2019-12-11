#include <stdio.h>
#include <string.h>

#include "parser.h"

bool stringCompaisor(char* str1, char* str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
		i++;
	}
	return str1[i] == '\0' && str2[i] == '\0';
}

bool programTest()
{
	const int size = 20;
	char* infix1 = new char[size] {};
	char* postfix1 = new char[size] {};
	char* parsInfix1 = new char[size] {};
	char* infix2 = new char[size] {};
	char* postfix2 = new char[size] {};
	char* parsInfix2 = new char[size] {};

	strncpy(infix1, "1+2*3+4", size);
	strncpy(postfix1, "1 2 3 * + 4 + ", size);
	parser(infix1, parsInfix1);
	strncpy(infix2, "(3 + 3) * 6 - 12", size);
	strncpy(postfix2, "3 3 + 6 * 12 - ", size);
	parser(infix2, parsInfix2);
	if (!stringCompaisor(postfix1, parsInfix1))
	{
		delete[] postfix1;
		delete[] infix1;
		delete[] parsInfix1;
		delete[] postfix2;
		delete[] infix2;
		delete[] parsInfix2;
		return false;
	}
	if (!stringCompaisor(postfix2, parsInfix2))
	{
		delete[] postfix1;
		delete[] infix1;
		delete[] parsInfix1;
		delete[] postfix2;
		delete[] infix2;
		delete[] parsInfix2;
		return false;
	}
	delete[] postfix1;
	delete[] infix1;
	delete[] parsInfix1;
	delete[] postfix2;
	delete[] infix2;
	delete[] parsInfix2;
	return true;
}

int main()
{
	if (!programTest())
	{
		printf("programm work incorrectly");
		return -1;
	} 

	char string[50] = {};
	char* postfixForm = new char[50]{};

	printf("Enter the expression in infix form: ");
	gets_s(string);
	parser(string, postfixForm);
	printf("%s", postfixForm);

	delete[] postfixForm;
	return 0;
}