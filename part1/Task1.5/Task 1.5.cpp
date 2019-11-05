#include <stdio.h>

int main()
{
	char string[] = "((a + b) * 4 - f * f) + g * (y + h)";
	const int arraySize = 35;
	int identifierOfOpeningAndClosingParentheses = 0;
	bool identifierOfBreakingCycle = true;

	for (int i = 0; i < arraySize; ++i)
	{
		if (string[i] == '(')
		{
			identifierOfOpeningAndClosingParentheses++;
		}
		if (string[i] == ')')
		{
			identifierOfOpeningAndClosingParentheses--;
		}
		if (identifierOfOpeningAndClosingParentheses < 0)
		{
			printf("The nested parenthesis rule fails");
			identifierOfBreakingCycle = false;
			break;
		}
	}
	if (identifierOfBreakingCycle == true)
	{
		if (identifierOfOpeningAndClosingParentheses == 0)
		{
			printf("Parentheses balance is perfomed");
		}
		else
		{
			printf("Parentheses balance is not perfomed");
		}
	}
	return 0;
}