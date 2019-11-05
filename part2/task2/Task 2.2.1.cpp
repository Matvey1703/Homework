#include <stdio.h>

float linearExponentation(float x, int exponent)
{
	float result = 1;

	if (exponent < 0)
	{
		return -1;
	}
	for (int i = 0; i < exponent; ++i)
	{
		result *= x;
	}
	if (exponent == 0)
	{
		result = 1;
	}
	return result;
}

float logarithmicTimeExponentation(float x, int exponent)
{
	float result = 1;
	
	if (exponent < 0)
	{
		return -1;
	}
	if (exponent == 0)
	{
		result = 1;
	}
	if (exponent > 0)
	{
		result = logarithmicTimeExponentation(x * x, exponent / 2);
		if (exponent % 2 != 0)
		{
			result *= x;
		}
	}
	return result;
}

bool testingProgram()
{
	float testX1 = 12;
	int testExponent1 = 4;
	float trueResult1 = 20736;
	float testX2 = 23;
	int testExponent2 = 1;
	float trueResult2 = 23;
	float testX3 = -13;
	int testExponent3 = 3;
	float trueResult3 = -2197;

	if (!(trueResult1 == linearExponentation(testX1, testExponent1) && trueResult1 == logarithmicTimeExponentation(testX1, testExponent1)))
	{
		return false;
	}
	if (!(trueResult2 == linearExponentation(testX2, testExponent2) && trueResult2 == logarithmicTimeExponentation(testX2, testExponent2)))
	{
		return false;
	}
	if (!(trueResult3 == linearExponentation(testX3, testExponent3) && trueResult3 == logarithmicTimeExponentation(testX3, testExponent3)))
	{
		return false;
	}
	if (linearExponentation(2, -5) != -1 && logarithmicTimeExponentation(3, -5) != -1)
	{
		return false;
	}
	return true;
}

int main()
{
	float x = 0;
	int exponent = 0;

	if (testingProgram())
	{
		printf("Put float x and int exponent (exponent >= 0): \n");
		printf("x: ");
		scanf_s("%f", &x);
		printf("exponent: ");
		scanf_s("%i", &exponent);
		printf("Result of exponentation by linear time: %f.\n", linearExponentation(x, exponent));
		printf("Result of exponentation by logarithmic time: %f.", logarithmicTimeExponentation(x, exponent));
	}
	else
	{
		printf("Error in the algorithm. Correct your code and try again.");
	}
	return 0;
}