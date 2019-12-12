#include <stdio.h>

#include "parser.h"

#include "stack.h"

bool isNumeral(char symbol)
{
	return symbol <= '9' && symbol >= '0';
}

bool isOperator(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int priority(char oper)
{
	if (oper == '(')
	{
		return 1;
	}
	if (oper == '+' || oper == '-')
	{
		return 2;
	}
	if (oper == '*' || oper == '/')
	{
		return 3;
	}
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

void parser(char* string, char* postfixForm)
{
	Stack* operatorStack = create();
	int i = 0;
	int j = 0;

	while (string[i] != '\0')
	{
		if (isNumeral(string[i]))
		{ 
			while (isNumeral(string[i]))
			{
				postfixForm[j] = string[i];
				j++;
				i++;
			}
			postfixForm[j] = ' ';
			j++;
			i--;
		}
		else if (string[i] == '(')
		{
			push(string[i], operatorStack);
		}
		else if (string[i] == ')')
		{
			while (top(operatorStack) != '(')
			{
				if (isEmpty(operatorStack))
				{
					break;
				}
				postfixForm[j] = pop(operatorStack);
				j++;
				postfixForm[j] = ' ';
				j++;
			}
			pop(operatorStack);
		}
		else if (isOperator(string[i]))
		{
			while (!isEmpty(operatorStack) && priority(top(operatorStack)) >= priority(string[i]))
			{
				postfixForm[j] = pop(operatorStack);
				j++;
				postfixForm[j] = ' ';
				j++;
			}
			
			push(string[i], operatorStack);
		}
		i++;
	}
	while (!isEmpty(operatorStack))
	{
		postfixForm[j] = pop(operatorStack);
		j++;
		postfixForm[j] = ' ';
		j++;
	}
	deleteStack(operatorStack);
}