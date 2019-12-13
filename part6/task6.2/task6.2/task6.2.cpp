#include <stdio.h>

#include "balanceCheck.h"

bool programmTest()
{
	char string1[] = "( { } [ ( ) ] ) { }";
	char string2[] = "( { ) } [ ( } ]";
	char string3[] = "[(a + b) * c - b / (v - {t - o})] * [ (g * {n - o}) + (j -b) * (m + n)]";
	char string4[] = "(";
	char string5[] = "[]";
	char string6[] = "[{}([{)])]";

	if (!balanceCheck(string1))
	{
		return false;
	}
	if (balanceCheck(string2))
	{
		return false;
	}
	if (!balanceCheck(string3))
	{
		return false;
	}
	if (balanceCheck(string4))
	{
		return false;
	}
	if (!balanceCheck(string5))
	{
		return false;
	}
	if (balanceCheck(string6))
	{
		return false;
	}
	return true;
}

int main()
{
	if (!programmTest())
	{
		printf("programm work incorrectly");
		return -1;
	}
	char string[50] = {};

	printf("Enter the expression: ");
	fgets(string, 50, stdin);
	if (balanceCheck(string))
	{
		printf("Parenthesis balance is perfomed");
		return 0;
	}
	printf("Parenthesis balance is not perfomed");
	return 0;
}