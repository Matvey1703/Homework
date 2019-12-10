#include <stdio.h>
#include <string.h>

#include "test.h"
#include "postfixEvaluate.h"

int main()
{
    if (!test())
	{
		printf("programm work incorrectly");
		return -1;
	} 
	char string[30] = {};

	printf("Enter the expression in postfix form: ");
	fgets(string, 30, stdin);
	printf("Result is %i", postfixExpressionEvaluator(string));
	
	return 0;
}