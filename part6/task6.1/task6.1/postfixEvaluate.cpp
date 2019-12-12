#include "stack.h"

#include "postfixEvaluate.h"

bool isNumeral(char symbol)
{
	return symbol <= '9' && symbol >= '0';
}

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

int postfixExpressionEvaluator(char* string)
{
	int i = 0;
	int result = 0;
	Stack* stack = create();

	while (string[i] != '\0')
	{
		if (isNumeral(string[i]))
		{
			int j = i;
			int sizeOfNumeral = 0;
			while (isNumeral(string[j]))
			{
				sizeOfNumeral++;
				j++;
			}
			int* arrayNumber = new int[sizeOfNumeral];
			j = 0;
			while (j < sizeOfNumeral)
			{
				arrayNumber[j] = (int)(string[i] - '0');
				j++;
				i++;
			}
			int value = toNumber(arrayNumber, sizeOfNumeral);
			push(value, stack);
			delete[] arrayNumber;
			i--;
		}
		else if (string[i] == '+')
		{
			int value = pop(stack);
			value += pop(stack);
			push(value, stack);
		}
		else if (string[i] == '-')
		{
			int number1 = pop(stack);
			int number2 = pop(stack);
			push(number2 - number1, stack);
		}
		else if (string[i] == '*')
		{
			int value = pop(stack);
			value *= pop(stack);
			push(value, stack);
		}
		else if (string[i] == '/')
		{
			int number1 = pop(stack);
			int number2 = pop(stack);
			push(number2 / number1, stack);
		}
		i++;
	}
	result = headValue(stack);
	deleteStack(stack);
	return result;
}