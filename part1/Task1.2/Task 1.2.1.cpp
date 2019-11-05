#include <stdio.h>
#include <math.h>

int main(void)
{
	int a = 0;
	int b = 0;
	int quotation = 0;
	int sign = 1;
	int corrector = 0;

	printf("input a: ");
	scanf_s("%i", &a);
	printf("input b: ");
	scanf_s("%i", &b);
	if (b == 0 && a != 0)
		printf("Error: b = 0 and a != 0!");
	else
	{
		if (a == 0 && b == 0)
		{
			quotation = 1;
		}
		else if (b != 0)
		{
			if (a * b < 0)
			{
				sign = -1;
			}
			if (a < 0 && b > 0)
			{
				corrector = -1;
			}
			if (a < 0 && b < 0)
			{
				corrector = 1;
			}
			a = abs(a);
			b = abs(b);
			while (a >= b)
			{
				quotation++;
				a -= b;
			}
			quotation *= sign;
		}
		printf("Incomplete quotient is %i", quotation + corrector);
	}
}