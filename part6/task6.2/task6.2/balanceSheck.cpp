#include "balanceCheck.h"
#include "stack.h"

bool balanceCheck(char* string)
{
	Stack* stack = create();
	int index = 0;

	while (string[index] != '\0')
	{
		if (string[index] == '{' || string[index] == '[' || string[index] == '(')
		{
			push(string[index], stack);
		}
		else if (string[index] == '}')
		{
			if (isEmpty(stack) || pop(stack) != '{')
			{
				deleteStack(stack);
				return false;
			}
		}
		else if (string[index] == ']')
		{
			if (isEmpty(stack) || pop(stack) != '[')
			{
				deleteStack(stack);
				return false;
			}
		}
		else if (string[index] == ')')
		{
			if (isEmpty(stack) || pop(stack) != '(')
			{
				deleteStack(stack);
				return false;
			}
		}
		index++;
	}
	if (!isEmpty(stack))
	{
		deleteStack(stack);
		return false;
	}
	deleteStack(stack);
	return true;
}